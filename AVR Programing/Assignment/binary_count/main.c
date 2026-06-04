/*
 * binary_count.c
 *
 * Created: 29/05/2026 19:46:35
 * Author : admin
 */ 

 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

volatile uint8_t counter = 0;

void updateLEDs(uint8_t value)
{
	PORTB = (PORTB & 0xF0) | (value & 0x0F);
}

int main(void)
{
	DDRB = 0x0F;     // PB0–PB3 as outputs
	DDRD &= ~(1<<PD2); // PD2 as input
	PORTD |= (1<<PD2); // Enable pull-up on PD2

	updateLEDs(counter);

	while (1)
	{
		if (!(PIND & (1<<PD2)))   // Button pressed (active low)
		{
			_delay_ms(50);        // Debounce delay
			while (!(PIND & (1<<PD2))); // Wait until release

			counter++;
			if (counter > 15)
			counter = 0;

			updateLEDs(counter);
		}
	}
}
