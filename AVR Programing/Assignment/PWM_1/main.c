/*
 * PWM_1.c
 *
 * Created: 30/05/2026 20:35:24
 * Author : admin
 */ 

#include <avr/io.h>

uint8_t level = 0;

void update_pwm(void) {
	if(level==0) OCR0A=64;    // 25%
	else if(level==1) OCR0A=128; // 50%
	else if(level==2) OCR0A=192; // 75%
	else if(level==3) OCR0A=255; // 100%
	else OCR0A=0;             // OFF
}

int main(void) {
	DDRD |= (1<<PD6);        // OC0A output
	DDRD &= ~(1<<PD2);       // Button input
	PORTD |= (1<<PD2);       // Pull-up

	TCCR0A = (1<<WGM00)|(1<<WGM01)|(1<<COM0A1);
	TCCR0B = (1<<CS01)|(1<<CS00);

	update_pwm();

	while(1) {
		if(!(PIND & (1<<PD2))) {
			level=(level+1)%5;
			update_pwm();
			while(!(PIND & (1<<PD2)));
		}
	}
}

