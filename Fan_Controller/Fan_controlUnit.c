/******************************************************************************
 * Fan_controlUnit.c
 *
 *  Created on: 6 Oct 2022
 *      Author: Omar Ben Emad
 *******************************************************************************/
#include "ADC.h"
#include "Motor.h"
#include "PWM.h"
#include "LM35_Sensor.h"
#include "LCD.h"

int main(){
	const ADC_ConfigType configPtr = { InternalVreff , Prescaler8 };
	uint8 volatile Temp=0;
	LCD_init();
	DcMotor_Init();
	ADC_init(&configPtr);
	LCD_displayStringRowColumn(0, 3,"Fan is ");
	LCD_displayStringRowColumn(1,3,"Temp=     C ");
	while(1){
		Temp=LM35_getTemperature();
		if(30>Temp){
			LCD_moveCursor(0,10);
			LCD_displayString("OFF");
			LCD_moveCursor(1,10);
			LCD_intgerToString(Temp);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(STOP,0);

		}
		else if (Temp>=30 && Temp<60){

			LCD_moveCursor(0,10);
			LCD_displayString("ON ");
			LCD_moveCursor(1,10);
			LCD_intgerToString(Temp);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,25);
		}
		else if(Temp>=60 && Temp<90){
			LCD_moveCursor(0,10);
			LCD_displayString("ON ");
			LCD_moveCursor(1,10);
			LCD_intgerToString(Temp);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,50);
		}
		else if(Temp>=90 && Temp<120){
			LCD_moveCursor(0,10);
			LCD_displayString("ON ");
			LCD_moveCursor(1,10);
			LCD_intgerToString(Temp);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,75);
		}
		else if(Temp>=120){
			LCD_moveCursor(0,10);
			LCD_displayString("ON ");
			LCD_moveCursor(1,10);
			LCD_intgerToString(Temp);
			DcMotor_Rotate(CW,100);
		}
	}
}


