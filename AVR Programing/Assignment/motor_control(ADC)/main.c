/*
 * motor_control(ADC).c
 *
 * Created: 04/06/2026 20:26:54
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

void init_PWM() {
	DDRB |= (1<<PB1);
	TCCR1A = (1<<COM1A1)|(1<<WGM11);
	TCCR1B = (1<<WGM13)|(1<<WGM12)|(1<<CS11);
	ICR1 = 19999;
 }

void set_servo(uint16_t adc_val) {
	uint16_t pulse = 1000 + ((adc_val * 1000) / 1023);
	
	OCR1A = pulse;
 }

int main() {
	
	init_ADC();
	init_PWM();
	while(1) {
		uint16_t val = read_ADC();
		
		set_servo(val);
	}
}

