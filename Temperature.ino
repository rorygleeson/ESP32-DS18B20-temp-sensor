/**
 * Temperature.ino
 *
 *  Created on: 14.11.2017
 *
 */

#include <Arduino.h>
#include "SimpleBLE.h"
#include <OneWire.h>
#include <DallasTemperature.h>


#define USE_SERIAL Serial
#include <esp_system.h>

// Data wire is plugged into port 4 on the Arduino or ESP32
#define ONE_WIRE_BUS 14
#define TEMPERATURE_PRECISION 10



SimpleBLE ble;
String beaconMsg = "ESP00";
float  finalTemp;


// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
 
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
 
// array to hold device address
DeviceAddress myTherm = { 0x28,  0xFF,  0xA3,  0xC9,  0x83,  0x16,  0x3,  0xBD };















void setup() {
    
    USE_SERIAL.begin(115200);
     // Start up the library
    sensors.begin();
 
    // locate devices on the bus
  
 
 
   
    // set the resolution to 9 bit per device
    sensors.setResolution(myTherm, TEMPERATURE_PRECISION);
 
   
}

void loop() {



      sensors.requestTemperatures();
    

      finalTemp = returnTemperature(myTherm);

      beaconMsg = "SkyGridT"+String(finalTemp);
     
      ble.begin(beaconMsg); 
      delay(500);
      /* USE_SERIAL.print("Now set up GPIO33 for external interrupt...");
      esp_sleep_enable_ext0_wakeup(GPIO_NUM_33,1); //1 = High, 0 = Low
      USE_SERIAL.print("All done, sleep now ...\n");  
      Serial.println("Going to sleep now until external interrupt occurs"); */
     /* esp_deep_sleep_start();  */
      esp_sleep_enable_timer_wakeup(60000000);
      Serial.println("bye bye .. sleep now");
      esp_deep_sleep_start();
      
}














void printTemperature(String label, DeviceAddress deviceAddress){
  float tempC = sensors.getTempC(deviceAddress);
  Serial.print(label);
  if (tempC == -127.00) {
    Serial.print("Error getting temperature");
  } else {
    Serial.print(" Temp C: ");
    Serial.print(tempC);
    Serial.print(" Temp F: ");
    Serial.println(DallasTemperature::toFahrenheit(tempC));
  }  
}


float returnTemperature(DeviceAddress deviceAddress){
  
  float tempC = sensors.getTempC(deviceAddress);
  return tempC;
 
}

