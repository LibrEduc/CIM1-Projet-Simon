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

int buttonNumber = 0; // Variable contenant le numéro du bouton pressé, 0 signifiant qu'aucun bouton n'est actionné

int button() {
  button0CurrentState = digitalRead(button0); // Récupérer l'état actuel du bouton
  button1CurrentState = digitalRead(button1); // Récupérer l'état actuel du bouton
  button2CurrentState = digitalRead(button2); // Récupérer l'état actuel du bouton
  button3CurrentState = digitalRead(button3); // Récupérer l'état actuel du bouton

  if (button0CurrentState != button0PreviousState) { // Si cet état a changé
    if (button0CurrentState == LOW) { // Si cet état est passé de haut à bas (C'est inversé à cause du PullUp)
      Serial.println("Pression bouton n0"); // C'est que le bouton est pressé, falling edge
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

void setup() {
  Serial.begin(9600);
  pinMode(button0, INPUT_PULLUP);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
}

void loop() {
  buttonNumber = button(); // Executer la procédure qui va lire l'état des boutons et le retourner
  if (buttonNumber != 4) {
    Serial.print("En gros c'est le: ");
    Serial.println(buttonNumber); // Afficher l'état des boutons
    Serial.println("");
  }
}
