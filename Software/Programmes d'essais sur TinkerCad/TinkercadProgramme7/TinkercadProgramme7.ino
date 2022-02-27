#include <Adafruit_NeoPixel.h> // Importation de la bibliothèque pour gérer les NeoPixels
#define BrocheNeoPixel 2 // Broche sur laquelle les NeoPixels sont connectées
#define NombrePixel 4 // Nombre de NeoPixel
Adafruit_NeoPixel MesLed = Adafruit_NeoPixel(NombrePixel, BrocheNeoPixel, NEO_GRB + NEO_KHZ800); // Affectation des paramètres définies ci-dessus.

#define button1 3 // Il y a 4 boutons, le premier est nommé "button1" puis connecté à la broche n°3
#define button2 4
#define button3 5
#define button4 6
int buttonNumber = 0; // Variable contenant le numéro du bouton pressé, 0 signifiant qu'aucun bouton n'est actionné
#define buzzerPin 8 // Le buzzer est connecté à la broche n°8

void setup() {
  MesLed.begin(); // Initialiser la bibliothèque
  pinMode(button1, INPUT_PULLUP); // Déclaration des broches associées aux boutons en tant qu'entré. Utilisation d'une résistance de tirage interne
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT); // La broche utilisé par le buzzer est configuré en tant que sortie
}

int button() {
  if (digitalRead(button1) == LOW) { // Si le premier bouton est à l'état bas c'est qu'il est pressé
    buttonNumber = 1; // Stocker le numéro du bouton pressé dans cette variable
  }
  else if (digitalRead(button2) == LOW) {
    buttonNumber = 2;
  }
  else if (digitalRead(button3) == LOW) {
    buttonNumber = 3;
  }
  else if (digitalRead(button4) == LOW) {
    buttonNumber = 4;
  }
  else { // Revient à dire "Si ni le bouton n°1, ni le n°2, ni le n°3, ni le n°4 n'est pressé c'est que qu'aucun bouton n'est pressé"
    buttonNumber = 0;
  }
  return (buttonNumber); // Lorsque la procédure est executé elle retournera le numéro du bouton pressé contenu dans la variable "buttonNumber"
}

void buzzer() {
  switch (buttonNumber) { // On s'intéresse à la valeur stocké dans la variable buttonNumber
    case 1: // Si elle vaut 1 c'est que le premier bouton est pressé
      tone(buzzerPin, 110); // Jouer un Là à 110Hz
      break;
    case 2:
      tone(buzzerPin, 220);
      break;
    case 3:
      tone(buzzerPin, 440);
      break;
    case 4:
      tone(buzzerPin, 880);
      break;
    default: // Si elle ne vaut ni 1, ni 2, ni 3, ni 4, c'est qu'elle vaut 0 donc aucun bouton n'est pressé
      noTone(buzzerPin); // Eteindre le buzzer
      break;
  }
}

void led() {
  switch (buttonNumber) { // On s'intéresse à la valeur stocké dans la variable buttonNumber
    case 1: // Si elle vaut 1 c'est que le premier bouton est pressé
      MesLed.setPixelColor(0, MesLed.Color(150, 0, 0)); // Alors, la led n°0 sera verte
      break;
    case 2:
      MesLed.setPixelColor(1, MesLed.Color(0, 150, 0));
      break;
    case 3:
      MesLed.setPixelColor(2, MesLed.Color(0, 0, 150));
      break;
    case 4:
      MesLed.setPixelColor(3, 0xFFFF00);
      break;
    default: // Si elle ne vaut ni 1, ni 2, ni 3, ni 4, c'est qu'elle vaut 0 donc aucun bouton n'est pressé
      MesLed.setPixelColor(0, MesLed.Color(0, 0, 0)); // Alors les led doivent-être éteintes
      MesLed.setPixelColor(1, MesLed.Color(0, 0, 0));
      MesLed.setPixelColor(2, MesLed.Color(0, 0, 0));
      MesLed.setPixelColor(3, MesLed.Color(0, 0, 0));
      break;
  }

}

void loop() {
  buttonNumber = button(); // Executer la fonction qui va lire l'état des boutons et l'enregistrer dans la variable buttonNumber
  buzzer(); // Executer la procédure qui va jouer un son en fonction du bouton pressé
  led(); // Executer la procédure pour déterminer les leds à allumer
  MesLed.show(); // Allumer les led ou plus précisement rafraichir l'état des led
}
