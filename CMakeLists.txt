# CMakeList.txt: CMakeProject3 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
cmake_minimum_required (VERSION 3.8)

set(CMAKE_C_COMPILER "C:/Keil_v5/ARM/ARMCC/bin/armcc.exe")
set(CMAKE_CXX_COMPILER "C:/Keil_v5/ARM/ARMCC/bin/armcc.exe")



project(STM32Timer)

# 将源代码添加到此项目的可执行文件。
add_executable (STM32Timer "./Source/main.c" "./Source/key.c" "./Source/key.h" "./Source/led.c" "./Source/led.h" "./Source/exti.h" "./Source/exti.c"
                "./Source/stm32f10x_it.c" "./Source/stm32f10x_it.c" "./Source/TIM.c" "./Source/TIM.h"
				"./Source/usart1.h" "./Source/usart1.c")

include_directories ("C:/Keil_v5/ARM/ARMCC/include" 
                     "C:/Users/redal/AppData/Local/Arm/Packs/ARM/CMSIS/5.5.1/CMSIS/Core/Include" 
					 "C:/Users/redal/AppData/Local/Arm/Packs/Keil/STM32F1xx_DFP/2.3.0/Device/Include/" 
					 "C:/Users/redal/AppData/Local/Arm/Packs/Keil/STM32F1xx_DFP/2.3.0/Device/StdPeriph_Driver/inc")

add_compile_definitions(STM32F10X_HD)


