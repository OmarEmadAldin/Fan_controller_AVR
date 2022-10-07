 /******************************************************************************
  * ADC_REG.h
 *
 *  Created on: 4 Oct 2022
 *      Author: Omar Ben Emaf
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_
#include<avr/io.h>
#include"std_types.h"
#include"gpio.h"
/*******************************************************************************
 *                      	Registers Definitions                              *
 *******************************************************************************/
/*	ADC Multiplexer Selection Register – ADMUX
 * 	Also Channel Bits and Selection Bits for Vref defined
 * */
#define Multiplexer_SelectionReg	ADMUX
#define Ref_selection_bit1			REFS1
#define Ref_selection_bit0			REFS0
#define ADC_Channel0				MUX0
#define ADC_Channel1				MUX1
#define ADC_Channel2				MUX2
#define ADC_Channel3				MUX3
#define ADC_Channel4				MUX4
/*	ADC Control and Status Register A – ADCSRA
 * 	Also Enable Bit, Flag Bit , Start Conversion bit and prescaler bits
 * */
#define Control_StatusRegisterA		ADCSRA
#define ADC_Enable					ADEN
#define ADC_startConversion			ADSC
#define ADC_interruptFlag			ADIF
#define ADC_PrescalerSelectBit0		ADPS0
#define ADC_PrescalerSelectBit1		ADPS1
#define ADC_PrescalerSelectBit2		ADPS2
/*
 * Main ADC parameters definition
 * used in Equations instead of magic numbers
 * */
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum{
	InternalVref_Off ,AVcc , InternalVreff
}ADC_ReferenceVolatge;

typedef enum{
	Prescaler0 = 0, Prescaler2 = 2,Prescaler4 = 4,Prescaler8 = 8\
	,Prescaler16 = 16,Prescaler32 = 32,Prescaler64 = 64,Prescaler128 = 128
}ADC_Prescaler;

typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for initialize the ADC driver.
 * we pass to it structure by reference , to make the\
 * prescaler and reference voltage configurable
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);
/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 Ch_num);

#endif
