################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../managers/DataManager.c \
../managers/StudentManager.c 

OBJS += \
./managers/DataManager.o \
./managers/StudentManager.o 

C_DEPS += \
./managers/DataManager.d \
./managers/StudentManager.d 


# Each subdirectory must supply rules for building sources it contributes
managers/%.o: ../managers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


