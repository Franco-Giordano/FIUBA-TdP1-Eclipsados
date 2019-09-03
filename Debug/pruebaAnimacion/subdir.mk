################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../pruebaAnimacion/cody.cpp \
../pruebaAnimacion/game.cpp \
../pruebaAnimacion/main.cpp \
../pruebaAnimacion/objeto.cpp 

OBJS += \
./pruebaAnimacion/cody.o \
./pruebaAnimacion/game.o \
./pruebaAnimacion/main.o \
./pruebaAnimacion/objeto.o 

CPP_DEPS += \
./pruebaAnimacion/cody.d \
./pruebaAnimacion/game.d \
./pruebaAnimacion/main.d \
./pruebaAnimacion/objeto.d 


# Each subdirectory must supply rules for building sources it contributes
pruebaAnimacion/%.o: ../pruebaAnimacion/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


