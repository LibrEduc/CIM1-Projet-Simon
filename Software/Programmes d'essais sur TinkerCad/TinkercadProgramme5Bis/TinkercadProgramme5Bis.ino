/* Ce programme lit puis stock l'état de 4 boutons dans un tableau avant de les afficher dans le moniteur série.
 *  Ainsi, plusieurs boutons peuvent être préssé en même temps.
 * https://html-color-codes.info/ Roue de couleurs hex
*/

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
  buttonNumber[0] = digitalRead(button0);
  buttonNumber[1] = digitalRead(button1);
  buttonNumber[2] = digitalRead(button2);
  buttonNumber[3] = digitalRead(button3);
}

void loop() {
  button();
  for (int i = 0; i < 4; i++) {
    Serial.print(buttonNumber[i]);
    delay(100);
  }
  Serial.println();
  Serial.print("Etat bouton n0->");
  Serial.println(buttonNumber[0]);
  Serial.print("Etat bouton n1->");
  Serial.println(buttonNumber[1]);
  Serial.print("Etat bouton n2->");
  Serial.println(buttonNumber[2]);
  Serial.print("Etat bouton n3->");
  Serial.println(buttonNumber[3]);
  Serial.println();
  Serial.println();
}
