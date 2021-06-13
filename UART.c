#include "tm4c123gh6pm.h"

void UART_inti(void){
SYSCTL_RCGCUART_R |=0x0020;
SYSCTL_RCGCGPIO_R |=0x0010;
UART5_CTL_R&=~0X0001;
UART5_IBRD_R=104;
UART5_FBRD_R=11;
UART5_LCRH_R=0x0070;
UART5_CTL_R=0x0301;
GPIO_PORTE_AFSEL_R|=0x0030;
GPIO_PORTE_PCTL_R=(GPIO_PORTE_PCTL_R&0xFF00FFFF)+0x00110000;
GPIO_PORTE_DEN_R |=0x0030;
GPIO_PORTE_AMSEL_R&=~0x0030;
}


unsigned char UART_input(unsigned char data){
	
while((UART5_FR_R&0X10)!=0){}
	 data=(UART5_DR_R&0xFF);
	return data;

}

void UART_write(char c){
    while((UART5_FR_R & UART_FR_TXFF) != 0){};
    UART0_DR_R = c;
}
