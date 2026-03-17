#include<LPC21XX.H>
#include "delay_header.h"
#define LCD_D 0xf<<14	  //d4 to d7 ---->14 to 17
#define RS 1<<12
#define E 1<<13

void LCD_COMMAND(unsigned char );
void LCD_DATA(unsigned char );
void LCD_INIT(void);
void LCD_STRING(unsigned char *);


void LCD_COMMAND(unsigned char cmd){

	IOCLR0 |= LCD_D;
	IOSET0 |= (0xf0&cmd)<<10;
	IOCLR0 |= RS;
	IOSET0 |= E;
	delay_ms(2);
	IOCLR0 |= E;

	 IOCLR0 |= LCD_D;
	IOSET0 |= (0x0f&cmd)<<14;
	IOCLR0 |= RS;
	IOSET0 |= E;
	delay_ms(2);
	IOCLR0 |= E;
	}
	
void LCD_DATA(unsigned char D){

	IOCLR0 |= LCD_D;
	IOSET0 |= (0xf0&D)<<10;
	IOSET0 |= RS;
	IOSET0 |= E;
	delay_ms(2);
	IOCLR0 |= E;
	
	IOCLR0 |= LCD_D;
	IOSET0 |= (0x0f&D)<<14;
	IOSET0 |= RS;
	IOSET0 |= E;
	delay_ms(2);
	IOCLR0 |= E;
	}
	

void LCD_INIT(void){
	
  IODIR0 |= LCD_D|RS|E;
	LCD_COMMAND(0x01);
	LCD_COMMAND(0x02);
	LCD_COMMAND(0x0C);
	LCD_COMMAND(0x28);
	
	}

void LCD_STRING(unsigned char *s){
	
	//char p = 0;
	while(*s){
		
		LCD_DATA(*s++);
// 		p++;
// 		if(p==32)
// 			LCD_COMMAND(0x01);
		
	}
}