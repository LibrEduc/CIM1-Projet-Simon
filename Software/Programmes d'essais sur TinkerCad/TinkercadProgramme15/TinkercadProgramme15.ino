// Ce programme compare la pression successive des boutons à une séquence encré en dur dans le code. Si la séquence est la bonne, l'utilisateur a gagné.
// Le programme ne comptabilise pas les erreurs mais les indique.
#define buzzerPin 8 // Le buzzer est connecté à la broche n°8
int buttonNumber = 0; // Variable contenant le numéro du bouton pressé, 0 signifiant qu'aucun bouton n'est actionné
#define button0 3
int button0CurrentState = 0;
int button0PreviousState = 1;
#define button1 4
int button1CurrentState = 0;
int button1PreviousState = 1;
#define button2 5
int button2CurrentState = 0;
int button2PreviousState = 1;
#define button3 6
int button3CurrentState = 0;
int button3PreviousState = 1;

// https://html-color-codes.info/ Roue de couleurs hex
#include <Adafruit_NeoPixel.h> // Importation de la bibliothèque pour gérer les NeoPixels
#define NeoPixelPin 2 // Broche sur laquelle les NeoPixels sont connectées
#define PixelCount 4 // Nombre de NeoPixel
Adafruit_NeoPixel MyLed = Adafruit_NeoPixel(PixelCount, NeoPixelPin, NEO_GRB + NEO_KHZ800); // Affectation des paramètres définies ci-dessus.

int SimonSequence[31] = {0, 1, 2, 3, 0}; // Tableau avec 5 cases. La case n°0 contient 0, la case n°1 contient 1 [...] , la case n°4 contient 0
int SequenceLenght = 1;

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
    randomSeed(analogRead(0));
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

int buttonState() {
  button0CurrentState = digitalRead(button0); // Récupérer l'état actuel du bouton
  button1CurrentState = digitalRead(button1); // Récupérer l'état actuel du bouton
  button2CurrentState = digitalRead(button2); // Récupérer l'état actuel du bouton
  button3CurrentState = digitalRead(button3); // Récupérer l'état actuel du bouton

  if (button0CurrentState != button0PreviousState) { // Si cet état a changé
    if (button0CurrentState == LOW) { // Si cet état est passé de haut à bas (C'est inversé à cause du PullUp)
      Serial.println("Pression bouton n0"); // C'est que le bouton est pressé, falling edge
      OnLed(0);
    }
    else { // Si cet état est passé de bas à haut
      Serial.println("Depression bouton n0"); // C'est que le bouton est relaché, rising edge
      buttonNumber = 0;
    }
    delay(50); // Debounce ?
    button0PreviousState = button0CurrentState; // Fin de l'action, cet état fait donc désormais parti du passé
  }

  else if (button1CurrentState != button1PreviousState) { // Si cet état a changé
    if (button1CurrentState == LOW) { // Si cet état est passé de haut à bas (C'est inversé à cause du PullUp)
      Serial.println("Pression bouton n1"); // C'est que le bouton est pressé, falling edge
      OnLed(1);
    }
    else { // Si cet état est passé de bas à haut
      Serial.println("Depression bouton n1"); // C'est que le bouton est relaché, rising edge
      buttonNumber = 1;
    }
    delay(50); // Debounce ?
    button1PreviousState = button1CurrentState; // Fin de l'action, cet état fait donc désormais parti du passé
  }
  else if (button2CurrentState != button2PreviousState) { // Si cet état a changé
    if (button2CurrentState == LOW) { // Si cet état est passé de haut à bas (C'est inversé à cause du PullUp)
      Serial.println("Pression bouton n2"); // C'est que le bouton est pressé, falling edge
      OnLed(2);
    }
    else { // Si cet état est passé de bas à haut
      Serial.println("Depression bouton n2"); // C'est que le bouton est relaché, rising edge
      buttonNumber = 2;
    }
    delay(50); // Debounce ?
    button2PreviousState = button2CurrentState; // Fin de l'action, cet état fait donc désormais parti du passé
  }
  else if (button3CurrentState != button3PreviousState) { // Si cet état a changé
    if (button3CurrentState == LOW) { // Si cet état est passé de haut à bas (C'est inversé à cause du PullUp)
      Serial.println("Pression bouton n3"); // C'est que le bouton est pressé, falling edge
      OnLed(3);
    }
    else { // Si cet état est passé de bas à haut
      Serial.println("Depression bouton n3"); // C'est que le bouton est relaché, rising edge
      buttonNumber = 3;
    }
    delay(50); // Debounce ?
    button3PreviousState = button3CurrentState; // Fin de l'action, cet état fait donc désormais parti du passé
  }
  else { // Revient à dire "Si ni le bouton n°0, ni le n°1, ni le n°2, ni le n°3 n'est pressé c'est que qu'aucun bouton n'est pressé"
    buttonNumber = 4;
  }
  return (buttonNumber); // Lorsque la procédure est executé elle retournera le numéro du bouton pressé contenu dans la variable "buttonNumber"
}

void SimonCheck() {
  Serial.println("Please press a button"); // Demander à l'utilisateur de presser un bouton
  int checkedNumber = 0; // Initaliser une variable permettant de vérifier que tout les chiffres de la séquence ont été pressé
  while (checkedNumber < SequenceLenght - 1) { // Tant que tout les chiffres de la séquence n'ont pas été pressé
    buttonNumber = buttonState(); // Etre attentif à la pression des boutons
    if (buttonNumber != 4) { // Si un bouton est pressé
      if (buttonNumber == SimonSequence[checkedNumber]) { // Et que c'est le bon au regard de la séquence
        Serial.println("It's the right button"); // Indiquer dans le moniteur série que c'est le bon
        checkedNumber ++; // Passer au nombre suivant de la séquence
        delay(100); // Attendre minimum 0.1sec avant la prochaine pression de bouton
      }
      else { // Sinon, c'est que le mauvais bouton est pressé
        Serial.println("It's not the right button"); // Dire à l'utilisateur que ce n'est pas la bonne réponse
        delay(100);// Attendre minimum 0.1sec avant la prochaine pression de bouton
      } // Le laisser réessayer, encore et encore.
      Serial.println("Please press a button"); // Demander à l'utilisateur de pressé un bouton
      Serial.println();
    }
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(button0, INPUT_PULLUP);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  MyLed.begin(); // Initialiser la bibliothèque
}

void loop() {
  Serial.println("Debut SimonShow");
  SimonShow(); // Générer, <stocker et montrer une suite aléatoire.
  Serial.println("Fin SimonShow");
  Serial.println("Début SimonCheck");
  SimonCheck(); // Executer la procédure pour vérifier si l'utilisateur a pressé le bon bouton
  Serial.println("You kinda won"); // Indiquer que la vérication est terminé et que l'utilisateur a gagné
  delay(800); // Pause de 800ms avant de jouer la prochaine séquence
}
