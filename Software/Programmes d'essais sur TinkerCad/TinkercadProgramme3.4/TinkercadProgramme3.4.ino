// https://html-color-codes.info/ Roue de couleurs hex
#include <Adafruit_NeoPixel.h> // Importation de la bibliothèque pour gérer les NeoPixels
#define BrocheNeoPixel 2 // Broche sur laquelle les NeoPixels sont connectées
#define NombrePixel 4 // Nombre de NeoPixel

Adafruit_NeoPixel MesLed = Adafruit_NeoPixel(NombrePixel, BrocheNeoPixel, NEO_GRB + NEO_KHZ800); // Affectation des paramètres définies ci-dessus.

void setup() {
  MesLed.begin(); // Initialiser la bibliothèque
}

void allume_led(String couleur, int broche) { // Procédure prenant la couleur et le numéro d'une led en paramètre
  if (couleur == "rouge") { // Si la couleur demandé est rouge
    MesLed.setPixelColor(broche, MesLed.Color(150, 0, 0)); // régler la led spécifié sur rouge
  }
  if (couleur == "vert") { // Si la couleur demandé est vert
    MesLed.setPixelColor(broche, MesLed.Color(0, 150, 0)); // régler la led spécifié sur vert
  }
  if (couleur == "bleu") { // Si la couleur demandé est bleu
    MesLed.setPixelColor(broche, MesLed.Color(0, 0, 150)); // régler la led spécifié sur bleu
  }
  if (couleur == "jaune") { // Si la couleur demandé est jaune
    MesLed.setPixelColor(3, 0xFFFF00); // régler la led spécifié sur jaune
  }
}

void loop() {
  allume_led("rouge", 0); // Appeler la procédure "allume_led" en lui demandant de régler la led n°0 en rouge
  allume_led("vert", 1); // Led n°1 vert
  allume_led("bleu", 2); // Led n°2 bleu
  allume_led("jaune", 3); // Led n°3 jaune
  MesLed.show(); // Allumer toutes les led d'un coup

}
