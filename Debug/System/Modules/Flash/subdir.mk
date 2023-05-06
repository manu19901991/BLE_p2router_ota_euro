################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../System/Modules/Flash/flash_driver.c \
../System/Modules/Flash/flash_manager.c \
../System/Modules/Flash/rf_timing_synchro.c \
../System/Modules/Flash/simple_nvm_arbiter.c 

OBJS += \
./System/Modules/Flash/flash_driver.o \
./System/Modules/Flash/flash_manager.o \
./System/Modules/Flash/rf_timing_synchro.o \
./System/Modules/Flash/simple_nvm_arbiter.o 

C_DEPS += \
./System/Modules/Flash/flash_driver.d \
./System/Modules/Flash/flash_manager.d \
./System/Modules/Flash/rf_timing_synchro.d \
./System/Modules/Flash/simple_nvm_arbiter.d 


# Each subdirectory must supply rules for building sources it contributes
System/Modules/Flash/%.o System/Modules/Flash/%.su System/Modules/Flash/%.cyclo: ../System/Modules/Flash/%.c System/Modules/Flash/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_ASSERT -DUSE_FULL_LL_DRIVER -DPHY_2_10_a -DPHY_40nm_2_30_a_A1 -DNVM_ADAPT -DBLE -DUSE_HAL_DRIVER -DSTM32WBA52xx -c -I../Core/Inc -I../System/Interfaces -I../System/Modules -I../System/Modules/baes -I../System/Modules/Flash -I../System/Modules/MemoryManager -I../System/Modules/Nvm -I../System/Modules/RTDebug -I../System/Config/Debug_GPIO -I../System/Config/LowPower -I../System/Config/Flash -I../STM32_WPAN/App -I../STM32_WPAN/Target -I../Drivers/STM32WBAxx_HAL_Driver/Inc -I../Drivers/BSP/STM32WBAxx_Nucleo -I../Drivers/STM32WBAxx_HAL_Driver/Inc/Legacy -I../Utilities/trace/adv_trace -I../Utilities/misc -I../Utilities/sequencer -I../Utilities/tim_serv -I../Utilities/lpm/tiny_lpm -I../Middlewares/ST/STM32_WPAN -I../Middlewares/ST/STM32_WPAN/link_layer/ll_cmd_lib/config/ble_basic -I../Middlewares/ST/STM32_WPAN/ble/svc/Src -I../Drivers/CMSIS/Device/ST/STM32WBAxx/Include -I../Middlewares/ST/STM32_WPAN/link_layer/ll_cmd_lib/inc -I../Middlewares/ST/STM32_WPAN/link_layer/ll_cmd_lib/inc/_40nm_reg_files -I../Middlewares/ST/STM32_WPAN/link_layer/ll_sys/inc -I../Middlewares/ST/STM32_WPAN/ble -I../Middlewares/ST/STM32_WPAN/ble/stack/include -I../Middlewares/ST/STM32_WPAN/ble/stack/include/auto -I../Middlewares/ST/STM32_WPAN/ble/svc/Inc -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-System-2f-Modules-2f-Flash

clean-System-2f-Modules-2f-Flash:
	-$(RM) ./System/Modules/Flash/flash_driver.cyclo ./System/Modules/Flash/flash_driver.d ./System/Modules/Flash/flash_driver.o ./System/Modules/Flash/flash_driver.su ./System/Modules/Flash/flash_manager.cyclo ./System/Modules/Flash/flash_manager.d ./System/Modules/Flash/flash_manager.o ./System/Modules/Flash/flash_manager.su ./System/Modules/Flash/rf_timing_synchro.cyclo ./System/Modules/Flash/rf_timing_synchro.d ./System/Modules/Flash/rf_timing_synchro.o ./System/Modules/Flash/rf_timing_synchro.su ./System/Modules/Flash/simple_nvm_arbiter.cyclo ./System/Modules/Flash/simple_nvm_arbiter.d ./System/Modules/Flash/simple_nvm_arbiter.o ./System/Modules/Flash/simple_nvm_arbiter.su

.PHONY: clean-System-2f-Modules-2f-Flash

