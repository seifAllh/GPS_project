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

void LCD_PORT_Initialization(void){

	SYSCTL_RCGCGPIO_R|=0x03;
	// while((SYSCTL_PRGPIO_R&0X03)==0)
	GPIO_PORTB_DIR_R|=0xFF;
	GPIO_PORTB_DEN_R|=0xFF;
	GPIO_PORTB_AMSEL_R&= ~0XFF;
  GPIO_PORTB_AFSEL_R&= ~0XFF;
  GPIO_PORTB_PCTL_R&=~0xFFFFFFFF;
	GPIO_PORTA_DIR_R|=0xE0;
	GPIO_PORTA_DEN_R|=0xE0;
  GPIO_PORTA_AMSEL_R&= ~0XE0;
  GPIO_PORTA_AFSEL_R&= ~0XE0;
	GPIO_PORTA_PCTL_R&=~0xFFF00000;
	   delay_micro(37);
	LCD_COM(0x38);
	 	 delay_micro(37);
  LCD_COM(0x06);
	 	 delay_micro(37);
  LCD_COM(0x01);
	 	 delay_micro(37);
  LCD_COM(0x0F);
	 	 delay_micro(37);
	LCD_COM(0x30);
	 	 delay_micro(37);
 }

 // for data viewing


 void LCD_written_out(void)
{
	 int i;
	 char out_word[6]="DONE=>";

	 for (i = 0 ; i<6 ;i++)
	 {
			 LCD_DATA(out_word[i]);
			 delay_milli(20);
	 }
}


void LCD_numeric_out(int dist){
	 int i=0;
	 int arr[10];
	 int x=dist;
	 for(i=0 ; dist!=0 ; i++){
			 arr[i]=x % 10;
			 dist /=10;
			 x=dist;
	 }
	 for(  ; i!=0 ; i-- ){
			 LCD_DATA(arr[i-1] + 48);
			 delay_milli(20);
	 }
}
