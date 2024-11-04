#include "matrice_led.h"

// Matrice LED
// Doc : https://docs.arduino.cc/tutorials/uno-r4-wifi/led-matrix/

void scrollText(String text) {
  /** scrollText - Affiche sur la matrice LED du texte défilant
    *
    * @param text  Le texte à afficher
    *
    * @return void
    */

  matrix.beginDraw();

  matrix.stroke(0xFFFFFFFF);
  matrix.textScrollSpeed(50);

  matrix.textFont(Font_5x7);
  matrix.beginText(10, 1, 0xFFFFFF);
  matrix.println(text);
  matrix.endText(SCROLL_LEFT);

  matrix.endDraw();
}
