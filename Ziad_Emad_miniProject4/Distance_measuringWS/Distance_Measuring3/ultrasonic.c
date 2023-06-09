/******************************************************************************
 * [Module]	     : ultrasonic.
 * [File Name]   : ultrasonic.c
 * [Description] : Source file for the AVR ultrasonic driver.
 * [Author]      : Ziad Emad
 *******************************************************************************/
#include "ultrasonic.h"
#include "icu.h"
#include "gpio.h"
#include <util/delay.h>

const Icu_ConfigType icu_parameter={F_CPU_8,RISING};
volatile uint8 g_edgeCount=0;
volatile uint16 g_TimeHigh=0;
/*
*****************************************************************************************************
[Function Name]	: static for private Ultrasonic_edgeProcessing
[Description]  	: 1- This is the call back function called by the ICU driver.
				  2- This is used to calculate the high time (pulse time) generated by
                    the ultrasonic sensor.
[Arguments]    	: This Function take nothing.
[Returns]      	: This Function return nothing.
****************************************************************************************************/
static void Ultrasonic_edgeProcessing(){
	g_edgeCount++;
	if (g_edgeCount==1) {

		Icu_clearTimerValue();
		Icu_setEdgeDetectionType(FALLING);
	}
	else if (g_edgeCount==2) {

		g_TimeHigh= Icu_getInputCaptureValue();
		Icu_setEdgeDetectionType(RISING);
		Icu_clearTimerValue();
		g_edgeCount=0;
	}
}
/*
*****************************************************************************************************
[Function Name]	: Ultrasonic_init
[Description]  	: ➢ Initialize the ICU driver as required.
				  ➢ Setup the ICU call back function.
				  ➢ Setup the direction for the trigger pin as output pin through the GPIO driver.
[Arguments]    	: This Function take nothing.
[Returns]      	: This Function return nothing.
****************************************************************************************************/
void Ultrasonic_init(){
	Icu_init(&icu_parameter);
	Icu_setCallBack(Ultrasonic_edgeProcessing);
	GPIO_setupPinDirection(ultrasonic_trig_port_ID, ultrasonic_trig_pin_ID, PIN_OUTPUT);
}
/*
*****************************************************************************************************
[Function Name]	: Ultrasonic_Trigger
[Description]  	: Send the Trigger pulse to the ultrasonic.
[Arguments]    	: This Function take nothing.
[Returns]      	: This Function return nothing.
****************************************************************************************************/
void Ultrasonic_Trigger(){
	GPIO_writePin(ultrasonic_trig_port_ID, ultrasonic_trig_pin_ID, LOGIC_LOW);
	_delay_us(10);
	GPIO_writePin(ultrasonic_trig_port_ID, ultrasonic_trig_pin_ID, LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(ultrasonic_trig_port_ID, ultrasonic_trig_pin_ID, LOGIC_LOW);
}
/*
*****************************************************************************************************
[Function Name]	: Ultrasonic_readDistance
[Description]  	: 1- Send the trigger pulse by using Ultrasonic_Trigger function.
			      2- Start the measurements by the ICU from this moment.
[Arguments]    	: This Function take nothing.
[Returns]      	: This Function return the measured distance in Centimeter.
****************************************************************************************************/
uint16 Ultrasonic_readDistance(){
	uint16 distance_cm=0;

	Ultrasonic_Trigger();

	distance_cm=((float32)(g_TimeHigh)/(57.8));

	return distance_cm;
}

