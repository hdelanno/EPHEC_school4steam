#ifndef MATRICE_LED_H
#define MATRICE_LED_H
#include <Arduino.h>
#include "ArduinoGraphics.h"  // To use ArduinoGraphics APIs, please include BEFORE Arduino_LED_Matrix
#include "Arduino_LED_Matrix.h"

// Matrice LED
// Doc : https://docs.arduino.cc/tutorials/uno-r4-wifi/led-matrix/extern ArduinoLEDMatrix matrix;

extern ArduinoLEDMatrix matrix;

void scrollText(String text);

#endif