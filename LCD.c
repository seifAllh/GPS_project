# include "tm4c123gh6pm.h"
#include "delay.h"

// data func.

void LCD_VIEWED_DATA(unsigned char data)
{
	GPIO_PORTA_DATA_R=0x20;
	GPIO_PORTB_DATA_R=data;
	GPIO_PORTA_DATA_R|=0x80;
	delay_micro(0);
	GPIO_PORTA_DATA_R=0x00;
}


// command func.

void LCD_COMMAND(unsigned char command)
{
	GPIO_PORTA_DATA_R=0x00;
	GPIO_PORTB_DATA_R=com;
	GPIO_PORTA_DATA_R=0x80;
	delay_micro(0);
		GPIO_PORTA_DATA_R=0x00;
	if(command <4) delay_milli(2); else delay_micro(37); }










//initialitation




