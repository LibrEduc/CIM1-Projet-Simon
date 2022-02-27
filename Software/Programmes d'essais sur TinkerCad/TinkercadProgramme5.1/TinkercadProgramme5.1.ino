#include <Adafruit_NeoPixel.h> // Importation de la bibliothèque pour gérer les NeoPixels
#define BrocheNeoPixel 2 // Broche sur laquelle les NeoPixels sont connectées
#define NombrePixel 4 // Nombre de NeoPixel
Adafruit_NeoPixel MesLed = Adafruit_NeoPixel(NombrePixel, BrocheNeoPixel, NEO_GRB + NEO_KHZ800); // Affectation des paramètres définies ci-dessus.


#define button0 3 // Il y a 4 boutons, le premier est nommé "button1" puis connecté à la broche n°3
#define button1 4
#define button2 5
#define button3 6
int buttonNumber[4] = {1, 1, 1, 1}; // Tableau de type int comprenant l'état des 4 boutons

void setup() {
  MesLed.begin(); // Initialiser la bibliothèque
  Serial.begin(9600); // Initialisation de la liaison série
  pinMode(button0, INPUT_PULLUP); // Déclaration des broches associées aux boutons en tant qu'entré. Utilisation d'une résistance de tirage interne
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
}

void button() {
  buttonNumber[0] = digitalRead(button0); // La case n°0 du tableau contient l'état du bouton n°0 en cet instant
  buttonNumber[1] = digitalRead(button1);
  buttonNumber[2] = digitalRead(button2);
  buttonNumber[3] = digitalRead(button3);
}

void led() {
  if (buttonNumber[0] == 0) { // Si le bouton n°0 est à l'état bas c'est qu'il est pressé
    MesLed.setPixelColor(0, MesLed.Color(150, 0, 0)); // Alors, la led n°0 sera verte
  }
  else { // Si le bouton n°0 n'est pas pressé
    MesLed.setPixelColor(0, MesLed.Color(0, 0, 0)); // Alors, éteindre la led n°0
  }
  if (buttonNumber[1] == 0) {
    MesLed.setPixelColor(1, MesLed.Color(0, 150, 0));
  }
  else {
    MesLed.setPixelColor(1, MesLed.Color(0, 0, 0));
  }
  if (buttonNumber[2] == 0) {
    MesLed.setPixelColor(2, MesLed.Color(0, 0, 150));
  }
  else {
    MesLed.setPixelColor(2, MesLed.Color(0, 0, 0));
  }
  if (buttonNumber[3] == 0) {
    MesLed.setPixelColor(3, 0xFFFF00);
  }
  else {
    MesLed.setPixelColor(3, MesLed.Color(0, 0, 0));
  }

}

void loop() {
  button(); // Exectuer la procédure pour lire l'état des boutons
  led(); // Executer la procédure pour déterminer les leds à allumer
  MesLed.show(); // Allumer les led ou plus précisement rafraichir l'état des led
}
