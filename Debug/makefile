################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Utilities/trace/adv_trace/subdir.mk
-include Utilities/tim_serv/subdir.mk
-include Utilities/sequencer/subdir.mk
-include Utilities/misc/subdir.mk
-include Utilities/lpm/tiny_lpm/subdir.mk
-include System/Startup/subdir.mk
-include System/Modules/baes/subdir.mk
-include System/Modules/RTDebug/subdir.mk
-include System/Modules/Nvm/subdir.mk
-include System/Modules/MemoryManager/subdir.mk
-include System/Modules/Flash/subdir.mk
-include System/Modules/subdir.mk
-include System/Interfaces/subdir.mk
-include System/Config/Debug_GPIO/subdir.mk
-include STM32_WPAN/Target/subdir.mk
-include STM32_WPAN/App/subdir.mk
-include Middlewares/ST/STM32_WPAN/link_layer/ll_sys/src/subdir.mk
-include Middlewares/ST/STM32_WPAN/ble/svc/Src/subdir.mk
-include Drivers/STM32WBAxx_HAL_Driver/Src/subdir.mk
-include Drivers/BSP/STM32WBAxx_Nucleo/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := BLE_p2pServer_ota
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
BLE_p2pServer_ota.elf \

MAP_FILES += \
BLE_p2pServer_ota.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
BLE_p2pServer_ota.list \

OBJCOPY_BIN += \
BLE_p2pServer_ota.bin \


# All Target
all: main-build

# Main-build Target
main-build: BLE_p2pServer_ota.elf secondary-outputs

# Tool invocations
BLE_p2pServer_ota.elf BLE_p2pServer_ota.map: $(OBJS) $(USER_OBJS) C:\Users\marciasm\OneDrive\ -\ STMicroelectronics\Documents\GitHub\BLE_p2pServer_ota\STM32WBA52CGUX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "BLE_p2pServer_ota.elf" @"objects.list" $(USER_OBJS) -Wl,--start-group $(LIBS) -Wl,--end-group -mcpu=cortex-m33 -T"C:\Users\marciasm\OneDrive - STMicroelectronics\Documents\GitHub\BLE_p2pServer_ota\STM32WBA52CGUX_FLASH.ld" --specs=nosys.specs -Wl,-Map="BLE_p2pServer_ota.map" -Wl,--gc-sections -static -L../Middlewares/ST/STM32_WPAN/link_layer/ll_cmd_lib/lib -L../Middlewares/ST/STM32_WPAN/ble/stack/lib --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

BLE_p2pServer_ota.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "BLE_p2pServer_ota.list"
	@echo 'Finished building: $@'
	@echo ' '

BLE_p2pServer_ota.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "BLE_p2pServer_ota.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) BLE_p2pServer_ota.bin BLE_p2pServer_ota.elf BLE_p2pServer_ota.list BLE_p2pServer_ota.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
