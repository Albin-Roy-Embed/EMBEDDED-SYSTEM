/*
 * DC_motor_speed_control.c
 *
 * Created: 04/06/2026 20:38:25
 * Author : admin
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>



void init_ADC() {
	
	ADMUX = (1<<REFS0);
	
	
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

uint16_t read_ADC() {
	ADMUX = (ADMUX & 0xF0) | 0;
	ADCSRA |= (1<<ADSC);
	while (ADCSRA & (1<<ADSC));
	return ADC;
}

uint8_t scale_to_PWM(uint16_t adc_val) {
	
	return (adc_val >> 2); // 10-bit ? 8-bit
}

void init_PWM() {
	DDRD |= (1<<PD6);
	TCCR0A = (1<<COM0A1)|(1<<WGM01)|(1<<WGM00);
	TCCR0B = (1<<CS01);
}

void set_motor_speed(uint8_t speed) {
	OCR0A = speed;
}


int main() {
	init_ADC();
	init_PWM();
	while(1) {
		uint16_t val = read_ADC();
		uint8_t speed = scale_to_PWM(val);
		set_motor_speed(speed);
	}
}
