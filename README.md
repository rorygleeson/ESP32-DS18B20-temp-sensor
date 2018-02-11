"# ESP32-DS18B20-temp-sensor" 



Uses a DS18B20 1Wire temp sensor, with an ESP32 (Sparkfun thing dev version). Its reads the temperature, and then broadcasts it over bluetooth (BLE), for 500 ms. It then enters deep sleep mode for 60 seconds, wakes up and repeats. 


