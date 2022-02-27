#define buzzerPin 8 // Le buzzer est connecté à la broche n°8
void setup() {
  pinMode(buzzerPin, OUTPUT); // La broche utilisé par le buzzer est configuré en tant que sortie

}

void loop() {
  tone(buzzerPin, 110); // Jouer un Là en première octave, 110Hz
  delay(500); // Pendant une demi seconde
  noTone(buzzerPin); // Eteindre le buzzer
  delay(1500); // Pendant 1,5 sec
  tone(buzzerPin, 220); // Jouer un Là en seconde octave, 220Hz
  delay(500);
  noTone(buzzerPin);
  delay(1500);
  tone(buzzerPin, 440); // Jouer un Là en troisième octave, 440Hz
  delay(500);
  noTone(buzzerPin);
  delay(1500);
  tone(buzzerPin, 880); // Jouer un Là en quatrième octave, 880Hz
  delay(500);
  noTone(buzzerPin);
  delay(1500);
}
