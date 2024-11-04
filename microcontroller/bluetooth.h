#ifndef BLUETOOTH_H
#define BLUETOOTH_H
#include <Arduino.h>
#include <ArduinoBLE.h>

// Arduino BLE
// Doc : https://docs.arduino.cc/libraries/arduinoble/

void initializeBLE(unsigned int module_number);
void handleBLEConnections();


#endif