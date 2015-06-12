################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../PngUtilities/lodepng.cpp \
../PngUtilities/pngUtil.cpp 

OBJS += \
./PngUtilities/lodepng.o \
./PngUtilities/pngUtil.o 

CPP_DEPS += \
./PngUtilities/lodepng.d \
./PngUtilities/pngUtil.d 


# Each subdirectory must supply rules for building sources it contributes
PngUtilities/%.o: ../PngUtilities/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/player-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


