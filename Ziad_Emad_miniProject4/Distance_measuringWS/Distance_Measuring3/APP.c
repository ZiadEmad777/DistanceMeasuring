/*************************************************************************************************
 * [Module]		  : App.
 * [File Name]    : APP.c
 * [Description]  : source file for Implementing system to measure the distance using ultra-sonic sensor
 * [Author]       : Ziad Emad
 **************************************************************************************************/
#include "ultrasonic.h"
#include "lcd.h"
#include <avr/io.h>
#include <util/delay.h>


int main (){
	uint16 distance=0;

	/*set the global interrupt I-BIT*/
	SREG |=(1<<7);

	/*initialize the Ultra-sonic and LCD devices*/
	Ultrasonic_init();
	LCD_init();

	/*Displaying required texts*/
	LCD_moveCursor(0, 3);
	LCD_displayString("Welcome to");
	_delay_ms(50);
	LCD_moveCursor(1, 3);
	LCD_displayString("ULTRASONIC");
	_delay_ms(50);
	LCD_moveCursor(2, 4);
	LCD_displayString("SENSOR :)");
	_delay_ms(3000);
	LCD_clearScreen();
	LCD_displayString("Distance=    CM");

	while(1){

		/*take the reading from the Ultra-sonic sensor*/
		distance=Ultrasonic_readDistance();

		/*checking the suitable position for the displaying the number
		 * if the number greater than 100 then display starting from 10th col*/
		if (distance>=100)
		{
			/*move cursor to the 10 col*/
			LCD_moveCursor(0, 10);

			/*Display the number*/
			LCD_intgerToString(distance);
		}
		else
		{
			/*in any other case just delete the third number by replacing it by a space */
			LCD_moveCursor(0, 10);

			/*Display the number*/
			LCD_intgerToString(distance);

			/* In case the value is two or one digits print space in the next place */
			LCD_displayCharacter(' ');
		}
	}
}


