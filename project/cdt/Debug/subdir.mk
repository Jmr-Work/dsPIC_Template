################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Documents/MyWorkspaces/Ref/dsPIC/dsPIC33Template.X/main.c 

OBJS += \
./main.o 

C_DEPS += \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
main.o: D:/Documents/MyWorkspaces/Ref/dsPIC/dsPIC33Template.X/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	mingw32-gcc -D__dsPIC33EP512GM710__ -D__COMPILE_WITH_ECLIPSE__ -I"D:\Software\Microchip\xc16\v1.33\support\generic\h" -I"D:\Software\Microchip\xc16\v1.33\support\dsPIC33E\h" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


