################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../pruebaMVC/Controlador.cpp \
../pruebaMVC/Juego.cpp \
../pruebaMVC/Personaje.cpp \
../pruebaMVC/Vista.cpp \
../pruebaMVC/main.cpp 

OBJS += \
./pruebaMVC/Controlador.o \
./pruebaMVC/Juego.o \
./pruebaMVC/Personaje.o \
./pruebaMVC/Vista.o \
./pruebaMVC/main.o 

CPP_DEPS += \
./pruebaMVC/Controlador.d \
./pruebaMVC/Juego.d \
./pruebaMVC/Personaje.d \
./pruebaMVC/Vista.d \
./pruebaMVC/main.d 


# Each subdirectory must supply rules for building sources it contributes
pruebaMVC/%.o: ../pruebaMVC/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


