################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Lib/Src/subdir.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

BUILD_ARTIFACT_NAME := Self_Balancing_Robot
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX := 
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME).$(BUILD_ARTIFACT_EXTENSION)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Self_Balancing_Robot.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Self_Balancing_Robot.list \

OBJCOPY_BIN += \
Self_Balancing_Robot.bin \


# All Target
all: main-build

# Main-build Target
main-build: Self_Balancing_Robot.elf secondary-outputs

# Tool invocations
Self_Balancing_Robot.elf: $(OBJS) $(USER_OBJS) C:\Users\84935\Desktop\Self-Balancing-Robot\FW\Self_Balancing_Robot\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -o "Self_Balancing_Robot.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\84935\Desktop\Self-Balancing-Robot\FW\Self_Balancing_Robot\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Self_Balancing_Robot.map" -Wl,--gc-sections -static -L"C:\Users\84935\Desktop\Self-Balancing-Robot\FW\Self_Balancing_Robot\Lib" --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Self_Balancing_Robot.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Self_Balancing_Robot.list"
	@echo 'Finished building: $@'
	@echo ' '

Self_Balancing_Robot.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Self_Balancing_Robot.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents fail-specified-linker-script-missing warn-no-linker-script-specified
.SECONDARY:

-include ../makefile.targets
