################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_WPAN/App/app_ble.c \
../STM32_WPAN/App/ota.c \
../STM32_WPAN/App/ota_app.c \
../STM32_WPAN/App/p2p_server.c \
../STM32_WPAN/App/p2p_server_app.c 

OBJS += \
./STM32_WPAN/App/app_ble.o \
./STM32_WPAN/App/ota.o \
./STM32_WPAN/App/ota_app.o \
./STM32_WPAN/App/p2p_server.o \
./STM32_WPAN/App/p2p_server_app.o 

C_DEPS += \
./STM32_WPAN/App/app_ble.d \
./STM32_WPAN/App/ota.d \
./STM32_WPAN/App/ota_app.d \
./STM32_WPAN/App/p2p_server.d \
./STM32_WPAN/App/p2p_server_app.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_WPAN/App/%.o STM32_WPAN/App/%.su STM32_WPAN/App/%.cyclo: ../STM32_WPAN/App/%.c STM32_WPAN/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_ASSERT -DUSE_FULL_LL_DRIVER -DPHY_2_10_a -DPHY_40nm_2_30_a_A1 -DNVM_ADAPT -DBLE -DUSE_HAL_DRIVER -DSTM32WBA52xx -c -I../Core/Inc -I../System/Interfaces -I../System/Modules -I../System/Modules/baes -I../System/Modules/Flash -I../System/Modules/MemoryManager -I../System/Modules/Nvm -I../System/Modules/RTDebug -I../System/Config/Debug_GPIO -I../System/Config/LowPower -I../System/Config/Flash -I../STM32_WPAN/App -I../STM32_WPAN/Target -I../Drivers/STM32WBAxx_HAL_Driver/Inc -I../Drivers/BSP/STM32WBAxx_Nucleo -I../Drivers/STM32WBAxx_HAL_Driver/Inc/Legacy -I../Utilities/trace/adv_trace -I../Utilities/misc -I../Utilities/sequencer -I../Utilities/tim_serv -I../Utilities/lpm/tiny_lpm -I../Middlewares/ST/STM32_WPAN -I../Middlewares/ST/STM32_WPAN/link_layer/ll_cmd_lib/config/ble_basic -I../Middlewares/ST/STM32_WPAN/ble/svc/Src -I../Drivers/CMSIS/Device/ST/STM32WBAxx/Include -I../Middlewares/ST/STM32_WPAN/link_layer/ll_cmd_lib/inc -I../Middlewares/ST/STM32_WPAN/link_layer/ll_cmd_lib/inc/_40nm_reg_files -I../Middlewares/ST/STM32_WPAN/link_layer/ll_sys/inc -I../Middlewares/ST/STM32_WPAN/ble -I../Middlewares/ST/STM32_WPAN/ble/stack/include -I../Middlewares/ST/STM32_WPAN/ble/stack/include/auto -I../Middlewares/ST/STM32_WPAN/ble/svc/Inc -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-STM32_WPAN-2f-App

clean-STM32_WPAN-2f-App:
	-$(RM) ./STM32_WPAN/App/app_ble.cyclo ./STM32_WPAN/App/app_ble.d ./STM32_WPAN/App/app_ble.o ./STM32_WPAN/App/app_ble.su ./STM32_WPAN/App/ota.cyclo ./STM32_WPAN/App/ota.d ./STM32_WPAN/App/ota.o ./STM32_WPAN/App/ota.su ./STM32_WPAN/App/ota_app.cyclo ./STM32_WPAN/App/ota_app.d ./STM32_WPAN/App/ota_app.o ./STM32_WPAN/App/ota_app.su ./STM32_WPAN/App/p2p_server.cyclo ./STM32_WPAN/App/p2p_server.d ./STM32_WPAN/App/p2p_server.o ./STM32_WPAN/App/p2p_server.su ./STM32_WPAN/App/p2p_server_app.cyclo ./STM32_WPAN/App/p2p_server_app.d ./STM32_WPAN/App/p2p_server_app.o ./STM32_WPAN/App/p2p_server_app.su

.PHONY: clean-STM32_WPAN-2f-App

