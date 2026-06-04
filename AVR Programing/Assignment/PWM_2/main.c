/*
 * PWM_2.c
 *
 * Created: 30/05/2026 20:39:35
 * Author : admin
 */ 


#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

uint8_t level = 0;

void update_pwm(void) {
	
	
	if(level==0) OCR0A=64;     // 25%
	
	else if(level==1) OCR0A=128; // 50%
	
	else if(level==2) OCR0A=192; // 75%
	
	else if(level==3) OCR0A=255; // 100%

	
	else OCR0A=0;              // OFF
}

int main(void) {
	
	DDRD |= (1<<PD6);          // OC0A output
	DDRD &= ~(1<<PD2);         // Button input
	PORTD |= (1<<PD2);         // Pull-up
	

	TCCR0A = (1<<WGM00)|(1<<WGM01)|(1<<COM0A1); // Fast PWM, non-inverting
	
	TCCR0B = (1<<CS01)|(1<<CS00);               // Prescaler = 64

	update_pwm();              // Start at 25%

	while(1) {
		if(!(PIND & (1<<PD2))) {   // Button pressed
			
			_delay_ms(50);         // Debounce delay
			
			if(!(PIND & (1<<PD2))) {
				level = (level+1)%5;  // Cycle levels
				
				update_pwm();
				
				while(!(PIND & (1<<PD2))); // Wait release
				
			}
		}
	}
}

