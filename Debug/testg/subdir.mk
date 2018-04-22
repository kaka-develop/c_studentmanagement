################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../testg/ValidationManagerTest.c 

OBJS += \
./testg/ValidationManagerTest.o 

C_DEPS += \
./testg/ValidationManagerTest.d 


# Each subdirectory must supply rules for building sources it contributes
testg/%.o: ../testg/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


