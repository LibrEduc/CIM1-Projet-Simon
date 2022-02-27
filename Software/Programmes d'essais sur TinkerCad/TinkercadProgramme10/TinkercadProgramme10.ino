// Un chiffre aléatoire est généré. Les boutons sont numéroté, le programme vérifira que l'utilisateur a pressé le bon.

#define button0 3 // Il y a 4 boutons, le premier est nommé "button0" puis connecté à la broche n°3
#define button1 4
#define button2 5
#define button3 6
int buttonNumber = 0; // Variable contenant le numéro du bouton pressé, 4 signifiant qu'aucun bouton n'est actionné
int NumberToGuess = 3; // Nombre à "deviner"

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
  bool checked = 0; // L'utilisateur a-t-il trouvé le bon bouton à presser ?
  while (checked == 0) { // Tant qu'il n'a pas trouvé
    buttonNumber = buttonState(); // Etre attentif à la pression des boutons
    if (buttonNumber == NumberToGuess) { // Si le bon bouton est pressé
      Serial.println("It's the right button"); // Indiquer dans le moniteur série que c'est le bon
      checked = 1; // Changer l'état de cette variable pour sortir de la boucle tant que
    }
    else if (buttonNumber == 4) { // Si buttonNumber vaut 4 c'est qu'aucun bouton n'est pressé
      Serial.println("Please press a button"); // Demander à l'utilisateur de pressé un bouton
      delay(100);
    }
    else { // Sinon, c'est que le mauvais bouton est pressé
      Serial.println("It's not the right button"); // Dire à l'utilisateur que ce n'est pas la bonne réponse
    } // Le laisser réessayer, encore et encore.
  }
}

void loop() {
  NumberToGuess = random(0, 4);
  Serial.print("Correct button: ");
  Serial.println(NumberToGuess); // Afficher la réponse à la devinette un brêve instant avant que le terminal ne soit rempli de "Please press a button"
  SimonCheck(); // Executer la procédure pour vérifier si l'utilisateur a pressé le bon bouton
  Serial.println("You won"); // Indiquer que la vérication est terminé et que l'utilisateur a gagné
  delay(2000); // Lui laisser le temps de se remettre de ses émotions
}
