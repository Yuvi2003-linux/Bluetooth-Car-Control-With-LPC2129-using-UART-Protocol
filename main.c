
#include<lpc21xx.h>
//#include "lcd_header.h"
#include "lcd.h"
#include "UART_header.h"
#define IN1 (1<<8)
#define IN2 (1<<9)
#define IN3 (1<<10)
#define IN4 (1<<11)
//#define En (1<<16)|(1<<17)
void Prjct_Name_Disp(void);
void M1_clockwise(void);
void M2_anticlockwise(void);
void M_Stop(void);
void M_Left(void);
void M_Right(void);




int main(){
	
	unsigned char rxByte;
	IODIR0 |= IN1|IN2|IN3|IN4;
//	IOSET0|= En;
	LCD_INIT();
	Prjct_Name_Disp();
	UART0_CONFIG();
//while(1){	
	//M1_clockwise();
	//M2_anticlockwise();
//}
//}
	while(1){

	rxByte = UART0_RX();
	//UART0_TX(rxByte);
	
	 

	if(rxByte == 'F')
	       M1_clockwise();
	 	
	else if(rxByte == 'B')
		   M2_anticlockwise();

	else if(rxByte == 'L')
			M_Left();

	else if(rxByte == 'R')
			M_Right();

	else if(rxByte == 'S')
	       M_Stop();

}
}

void Prjct_Name_Disp(void){
	char i = 40;
	LCD_COMMAND(0x80);
	LCD_STRING("Drive The Future:");
	LCD_COMMAND(0xC0);
	LCD_STRING("BLUETOOTH CAR CONTROL USING ARM7");
	while(i){
	LCD_COMMAND(0x1C);
	delay_ms(150);
	i--;
}
LCD_COMMAND(0x01);
}

void M1_clockwise(void){
	
	LCD_STRING("FORWARD");
	delay_ms(500);
	LCD_COMMAND(0x01);
	IOSET0 |= IN1;
	IOCLR0 |= IN2;
	IOSET0 |= IN3;
	IOCLR0 |= IN4;
	
}

void M2_anticlockwise(void){
	
	LCD_STRING("BACKWARD");
	delay_ms(500);
	LCD_COMMAND(0x01);
  IOSET0 |= IN2;
	IOCLR0 |= IN1;
	IOSET0 |= IN4;
	IOCLR0 |= IN3;
	
}

void M_Left(void){

	 LCD_STRING("Left");
	 delay_ms(600);
	 LCD_COMMAND(0x01);
	 IOSET0 |= IN1;
	 IOCLR0 |= IN2;
	 IOSET0 |= IN3|IN4;
	 }

void M_Right(void){

	 LCD_STRING("Right");
	 delay_ms(600);
	 LCD_COMMAND(0x01);
	 IOSET0 |= IN3;
	 IOCLR0 |= IN4;
	 IOSET0 |= IN1|IN2;
	 }


void M_Stop(void)
{
   LCD_STRING("STOP");
	delay_ms(500);
	LCD_COMMAND(0x01);
   IOSET0 |= IN1|IN2|IN3|IN4;

   }

