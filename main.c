#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "LED.h"
#include "LCD.h"
#include "delay.h"
#include "distance.h"


void SystemInit(){}
double dis=0;
int main (void) {

	LED_INTI();
 LCD_PORT_Initialization();




	// distance

  dis= distance_m(40,28,41,29);

	//LCD
		if( dis>100){
		LCD_COMMAND(0x01);
	  LCD_COMMAND(0x80);
	  delay_milli(500);
		LCD_written_out();
		LCD_numeric_out(dis);

		// led

	 GPIO_PORTF_DATA_R|=0X06;}















	 }
