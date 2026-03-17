#include<LPC21XX.H>


void UART0_CONFIG(void){
	
	PINSEL0 |= 0x5;
	U0LCR = 0X83;
	U0DLL = 97;
	U0DLM = 0;
	U0LCR = 0X03;
	 	
}

void UART0_TX(unsigned char txByte){
	
	U0THR = txByte;
	while(((U0LSR>>5)&1)==0); 		

}


unsigned char UART0_RX(void){
	
	while((U0LSR&1)==0);
	return U0RBR;
	
}
