"# ESP32-DS18B20-temp-sensor" 



Uses a DS18B20 1Wire temp sensor, with an ESP32 (Sparkfun ESP32 Thing development board). Its reads the temperature, and then advertises it over bluetooth (BLE), for 500 ms. It then enters deep sleep mode for 60 seconds, wakes up and repeats. 

A separate device should be scanning for bluetooth advirtisements.


Built using Arduino IDE, the following libraries need to be installed in the IDE.

1)  https://github.com/adafruit/MAX31850_DallasTemp
2)  https://github.com/adafruit/MAX31850_OneWire

Also, a pullup resistor (4.7K) is required beween signal and vcc. In this code GPIO14 is used for signal. 


