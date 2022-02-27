// Détecer le rising edge et le falling edge sur un bouton

#define button1 3
int button1CurrentState = 0;
int button1PreviousState = 1;

void setup() {
  Serial.begin(9600);
  pinMode(button1, INPUT_PULLUP);
}

void loop() {
  button1CurrentState = digitalRead(button1); // Récupérer l'état actuel du bouton
  if (button1CurrentState != button1PreviousState) { // Si cet état a changé
    if (button1CurrentState == LOW) { // Si cet état est passé de haut à bas (C'est inversé à cause du PullUp)
      Serial.println("Pression"); // C'est que le bouton est pressé, falling edge
    }
    else { // Si cet état est passé de bas à haut
      Serial.println("Depression"); // C'est que le bouton est relaché, rising edge
    }
    delay(50); // Debounce ?
    button1PreviousState = button1CurrentState; // Fin de l'action, cet état fait donc désormais parti du passé
  }
}
