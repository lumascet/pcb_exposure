################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
D:\Users\Lukas\OneDrive\ -\ student.tuwien.ac.at\PROJEKTE\_Arduino\libraries\LCDMenuLib2\src\LCDMenuLib2.cpp \
D:\Users\Lukas\OneDrive\ -\ student.tuwien.ac.at\PROJEKTE\_Arduino\libraries\LCDMenuLib2\src\LCDMenuLib2_menu.cpp 

LINK_OBJ += \
.\libraries\LCDMenuLib2\src\LCDMenuLib2.cpp.o \
.\libraries\LCDMenuLib2\src\LCDMenuLib2_menu.cpp.o 

CPP_DEPS += \
.\libraries\LCDMenuLib2\src\LCDMenuLib2.cpp.d \
.\libraries\LCDMenuLib2\src\LCDMenuLib2_menu.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries\LCDMenuLib2\src\LCDMenuLib2.cpp.o: D:\Users\Lukas\OneDrive\ -\ student.tuwien.ac.at\PROJEKTE\_Arduino\libraries\LCDMenuLib2\src\LCDMenuLib2.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"D:\Users\Lukas\cpp-oxygen\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\eightanaloginputs" -I"D:\Users\Lukas\OneDrive - student.tuwien.ac.at\PROJEKTE\_Arduino\libraries\LCDMenuLib2" -I"D:\Users\Lukas\OneDrive - student.tuwien.ac.at\PROJEKTE\_Arduino\libraries\LCDMenuLib2\src" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\libraries\LiquidCrystal\1.0.7" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\LCDMenuLib2\src\LCDMenuLib2_menu.cpp.o: D:\Users\Lukas\OneDrive\ -\ student.tuwien.ac.at\PROJEKTE\_Arduino\libraries\LCDMenuLib2\src\LCDMenuLib2_menu.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"D:\Users\Lukas\cpp-oxygen\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\eightanaloginputs" -I"D:\Users\Lukas\OneDrive - student.tuwien.ac.at\PROJEKTE\_Arduino\libraries\LCDMenuLib2" -I"D:\Users\Lukas\OneDrive - student.tuwien.ac.at\PROJEKTE\_Arduino\libraries\LCDMenuLib2\src" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\libraries\LiquidCrystal\1.0.7" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


