#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "LED.h"
#include "LCD.h"
#include "delay.h"
#include "distance.h"
#include "UART.h"
#include <stdbool.h>
#include "GPS_module.h"
#include <string.h>
#include <stdio.h>
#include <math.h>

void SystemInit(){}






	   double dis=0;

	  char z[200];
int main (void) {


	long double lon2=0;
	long double lat2=0;
	long double lat1=0;
	long double lon1=0;
	bool y=false;
	bool x=false;

	LED_INTI();
	LCD_PORT_Initialization();
	UART_inti();
while (1){

	// get first coordinates
         x=GPS_ckeck();

	 if (x==true){
		  GPS_ckeck();
		  lat1=get_lat ();
		  lon1=get_lon ();




 while(1){


	 // get second coordinates
	x=GPS_ckeck();

	 if (x==true){
	 GPS_ckeck();
	       lon2=get_lon ();
	       lat2=get_lat ();
		 dis= distance_m(lat1,  lat2,  lon1,  lon2);
			 lat1=lat2;
			 lon1=lon2;




	 // showing distance on LCD

	 LCD_COMMAND(0x01);
   LCD_COMMAND(0x80);
   delay_milli(1);
	 sprintf(z, "%4.2f", dis);
   LCD_printS(z);


	//LCD

	if( dis>0){
	LCD_COMMAND(0x01);
  LCD_COMMAND(0x80);
  delay_milli(1);
	LCD_written_out();
	sprintf(z, "%4.2f", dis);
   LCD_printS(z);


	// led

 GPIO_PORTF_DATA_R|=0X06;



	}





}
	 else
		 continue;

			}


	 }
	 else
		 continue;
 }
     }
