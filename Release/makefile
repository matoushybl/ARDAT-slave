################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ARDAT_slave.lss \

FLASH_IMAGE += \
ARDAT_slave.hex \

EEPROM_IMAGE += \
ARDAT_slave.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: ARDAT_slave.elf secondary-outputs

# Tool invocations
ARDAT_slave.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ARDAT_slave.map -mmcu=atmega88 -o "ARDAT_slave.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ARDAT_slave.lss: ARDAT_slave.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ARDAT_slave.elf  >"ARDAT_slave.lss"
	@echo 'Finished building: $@'
	@echo ' '

ARDAT_slave.hex: ARDAT_slave.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex ARDAT_slave.elf  "ARDAT_slave.hex"
	@echo 'Finished building: $@'
	@echo ' '

ARDAT_slave.eep: ARDAT_slave.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex ARDAT_slave.elf  "ARDAT_slave.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ARDAT_slave.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega88 ARDAT_slave.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) ARDAT_slave.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
