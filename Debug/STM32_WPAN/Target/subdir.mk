################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_WPAN/Target/bleplat.c \
../STM32_WPAN/Target/bpka.c \
../STM32_WPAN/Target/host_stack_if.c \
../STM32_WPAN/Target/linklayer_plat.c \
../STM32_WPAN/Target/ll_sys_if.c \
../STM32_WPAN/Target/power_table.c 

OBJS += \
./STM32_WPAN/Target/bleplat.o \
./STM32_WPAN/Target/bpka.o \
./STM32_WPAN/Target/host_stack_if.o \
./STM32_WPAN/Target/linklayer_plat.o \
./STM32_WPAN/Target/ll_sys_if.o \
./STM32_WPAN/Target/power_table.o 

C_DEPS += \
./STM32_WPAN/Target/bleplat.d \
./STM32_WPAN/Target/bpka.d \
./STM32_WPAN/Target/host_stack_if.d \
./STM32_WPAN/Target/linklayer_plat.d \
./STM32_WPAN/Target/ll_sys_if.d \
./STM32_WPAN/Target/power_table.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_WPAN/Target/%.o STM32_WPAN/Target/%.su STM32_WPAN/Target/%.cyclo: ../STM32_WPAN/Target/%.c STM32_WPAN/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_ASSERT -DUSE_FULL_LL_DRIVER -DPHY_2_10_a -DPHY_40nm_2_30_a_A1 -DNVM_ADAPT -DBLE -DUSE_HAL_DRIVER -DSTM32WBA52xx -c -I../Core/Inc -I../System/Interfaces -I../System/Modules -I../System/Modules/baes -I../System/Modules/Flash -I../System/Modules/MemoryManager -I../System/Modules/Nvm -I../System/Modules/RTDebug -I../System/Config/Debug_GPIO -I../System/Config/LowPower -I../System/Config/Flash -I../STM32_WPAN/App -I../STM32_WPAN/Target -I../Drivers/STM32WBAxx_HAL_Driver/Inc -I../Drivers/BSP/STM32WBAxx_Nucleo -I../Drivers/STM32WBAxx_HAL_Driver/Inc/Legacy -I../Utilities/trace/adv_trace -I../Utilities/misc -I../Utilities/sequencer -I../Utilities/tim_serv -I../Utilities/lpm/tiny_lpm -I../Middlewares/ST/STM32_WPAN -I../Middlewares/ST/STM32_WPAN/link_layer/ll_cmd_lib/config/ble_basic -I../Middlewares/ST/STM32_WPAN/ble/svc/Src -I../Drivers/CMSIS/Device/ST/STM32WBAxx/Include -I../Middlewares/ST/STM32_WPAN/link_layer/ll_cmd_lib/inc -I../Middlewares/ST/STM32_WPAN/link_layer/ll_cmd_lib/inc/_40nm_reg_files -I../Middlewares/ST/STM32_WPAN/link_layer/ll_sys/inc -I../Middlewares/ST/STM32_WPAN/ble -I../Middlewares/ST/STM32_WPAN/ble/stack/include -I../Middlewares/ST/STM32_WPAN/ble/stack/include/auto -I../Middlewares/ST/STM32_WPAN/ble/svc/Inc -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-STM32_WPAN-2f-Target

clean-STM32_WPAN-2f-Target:
	-$(RM) ./STM32_WPAN/Target/bleplat.cyclo ./STM32_WPAN/Target/bleplat.d ./STM32_WPAN/Target/bleplat.o ./STM32_WPAN/Target/bleplat.su ./STM32_WPAN/Target/bpka.cyclo ./STM32_WPAN/Target/bpka.d ./STM32_WPAN/Target/bpka.o ./STM32_WPAN/Target/bpka.su ./STM32_WPAN/Target/host_stack_if.cyclo ./STM32_WPAN/Target/host_stack_if.d ./STM32_WPAN/Target/host_stack_if.o ./STM32_WPAN/Target/host_stack_if.su ./STM32_WPAN/Target/linklayer_plat.cyclo ./STM32_WPAN/Target/linklayer_plat.d ./STM32_WPAN/Target/linklayer_plat.o ./STM32_WPAN/Target/linklayer_plat.su ./STM32_WPAN/Target/ll_sys_if.cyclo ./STM32_WPAN/Target/ll_sys_if.d ./STM32_WPAN/Target/ll_sys_if.o ./STM32_WPAN/Target/ll_sys_if.su ./STM32_WPAN/Target/power_table.cyclo ./STM32_WPAN/Target/power_table.d ./STM32_WPAN/Target/power_table.o ./STM32_WPAN/Target/power_table.su

.PHONY: clean-STM32_WPAN-2f-Target

