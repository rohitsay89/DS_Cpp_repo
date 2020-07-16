################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ds_helper.cpp \
../ds_main.cpp \
../ds_unit_test.cpp 

OBJS += \
./ds_helper.o \
./ds_main.o \
./ds_unit_test.o 

CPP_DEPS += \
./ds_helper.d \
./ds_main.d \
./ds_unit_test.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


