// https://html-color-codes.info/ Roue de couleurs hex
#include <Adafruit_NeoPixel.h> // Importation de la bibliothèque pour gérer les NeoPixels
#define BrocheNeoPixel 2 // Broche sur laquelle les NeoPixels sont connectées
#define NombrePixel 4 // Nombre de NeoPixel

Adafruit_NeoPixel MesLed = Adafruit_NeoPixel(NombrePixel, BrocheNeoPixel, NEO_GRB + NEO_KHZ800); // Affectation des paramètres définies ci-dessus.

void setup() {
  MesLed.begin(); // Initialiser la bibliothèque

}

void loop() {
  MesLed.setPixelColor(0, MesLed.Color(150, 0, 0)); // La première led sera rouge
  MesLed.setPixelColor(1, MesLed.Color(0, 150, 0)); // La seconde led sera vert
  MesLed.setPixelColor(2, MesLed.Color(0, 0, 150)); // La troisième led sera bleu
  MesLed.setPixelColor(3, 0xFFFF00); // La quatrième led sera jaune
  MesLed.show(); // Allumer toutes les led d'un coup

}
