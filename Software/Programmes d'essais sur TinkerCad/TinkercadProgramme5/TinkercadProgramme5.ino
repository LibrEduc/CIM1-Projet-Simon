/* Ce programme affiche l'état d'un des 4 boutons connectés à l'arduino.
 *  Il ne peux donc pas identifier la pression de multiples boutons,
 *  pour cela je pourrais par exemple stocker leurs état dans un tableau char.
 */

#define button1 3 // Il y a 4 boutons, le premier est nommé "button1" puis connecté à la broche n°3
#define button2 4
#define button3 5
#define button4 6
int buttonNumber = 0; // Variable contenant le numéro du bouton pressé, 0 signifiant qu'aucun bouton n'est actionné

void setup() {
  Serial.begin(9600); // Initialisation de la liaison série
  pinMode(button1, INPUT_PULLUP); // Déclaration des broches associées aux boutons en tant qu'entré. Utilisation d'une résistance de tirage interne
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
}

int button() {
  if (digitalRead(button1) && digitalRead(button2) && digitalRead(button3) && digitalRead(button4) == HIGH) { // Si tout les boutons sont à l'état haut c'est qu'aucun d'entre eux n'est pressé
    buttonNumber = 0;
  }
  else {
    if (digitalRead(button1) == LOW) { // Si le premier bouton est à l'état bas c'est qu'il est pressé
      buttonNumber = 1; // Stocker le numéro du bouton pressé dans cette variable
    }
    else if (digitalRead(button2) == LOW) {
      buttonNumber = 2;
    }
    else if (digitalRead(button3) == LOW) {
      buttonNumber = 3;
    }
    else { // Si ni le bouton n°1, ni le n°2, ni le n°3 n'est pressé c'est que le n°4 l'est à coup sûr
      buttonNumber = 4;
    }
  }
  return (buttonNumber); // Lorsque la procédure est executé elle retournera le numéro du bouton pressé contenu dans la variable "buttonNumber"
}

void loop() {
  buttonNumber = button(); // Executer la procédure qui va lire l'état des boutons et le retourner
  Serial.println(buttonNumber); // Afficher l'état des boutons
}
