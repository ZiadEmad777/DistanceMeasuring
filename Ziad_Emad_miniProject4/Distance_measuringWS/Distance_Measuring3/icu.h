/******************************************************************************
 * [Module]      : ICU
 * [File Name]   : icu.h
 * [Description] : Header file for the AVR ICU driver
 * [Author]      : Ziad Emad
 *******************************************************************************/
#ifndef ICU_H_
#define ICU_H_

#include "std_types.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}Icu_Clock;


typedef enum
{
	FALLING,RISING
}Icu_EdgeType;


typedef struct
{
	Icu_Clock clock;
	Icu_EdgeType edge;
}Icu_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
*****************************************************************************************************
[Function Name]	: Icu_init
[Description]  	: Function to initialize the ICU driver
         	     	 1. Set the required clock.
             	 	 2. Set the required edge detection.
 	 	 	     	 3. Enable the Input Capture Interrupt.
 			     	 4. Initialize Timer1 Registers
[Arguments]    	: This Function take pointer to structure.
[Returns]      	: This Function return nothing.
****************************************************************************************************/
void Icu_init(const Icu_ConfigType * Config_Ptr);

/*
*****************************************************************************************************
[Function Name]	: Icu_setCallBack
[Description]  	: Function to set the Call Back function address.
[Arguments]    	: This Function take pointer to function
[Returns]      	: This Function return nothing.
****************************************************************************************************/
void Icu_setCallBack(void(*a_ptr)(void));

/*
*****************************************************************************************************
[Function Name]	: Icu_setEdgeDetectionType
[Description]  	: Function to set the required edge detection.
[Arguments]    	: This Function take member of structure as argument
[Returns]      	: This Function return nothing.
****************************************************************************************************/
void Icu_setEdgeDetectionType(const Icu_EdgeType edgeType);

/*
*****************************************************************************************************
[Function Name]	: Icu_getInputCaptureValue
[Description]  	: Function to get the Timer1 Value when the input is captured
                  The value stored at Input Capture Register ICR1
[Arguments]    	: This Function take nothing
[Returns]      	: This Function return nothing.
****************************************************************************************************/
uint16 Icu_getInputCaptureValue(void);

/*
*****************************************************************************************************
[Function Name]	: Icu_clearTimerValue
[Description]  	: Function to clear the Timer1 Value to start count from ZERO
[Arguments]    	: This Function take nothing
[Returns]      	: This Function return nothing.
****************************************************************************************************/
void Icu_clearTimerValue(void);

/*
*****************************************************************************************************
[Function Name]	: Icu_DeInit
[Description]  	: Function to disable the Timer1 to stop the ICU Driver
[Arguments]    	: This Function take nothing
[Returns]      	: This Function return nothing.
****************************************************************************************************/
void Icu_DeInit(void);

#endif /* ICU_H_ */
