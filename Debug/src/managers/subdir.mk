################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/managers/DataManager.c \
../src/managers/MenuManager.c \
../src/managers/StudentManager.c \
../src/managers/ValidationManager.c 

OBJS += \
./src/managers/DataManager.o \
./src/managers/MenuManager.o \
./src/managers/StudentManager.o \
./src/managers/ValidationManager.o 

C_DEPS += \
./src/managers/DataManager.d \
./src/managers/MenuManager.d \
./src/managers/StudentManager.d \
./src/managers/ValidationManager.d 


# Each subdirectory must supply rules for building sources it contributes
src/managers/%.o: ../src/managers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


