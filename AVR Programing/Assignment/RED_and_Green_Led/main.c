/*
 * RED_and_Green_Led.c
 *
 * Created: 06/05/2026 15:31:34
 * Author : admin
 */ 

#include <avr/io.h>


int main(void)
{
    DDRD|=(1<<PD5)|(1<<PD6);
	DDRB&=~(1<<PB3);
	
	int toggle;
	
	int
	
	
    while (1) 
    { 
	if(!(PINB&(1<<PB3))) 
	{
		
	}
	}