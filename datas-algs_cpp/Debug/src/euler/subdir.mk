################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/euler/p2.cpp \
../src/euler/p3.cpp \
../src/euler/p4.cpp \
../src/euler/p5.cpp 

OBJS += \
./src/euler/p2.o \
./src/euler/p3.o \
./src/euler/p4.o \
./src/euler/p5.o 

CPP_DEPS += \
./src/euler/p2.d \
./src/euler/p3.d \
./src/euler/p4.d \
./src/euler/p5.d 


# Each subdirectory must supply rules for building sources it contributes
src/euler/%.o: ../src/euler/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


