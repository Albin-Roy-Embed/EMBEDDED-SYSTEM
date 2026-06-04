/*
 * Interrupt_1.c
 *
 * Created: 30/05/2026 11:31:11
 * Author : admin
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t emergency_flag = 0;

void delay_sec(unsigned int sec) {    // delay 1 sec
	unsigned int i;
	for(i=0;i<sec;i++) {
		TCNT1=0;
		while(TCNT1<15625);
	}
}

ISR(INT0_vect) {            // interrupt 
	
	emergency_flag = 1;
}

int main(void) {
	
	DDRB |= (1<<PB0)|(1<<PB1)|(1<<PB2);
	TCCR1B |= (1<<CS12)|(1<<CS10);
	EIMSK |= (1<<INT0);
	EICRA |= (1<<ISC01)|(1<<ISC00);
	sei();

	while(1) {
		
		PORTB = (1<<PB0);
		delay_sec(10);
		if(emergency_flag) {
			PORTB = (1<<PB0);
			delay_sec(5);
			emergency_flag = 0;
			continue;
		}

		PORTB = (1<<PB1);
		delay_sec(3);
		if(emergency_flag) {
			PORTB = (1<<PB0);
			delay_sec(5);
			emergency_flag = 0;
			continue;
		}

		PORTB = (1<<PB2);
		delay_sec(10);
		if(emergency_flag) {
			PORTB = (1<<PB0);
			delay_sec(5);
			emergency_flag = 0;
			continue;
		}
	}
}
