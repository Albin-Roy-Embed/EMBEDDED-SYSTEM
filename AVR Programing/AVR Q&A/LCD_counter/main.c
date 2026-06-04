/*
 * LCD_counter.c
 *
 * Created: 04/06/2026 20:32:22
 * Author : admin
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

// LCD assumed on PORTC
#define RS PC0
#define EN PC1
#define LCD PORTC
#define BUTTON PD2

uint32_t counter = 0;

void lcd_cmd(unsigned char cmd) {
	LCD = (cmd & 0xF0);
	LCD |= (1<<EN);
	_delay_us(1);
	LCD &= ~(1<<EN);
	LCD = ((cmd<<4)&0xF0);
	LCD |= (1<<EN);
	_delay_us(1);
	LCD &= ~(1<<EN);
	_delay_ms(2);
}

void lcd_data(unsigned char data) {
	LCD = (data & 0xF0)|(1<<RS);
	LCD |= (1<<EN);
	_delay_us(1);
	LCD &= ~(1<<EN);
	LCD = ((data<<4)&0xF0)|(1<<RS);
	LCD |= (1<<EN);
	_delay_us(1);
	LCD &= ~(1<<EN);
	_delay_ms(2);
}

void lcd_init() {
	DDRC = 0xFF;
	_delay_ms(20);
	lcd_cmd(0x02);
	lcd_cmd(0x28);
	lcd_cmd(0x0C);
	lcd_cmd(0x06);
	lcd_cmd(0x01);
}

void lcd_print_num(uint32_t val) {
	char buf[11];
	sprintf(buf,"%09lu",val);
	lcd_cmd(0x80);
	for(int i=0;buf[i];i++) lcd_data(buf[i]);
}

uint8_t button_check() {
	if(!(PIND & (1<<BUTTON))) {
		_delay_ms(20);
		uint16_t t=0;
		while(!(PIND & (1<<BUTTON))) {
			_delay_ms(10);
			t+=10;
			if(t>=2000) return 2;
		}
		return 1;
	}
	return 0;
}

int main() {
	DDRD &= ~(1<<BUTTON);
	PORTD |= (1<<BUTTON);
	lcd_init();
	lcd_print_num(counter);

	while(1) {
		uint8_t res = button_check();
		if(res==1) { counter++; lcd_print_num(counter); }
		else if(res==2) { counter=0; lcd_print_num(counter); }
	}
}
