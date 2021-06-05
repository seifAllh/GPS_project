# include "tm4c123gh6pm.h"


void LED_INTI (void) {

	SYSCTL_RCGCGPIO_R|=0X20;
	while((SYSCTL_RCGCGPIO_R&0X20)==0){}
	  GPIO_PORTF_LOCK_R=0X4c4f434B;
    GPIO_PORTF_CR_R |= 0x0E;
		GPIO_PORTF_DIR_R |= 0x0E;
		 GPIO_PORTF_DEN_R |= 0x0E;
    GPIO_PORTF_AMSEL_R &=~ 0x0E;
    GPIO_PORTF_AFSEL_R &=~0x0E;
      GPIO_PORTF_PCTL_R &= ~0x0000FFF0;
	//	GPIO_PORTF_PUR_R|=0X02;



}



		void led_out(unsigned char data ){


        	GPIO_PORTF_DATA_R|=data;}

	
