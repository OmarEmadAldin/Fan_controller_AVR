################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../Fan_controlUnit.c \
../LM35_Sensor.c \
../Motor.c \
../PWM.c \
../gpio.c \
../lcd.c 

OBJS += \
./ADC.o \
./Fan_controlUnit.o \
./LM35_Sensor.o \
./Motor.o \
./PWM.o \
./gpio.o \
./lcd.o 

C_DEPS += \
./ADC.d \
./Fan_controlUnit.d \
./LM35_Sensor.d \
./Motor.d \
./PWM.d \
./gpio.d \
./lcd.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


