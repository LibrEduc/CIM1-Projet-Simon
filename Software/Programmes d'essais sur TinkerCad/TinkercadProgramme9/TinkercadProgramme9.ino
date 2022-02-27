// Ce programme créer une suite de chiffre traduite en son et lumière. A chaque "tour" la suite s'allonge d'un chiffre, jusqu'à une longeur de 31 caractères... inclus ?

// https://html-color-codes.info/ Roue de couleurs hex
#include <Adafruit_NeoPixel.h> // Importation de la bibliothèque pour gérer les NeoPixels
#define NeoPixelPin 2 // Broche sur laquelle les NeoPixels sont connectées
#define PixelCount 4 // Nombre de NeoPixel
Adafruit_NeoPixel MyLed = Adafruit_NeoPixel(PixelCount, NeoPixelPin, NEO_GRB + NEO_KHZ800); // Affectation des paramètres définies ci-dessus.
#define buzzerPin 8 // Le buzzer est connecté à la broche n°8
int SimonSequence[31] = {0, 1, 2, 3, 0}; // Tableau avec 5 cases. La case n°0 contient 0, la case n°1 contient 1 [...] , la case n°4 contient 0
int SequenceLenght = 1;

void setup() {
  Serial.begin(9600); // Initialisation d'une liaison série pour du déboggage
  MyLed.begin(); // Initialiser la bibliothèque
  /* for (int i = 0; i < 5; i++) { // Afficher la SimonSequence initialisé
     Serial.println(SimonSequence[i]);
    } */
}

void OnLed(int ledNumber) { // Procédure prenant le numéro d'une led en paramètre et allumant la led correspondante
  switch (ledNumber) {
    case 0:
      MyLed.setPixelColor(ledNumber, MyLed.Color(150, 0, 0)); // Si la led n°0 est demandé, elle est configuré en rouge
      tone(buzzerPin, 252);
      break;
    case 1:
      MyLed.setPixelColor(ledNumber, MyLed.Color(0, 150, 0)); // Si la led n°1 est demandé, elle est configuré en vert
      tone(buzzerPin, 209);
      break;
    case 2:
      MyLed.setPixelColor(ledNumber, MyLed.Color(0, 0, 150)); // Si la led n°2 est demandé, elle est configuré en bleu
      tone(buzzerPin, 415);
      break;
    case 3:
      MyLed.setPixelColor(3, 0xFFFF00); // Si la led n°3 est demandé, elle est configuré en jaune
      tone(buzzerPin, 310);
      break;
  }
  MyLed.show(); // // Allumer la led configuré
  delay(420); // Pendant 420ms
  noTone(buzzerPin);
  MyLed.clear(); // Configurer toutes les led en "noir" (Equivalent de: MyLed.setPixelColor(broche, MyLed.Color(0, 0, 0));)
  MyLed.show(); // Eteindre toutes les led
  delay(50); // Pendant 50ms
}

void SimonShow() {
  for (int i = 0; i < SequenceLenght; i++) { // Recommencer jusqu'à avoir générer une suite de 5 chiffres
    randomSeed(analogRead(0)); // Générer une nouvelle graine pour le calcul des chiffres aléatoires
    SimonSequence[i] = random(0, 4); // Générer un chiffre aléatoire et le stocker dans la case i du tableau
    Serial.println(SimonSequence[i]); // Afficher ce chiffre dans le moniteur série
    OnLed(SimonSequence[i]); // Allumer la led correspondant au chiffre générer
  }
  if (SequenceLenght < 31) {
    Serial.print("SequenceLenght: ");
    Serial.println(SequenceLenght);
    SequenceLenght ++;
  }
  else {
    SequenceLenght = 1;
  }
}

void loop() {
  Serial.println("Debut SimonShow");
  SimonShow(); // Générer, <stocker et montrer une suite aléatoire.
  Serial.println("Fin SimonShow");
  delay(800); // Pause de 800ms avant de jouer la prochaine séquence
}
