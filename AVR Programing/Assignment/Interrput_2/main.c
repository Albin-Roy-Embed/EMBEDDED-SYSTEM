/*
 * Interrput_2.c
 *
 * Created: 30/05/2026 20:10:16
 * Author : admin
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER1_COMPA_vect) {
	PORTB ^= (1<<PB1);   // Toggle PB1 every 2s
}

ISR(TIMER2_COMPA_vect) {
	PORTB ^= (1<<PB2);   // Toggle PB2 every 0.5s
}

int main(void) {
	DDRB |= (1<<PB1)|(1<<PB2);

	// Timer1: 2s
	TCCR1B |= (1<<WGM12)|(1<<CS12)|(1<<CS10);
	OCR1A = 31249;
	TIMSK1 |= (1<<OCIE1A);

	// Timer2: 0.5s
	TCCR2A |= (1<<WGM21);
	TCCR2B |= (1<<CS22)|(1<<CS21)|(1<<CS20);
	OCR2A = 124;
	TIMSK2 |= (1<<OCIE2A);

	sei();

	while(1);
}
