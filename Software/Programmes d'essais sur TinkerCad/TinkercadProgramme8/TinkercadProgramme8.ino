// Ce programme allume une led au hasard pendant 750ms puis attends 1sec avant d'en allumer une autre. Les couleurs sont prédéfinie

// https://html-color-codes.info/ Roue de couleurs hex
#include <Adafruit_NeoPixel.h> // Importation de la bibliothèque pour gérer les NeoPixels
#define NeoPixelPin 2 // Broche sur laquelle les NeoPixels sont connectées
#define PixelCount 4 // Nombre de NeoPixel
Adafruit_NeoPixel MyLed = Adafruit_NeoPixel(PixelCount, NeoPixelPin, NEO_GRB + NEO_KHZ800); // Affectation des paramètres définies ci-dessus.

void setup() {
  Serial.begin(9600); // Initialisation d'une liaison série pour du déboggage
  MyLed.begin(); // Initialiser la bibliothèque
}

void OnLed(int ledNumber) { // Procédure prenant le numéro d'une led en paramètre et allumant la led correspondante
  switch (ledNumber) {
    case 0:
      MyLed.setPixelColor(ledNumber, MyLed.Color(150, 0, 0)); // Si la led n°0 est demandé, elle est configuré en rouge
      break;
    case 1:
      MyLed.setPixelColor(ledNumber, MyLed.Color(0, 150, 0)); // Si la led n°1 est demandé, elle est configuré en vert
      break;
    case 2:
      MyLed.setPixelColor(ledNumber, MyLed.Color(0, 0, 150)); // Si la led n°2 est demandé, elle est configuré en bleu
      break;
    case 3:
      MyLed.setPixelColor(3, 0xFFFF00); // Si la led n°3 est demandé, elle est configuré en jaune
      break;
  }
  MyLed.show(); // // Allumer la led configuré
  delay(750); // Pendant 750ms
  MyLed.clear(); // Configurer toutes les led en "noir" (Equivalent de: MyLed.setPixelColor(broche, MyLed.Color(0, 0, 0));)
  MyLed.show(); // Eteindre toutes les led
}

void loop() {
  int randNumber = random(0, 4); // Choisir un nombre aléatoire entre 0 inclus et 3 inclus.
  Serial.println(randNumber);
  OnLed(randNumber); // Appeler la procédure "allume_led" en lui demandant de régler la led n°0 en rouge
  delay(1000);
}
