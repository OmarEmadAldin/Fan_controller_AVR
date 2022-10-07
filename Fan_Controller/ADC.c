 /******************************************************************************
  * ADC.c
  *
  *  Created on: 4 Oct 2022
 *******************************************************************************/
#include "ADC.h"
#include<avr/io.h>
#include"common_macros.h"
#include"std_types.h"

void ADC_init(const ADC_ConfigType * Config_Ptr){
	switch(Config_Ptr->prescaler){
		case(Prescaler0):
			CLEAR_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit0);
			CLEAR_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit1);
			CLEAR_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit2);
			break;
		case(Prescaler2):
			SET_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit0);
			CLEAR_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit1);
			CLEAR_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit2);
			break;
		case(Prescaler4):
			CLEAR_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit0);
			SET_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit1);
			CLEAR_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit2);
			break;
		case(Prescaler8):
			SET_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit0);
			SET_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit1);
			CLEAR_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit2);
			break;
		case(Prescaler16):
			CLEAR_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit0);
			CLEAR_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit1);
			SET_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit2);
			break;
		case(Prescaler32):
			SET_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit0);
			CLEAR_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit1);
			SET_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit2);
			break;
		case(Prescaler64):
			CLEAR_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit0);
			SET_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit1);
			SET_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit2);
			break;
		case(Prescaler128):
			SET_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit0);
			SET_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit1);
			SET_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit2);
			break;
		default:
			CLEAR_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit0);
			CLEAR_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit1);
			CLEAR_BIT(Control_StatusRegisterA,ADC_PrescalerSelectBit2);
			break;
	}
	switch(Config_Ptr->ref_volt){
		case(InternalVref_Off):
			CLEAR_BIT(Multiplexer_SelectionReg,Ref_selection_bit1);
			CLEAR_BIT(Multiplexer_SelectionReg,Ref_selection_bit0);
			break;
		case(AVcc):
			CLEAR_BIT(Multiplexer_SelectionReg,Ref_selection_bit1);
			SET_BIT(Multiplexer_SelectionReg,Ref_selection_bit0);
			break;
		case(InternalVreff):
			SET_BIT(Multiplexer_SelectionReg,Ref_selection_bit1);
			SET_BIT(Multiplexer_SelectionReg,Ref_selection_bit0);
			break;
	}
	SET_BIT(Control_StatusRegisterA,ADC_Enable);
	SET_BIT(Control_StatusRegisterA,ADC_interruptFlag);

}

uint16 ADC_readChannel(uint8 Ch_num){
	Ch_num &= 0x07;
	Multiplexer_SelectionReg &= 0xE0;
	Multiplexer_SelectionReg |= Ch_num;
	SET_BIT(Control_StatusRegisterA,ADC_startConversion);
	while(BIT_IS_CLEAR(ADCSRA,ADIF)){};
	SET_BIT(Control_StatusRegisterA,ADC_interruptFlag);
	return ADC;
}
