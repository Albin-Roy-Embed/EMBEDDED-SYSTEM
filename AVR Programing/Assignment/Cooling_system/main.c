/*
 * Cooling_system.c
 *
 * Created: 04/06/2026 20:23:10
 * Author : admin
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

#define BUTTON_PIN PD2
#define MOTOR_PIN PD6

uint8_t system_state = 0;

void init_ADC() {
	ADMUX = (1<<REFS0);
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

uint16_t read_temperature() {
	ADMUX = (ADMUX & 0xF0) | 0;
	ADCSRA |= (1<<ADSC);
	while (ADCSRA & (1<<ADSC));
	return ADC;
}

uint8_t calculate_speed(uint16_t temp) {
	if(temp < 200) return 64;
	else if(temp < 400) return 128;
	else return 255;
}

void control_motor(uint8_t speed) {
	OCR0A = speed;
}

int main() {
	DDRD |= (1<<MOTOR_PIN);
	DDRD &= ~(1<<BUTTON_PIN);
	PORTD |= (1<<BUTTON_PIN);

	TCCR0A = (1<<COM0A1)|(1<<WGM00);
	TCCR0B = (1<<CS01);

	init_ADC();

	while(1) {
		if(!(PIND & (1<<BUTTON_PIN))) {
			_delay_ms(200);
			system_state ^= 1;
		}

		if(system_state) {
			uint16_t temp = read_temperature();
			uint8_t speed = calculate_speed(temp);
			control_motor(speed);
			} else {
			control_motor(0);
		}
	}
}
