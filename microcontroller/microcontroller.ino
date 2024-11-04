#include "matrice_led.h"
#include "boutons_poussoirs.h"
#include "capteur_couleur.h"
#include <Servo.h>
#include "bluetooth.h"

#define MODULE 1

void setup() {
  Serial.begin(9600);
  while (!Serial);  // Wait for serial monitor to open

  initializeBLE(MODULE);  // Initialize BLE and gives its name
}

void loop() {
  handleBLEConnections();  // Handle BLE connections
}