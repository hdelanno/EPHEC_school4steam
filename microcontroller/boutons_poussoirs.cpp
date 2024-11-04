#include "boutons_poussoirs.h"

// ADKeyboard Module (boutons poussoirs)
// Doc : https://wiki.dfrobot.com/ADKeyboard_Module__SKU__DFR0075_

int adc_key_val[5] = { 610, 660, 720, 800, 900 };  //tableau des valeurs de tension délimitant les différents boutons
const int NUM_KEYS = 5;

int get_key(unsigned int input) {
  /** get_key - Donne le numéro du bouton pressé en fonction de la tension lue sur la pin correspondante.
   *
   * @param input   Valeur de la tension lue sur le pin (analogRead(PIN))
   *
   * @return int    1 à 5 pour les 5 boutons du module. Et -1 si rien n'est pressé.
   */
  int k;
  for (k = 0; k < NUM_KEYS; k++) {
    if (input < adc_key_val[k]) {
      return ++k;
    }
  }
  if (k >= NUM_KEYS) k = -1;  // No valid key pressed
  return k;
}
