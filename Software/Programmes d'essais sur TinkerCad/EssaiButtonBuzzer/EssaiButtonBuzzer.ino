#define buzzerPin 7
#define button0 3 // Il y a 4 boutons, le premier est nommé "button1" puis connecté à la broche n°3
#define button1 4
#define button2 5
#define button3 6
int buttonNumber[4] = {1, 1, 1, 1}; // Tableau de type int comprenant l'état des 4 boutons
int frequency = 440;
void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
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
  if (buttonNumber[0]==0) {
    frequency = 110;
  }
    if (buttonNumber[1]==0) {
    frequency = 220;
  }
    if (buttonNumber[2]==0) {
   frequency = 440;
  }
    if (buttonNumber[3]==0) {
    frequency = 880;
  }
  if (buttonNumber[0] && buttonNumber[1] && buttonNumber[2] && buttonNumber[3]==1) {
  noTone(buzzerPin); // Eteindre le buzzer
  }
  else {
    Serial.println(frequency);
    tone(buzzerPin, frequency);
  }

}
