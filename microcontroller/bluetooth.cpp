#include "bluetooth.h"

// Arduino BLE
// Doc : https://docs.arduino.cc/libraries/arduinoble/

// Constants for BLE service and characteristic UUIDs
const char * deviceServiceUuid = "19b10000-e8f2-537e-4f6c-d104768a1214";
const char * deviceServiceRequestCharacteristicUuid = "19b10001-e8f2-537e-4f6c-d104768a1215";
const char * deviceServiceResponseCharacteristicUuid = "19b10001-e8f2-537e-4f6c-d104768a1216";

// BLE service and characteristics
BLEService servoService(deviceServiceUuid);

// Using char arrays instead of String for better memory management
char receivedValue[101];  
char prevValue[101] = "Nothing";  

BLECharacteristic servoRequestCharacteristic(deviceServiceRequestCharacteristicUuid, BLEWrite, 100);
BLECharacteristic servoResponseCharacteristic(deviceServiceResponseCharacteristicUuid, BLENotify, 100);

void initializeBLE(unsigned int module_number) {
  if (!BLE.begin()) {
    Serial.println("- Starting Bluetooth® Low Energy module failed!");
    while (1);  // Halt the program if BLE initialization fails
  }

  // Convert module_number to a string
  String deviceName = "Module " + String(module_number);
  
  BLE.setDeviceName(deviceName.c_str());
  BLE.setLocalName(deviceName.c_str());

  BLE.setAdvertisedService(servoService);
  servoService.addCharacteristic(servoRequestCharacteristic);
  servoService.addCharacteristic(servoResponseCharacteristic);
  BLE.addService(servoService);

  servoResponseCharacteristic.writeValue("0");  // Initial response value
  BLE.advertise();  // Start advertising BLE service
  Serial.println("BLE Peripheral Ready - Waiting for connections...");
}

void handleBLEConnections() {
  BLEDevice central = BLE.central();

  if (central) {
    Serial.println("* Central device connected!");
    Serial.print("* Device MAC address: ");
    Serial.println(central.address());

    while (central.connected()) {
      if (servoRequestCharacteristic.written()) {
        int length = servoRequestCharacteristic.readValue(receivedValue, sizeof(receivedValue) - 1);
        receivedValue[length] = '\0';  // Null-terminate the string

        if (strcmp(receivedValue, prevValue) != 0) {
          strcpy(prevValue, receivedValue);  // Update previous value
          servoResponseCharacteristic.writeValue(receivedValue);  // Send back the same value as response

          Serial.print("Received: ");
          Serial.println(receivedValue);
        }
      }
    }

    Serial.println("* Central device disconnected!");
  }
}
