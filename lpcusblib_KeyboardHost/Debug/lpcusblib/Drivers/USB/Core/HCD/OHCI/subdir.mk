################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lpcusblib/Drivers/USB/Core/HCD/OHCI/OHCI.c 

OBJS += \
./lpcusblib/Drivers/USB/Core/HCD/OHCI/OHCI.o 

C_DEPS += \
./lpcusblib/Drivers/USB/Core/HCD/OHCI/OHCI.d 


# Each subdirectory must supply rules for building sources it contributes
lpcusblib/Drivers/USB/Core/HCD/OHCI/%.o: ../lpcusblib/Drivers/USB/Core/HCD/OHCI/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -D__LPC175X_6X__ -DUSB_HOST_ONLY -DCORE_M3 -I"/home/sran/amarpreetsran/Amarpreetsran/lpcusblib_KeyboardHost/lpcusblib/Drivers/USB" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


