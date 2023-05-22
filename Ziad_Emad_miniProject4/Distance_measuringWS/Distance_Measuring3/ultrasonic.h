/******************************************************************************
 * [Module]	     : ultrasonic.
 * [File Name]   : ultrasonic.h
 * [Description] : Header file for the AVR ultrasonic driver.
 * [Author]      : Ziad Emad
 *******************************************************************************/
#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ultrasonic_trig_port_ID				PORTB_ID
#define ultrasonic_trig_pin_ID				PIN5_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
*****************************************************************************************************
[Function Name]	: Ultrasonic_init
[Description]  	: ➢ Initialize the ICU driver as required.
				  ➢ Setup the ICU call back function.
				  ➢ Setup the direction for the trigger pin as output pin through the GPIO driver.
[Arguments]    	: This Function take nothing.
[Returns]      	: This Function return nothing.
****************************************************************************************************/
void Ultrasonic_init();
/*
*****************************************************************************************************
[Function Name]	: Ultrasonic_Trigger
[Description]  	: Send the Trigger pulse to the ultrasonic.
[Arguments]    	: This Function take nothing.
[Returns]      	: This Function return nothing.
****************************************************************************************************/
void Ultrasonic_Trigger();
/*
*****************************************************************************************************
[Function Name]	: Ultrasonic_readDistance
[Description]  	: 1- Send the trigger pulse by using Ultrasonic_Trigger function.
			      2- Start the measurements by the ICU from this moment.
[Arguments]    	: This Function take nothing.
[Returns]      	: This Function return the measured distance in Centimeter.
****************************************************************************************************/
uint16 Ultrasonic_readDistance();

#endif /* ULTRASONIC_H_ */
