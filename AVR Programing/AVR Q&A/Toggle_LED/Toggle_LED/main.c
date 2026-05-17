/*
 * Toggle_LED.c
 *
 * Created: 05/05/2026 21:02:00
 * Author : admin
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>



int main(void)
{
	DDRD|=(1<<PD5);
	
	
	while (1)
	{
		PORTD|=(1<<PD5);
		_delay_ms(1000);
		PORTD&=~(1<<PD5);
		_delay_ms(1000);
	}
	
	return 0;
}


