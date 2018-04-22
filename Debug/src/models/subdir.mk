################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/models/Student.c \
../src/models/StudentArray.c 

OBJS += \
./src/models/Student.o \
./src/models/StudentArray.o 

C_DEPS += \
./src/models/Student.d \
./src/models/StudentArray.d 


# Each subdirectory must supply rules for building sources it contributes
src/models/%.o: ../src/models/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


