// Une suite de chiffre est initalisé. Sans aucune aide l'utilisateur doit presser les boutons dans le bon ordre pour "gagner".
// Il suffit de regarder le code pour connaître la solution qui en plus ne peut-être changé que manuellement !
#define button0 3 // Il y a 4 boutons, le premier est nommé "button0" puis connecté à la broche n°3
#define button1 4
#define button2 5
#define button3 6
int buttonNumber = 0; // Variable contenant le numéro du bouton pressé, 4 signifiant qu'aucun bouton n'est actionné
int NumberToGuess = 3; // Nombre à "deviner"
int SimonSequence[5] = {0, 1, 2, 3, 0}; // Tableau avec 5 cases. La case n°0 contient 0, la case n°1 contient 1 [...] , la case n°4 contient 0

void setup() {
  Serial.begin(9600); // Initialisation de la liaison série
  pinMode(button0, INPUT_PULLUP); // Déclaration des broches associées aux boutons en tant qu'entré. Utilisation d'une résistance de tirage interne
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
}

int buttonState() {
  if (digitalRead(button0) == LOW) { // Si le premier bouton est à l'état bas c'est qu'il est pressé
    buttonNumber = 0; // Stocker le numéro du bouton pressé dans cette variable
  }
  else if (digitalRead(button1) == LOW) {
    buttonNumber = 1;
  }
  else if (digitalRead(button2) == LOW) {
    buttonNumber = 2;
  }
  else if (digitalRead(button3) == LOW) {
    buttonNumber = 3;
  }
  else { // Revient à dire "Si ni le bouton n°0, ni le n°1, ni le n°2, ni le n°3 n'est pressé c'est que qu'aucun bouton n'est pressé"
    buttonNumber = 4; // La variable prends la valeur "4" lorsqu'aucun bouton n'est pressé
  }
  return (buttonNumber); // Lorsque la procédure est executé elle retournera le numéro du bouton pressé contenu dans la variable "buttonNumber"
}

void SimonCheck() {
  Serial.println("Please press a button"); // Demander à l'utilisateur de presser un bouton
  int checkedNumber = 0; // Initaliser une variable permettant de vérifier que tout les chiffres de la séquence ont été pressé
  while (checkedNumber < 5) { // Tant que tout les chiffres de la séquence n'ont pas été pressé
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

void loop() {
  SimonCheck(); // Executer la procédure pour vérifier si l'utilisateur a pressé le bon bouton
  Serial.println("You won"); // Indiquer que la vérication est terminé et que l'utilisateur a gagné
  delay(2000); // Lui laisser le temps de se remettre de ses émotions
}
