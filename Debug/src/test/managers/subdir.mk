################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/test/managers/DataManager.c \
../src/test/managers/StudentManagerTest.c \
../src/test/managers/ValidationManagerTest.c 

OBJS += \
./src/test/managers/DataManager.o \
./src/test/managers/StudentManagerTest.o \
./src/test/managers/ValidationManagerTest.o 

C_DEPS += \
./src/test/managers/DataManager.d \
./src/test/managers/StudentManagerTest.d \
./src/test/managers/ValidationManagerTest.d 


# Each subdirectory must supply rules for building sources it contributes
src/test/managers/%.o: ../src/test/managers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


