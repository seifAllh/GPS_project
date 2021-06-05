#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "LED.h"
#include "LCD.h"
#include "delay.h"



void SystemInit(){}

int main (void) {

	LED_INTI();
 LCD_PORT_Initialization();




	//while(1) {



	//LCD

	LCD_COMMAND(0x01);
  LCD_COMMAND(0x80);
  delay_milli(500);
	LCD_VIEWED_DATA('d');
	delay_milli(1);
	LCD_VIEWED_DATA('0');
	delay_milli(1);
	LCD_VIEWED_DATA('n');
	delay_milli(1);
	LCD_VIEWED_DATA('e');
	delay_milli(1);
	LCD_VIEWED_DATA('=');
	delay_milli(1);
LCD_VIEWED_DATA('>');
	delay_milli(1);
	LCD_VIEWED_DATA('9');
	delay_milli(1);
		LCD_VIEWED_DATA('9');
	delay_milli(1);
	LCD_VIEWED_DATA('9');
	delay_milli(500);
	// led
		GPIO_PORTF_DATA_R|=0X06;














	 }
