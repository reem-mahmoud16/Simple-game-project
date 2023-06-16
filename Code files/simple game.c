/*
 * simple_game.c
 *
 * Created: 9/11/2022 11:24:10 PM
 *  Author: HP.SXH08
 */ 


#include <avr/io.h>
#include "avr/interrupt.h"
#include "timer.h"
#include "keypad_driver.h"
#include "LCD.h"


volatile unsigned short counter;

int main(void)
{
	LCD_vInit();
	keypad_vInit();
	timer_CTC_init_interrupt();
	LCD_vSend_string("3+?=8");
	char flag=0,val=NOTPRESSED;
	
	while(val==NOTPRESSED && flag==0)
	{
		val=keypad_u8check_press();
		if(counter>=500)
		{
			LCD_clearscreen();
			LCD_vSend_string("time over!");
			flag=1;
		}
	}		
         
		 
	if(flag==0)
	{
			 if(val=='5')
			 {
				 LCD_clearscreen();
				 LCD_movecursor(2,3);
				 LCD_vSend_string("well done!");
			 }
			 else if(val !='5' && val !=NOTPRESSED)
			 {
				 LCD_clearscreen();
				 LCD_movecursor(2,2);
				 LCD_vSend_string("wrong answer!");
			 }
	}	 
  
}

ISR(TIMER0_COMP_vect)
{
	counter++;
}