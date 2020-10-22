################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/abm.c \
../src/cliente.c \
../src/electrodomestico.c \
../src/reparacion.c 

OBJS += \
./src/abm.o \
./src/cliente.o \
./src/electrodomestico.o \
./src/reparacion.o 

C_DEPS += \
./src/abm.d \
./src/cliente.d \
./src/electrodomestico.d \
./src/reparacion.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


