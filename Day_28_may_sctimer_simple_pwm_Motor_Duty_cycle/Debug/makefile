################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include utilities/subdir.mk
-include startup/subdir.mk
-include source/subdir.mk
-include drivers/subdir.mk
-include device/subdir.mk
-include component/uart/subdir.mk
-include component/serial_manager/subdir.mk
-include component/lists/subdir.mk
-include board/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Day_28_may_sctimer_simple_pwm_Motor_Duty_cycle.axf

# Tool invocations
Day_28_may_sctimer_simple_pwm_Motor_Duty_cycle.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/home/himanshu/Documents/Day_28_may_sctimer_simple_pwm_Motor_Duty_cycle/libs" -Xlinker -Map="Day_28_may_sctimer_simple_pwm_Motor_Duty_cycle.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -T Day_28_may_sctimer_simple_pwm_Motor_Duty_cycle_Debug.ld -o "Day_28_may_sctimer_simple_pwm_Motor_Duty_cycle.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) Day_28_may_sctimer_simple_pwm_Motor_Duty_cycle.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "Day_28_may_sctimer_simple_pwm_Motor_Duty_cycle.axf"; # arm-none-eabi-objcopy -v -O binary "Day_28_may_sctimer_simple_pwm_Motor_Duty_cycle.axf" "Day_28_may_sctimer_simple_pwm_Motor_Duty_cycle.bin" ; # checksum -p LPC54114J256 -d "Day_28_may_sctimer_simple_pwm_Motor_Duty_cycle.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
