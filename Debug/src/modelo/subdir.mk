################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/modelo/AdministradorDeNiveles.cpp \
../src/modelo/Nivel.cpp \
../src/modelo/Posicion.cpp 

OBJS += \
./src/modelo/AdministradorDeNiveles.o \
./src/modelo/Nivel.o \
./src/modelo/Posicion.o 

CPP_DEPS += \
./src/modelo/AdministradorDeNiveles.d \
./src/modelo/Nivel.d \
./src/modelo/Posicion.d 


# Each subdirectory must supply rules for building sources it contributes
src/modelo/%.o: ../src/modelo/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


