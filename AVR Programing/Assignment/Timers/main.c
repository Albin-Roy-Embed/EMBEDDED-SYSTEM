/*
 * Timers.c
 *
 * Created: 29/05/2026 19:50:12
 * Author : admin
 */ 

#include <avr/io.h>

void delay_sec(unsigned int sec) {
	unsigned int i;
	for(i=0;i<sec;i++) {
		TCNT1=0;
		while(TCNT1<15625);
	}
}

int main(void) {
	DDRB |= (1<<PB0)|(1<<PB1)|(1<<PB2);
	TCCR1B |= (1<<CS12)|(1<<CS10);
	while(1) {
		PORTB = (1<<PB0);
		delay_sec(10);
		PORTB = (1<<PB1);
		delay_sec(3);
		PORTB = (1<<PB2);
		delay_sec(10);
	}
}

