################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
INO_SRCS += \
..\LCDML_condetion.ino \
..\LCDML_control.ino \
..\LCDML_display_dynFunction.ino \
..\LCDML_display_menu.ino \
..\LCDML_display_menuFunction.ino \
..\Platinenbelichtung.ino 

CPP_SRCS += \
..\sloeber.ino.cpp 

LINK_OBJ += \
.\sloeber.ino.cpp.o 

INO_DEPS += \
.\LCDML_condetion.ino.d \
.\LCDML_control.ino.d \
.\LCDML_display_dynFunction.ino.d \
.\LCDML_display_menu.ino.d \
.\LCDML_display_menuFunction.ino.d \
.\Platinenbelichtung.ino.d 

CPP_DEPS += \
.\sloeber.ino.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
LCDML_condetion.o: ..\LCDML_condetion.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"D:\Users\Lukas\cpp-oxygen\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\eightanaloginputs" -I"D:\Users\Lukas\OneDrive - student.tuwien.ac.at\PROJEKTE\_Arduino\libraries\LCDMenuLib2" -I"D:\Users\Lukas\OneDrive - student.tuwien.ac.at\PROJEKTE\_Arduino\libraries\LCDMenuLib2\src" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\libraries\LiquidCrystal\1.0.7" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

LCDML_control.o: ..\LCDML_control.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"D:\Users\Lukas\cpp-oxygen\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\eightanaloginputs" -I"D:\Users\Lukas\OneDrive - student.tuwien.ac.at\PROJEKTE\_Arduino\libraries\LCDMenuLib2" -I"D:\Users\Lukas\OneDrive - student.tuwien.ac.at\PROJEKTE\_Arduino\libraries\LCDMenuLib2\src" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\libraries\LiquidCrystal\1.0.7" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

LCDML_display_dynFunction.o: ..\LCDML_display_dynFunction.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"D:\Users\Lukas\cpp-oxygen\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\eightanaloginputs" -I"D:\Users\Lukas\OneDrive - student.tuwien.ac.at\PROJEKTE\_Arduino\libraries\LCDMenuLib2" -I"D:\Users\Lukas\OneDrive - student.tuwien.ac.at\PROJEKTE\_Arduino\libraries\LCDMenuLib2\src" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\libraries\LiquidCrystal\1.0.7" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

LCDML_display_menu.o: ..\LCDML_display_menu.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"D:\Users\Lukas\cpp-oxygen\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\eightanaloginputs" -I"D:\Users\Lukas\OneDrive - student.tuwien.ac.at\PROJEKTE\_Arduino\libraries\LCDMenuLib2" -I"D:\Users\Lukas\OneDrive - student.tuwien.ac.at\PROJEKTE\_Arduino\libraries\LCDMenuLib2\src" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\libraries\LiquidCrystal\1.0.7" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

LCDML_display_menuFunction.o: ..\LCDML_display_menuFunction.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"D:\Users\Lukas\cpp-oxygen\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\eightanaloginputs" -I"D:\Users\Lukas\OneDrive - student.tuwien.ac.at\PROJEKTE\_Arduino\libraries\LCDMenuLib2" -I"D:\Users\Lukas\OneDrive - student.tuwien.ac.at\PROJEKTE\_Arduino\libraries\LCDMenuLib2\src" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\libraries\LiquidCrystal\1.0.7" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Platinenbelichtung.o: ..\Platinenbelichtung.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"D:\Users\Lukas\cpp-oxygen\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\eightanaloginputs" -I"D:\Users\Lukas\OneDrive - student.tuwien.ac.at\PROJEKTE\_Arduino\libraries\LCDMenuLib2" -I"D:\Users\Lukas\OneDrive - student.tuwien.ac.at\PROJEKTE\_Arduino\libraries\LCDMenuLib2\src" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\libraries\LiquidCrystal\1.0.7" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

sloeber.ino.cpp.o: ..\sloeber.ino.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"D:\Users\Lukas\cpp-oxygen\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\eightanaloginputs" -I"D:\Users\Lukas\OneDrive - student.tuwien.ac.at\PROJEKTE\_Arduino\libraries\LCDMenuLib2" -I"D:\Users\Lukas\OneDrive - student.tuwien.ac.at\PROJEKTE\_Arduino\libraries\LCDMenuLib2\src" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\libraries\LiquidCrystal\1.0.7" -I"D:\Users\Lukas\cpp-oxygen\eclipse\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


