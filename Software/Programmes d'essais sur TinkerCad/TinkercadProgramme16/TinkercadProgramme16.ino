/* Ce programme génère des groupes de chiffres réellement aléatoires
 * grâce à différentes variantes de randomSeed();
 * En effet, il faut générer une "graine" différente régulièrement pour que
 * l'algorithme random(); ne génère pas tout le temps les mêmes chiffres.
 */
int number = 0;
void(* resetFunc) (void) = 0; // Lorsqu'elle est appelé, cette fonction redémarre l'arduino (reset)
/* ATTENTION la fonction de redémarrage ne marche pas bien sur tinkercad !
 *  Elle remplace le premier chiffre par un j...
 */
void setup() {
  Serial.begin(9600);
  
  randomSeed(analogRead(0)); // ok tinkercad, ok en physique
  //randomSeed(micros()); // Ca ne marche pas dans tinkercad, ok en physique

  for (int i = 0; i < 4; i++) { // Générer 4 chiffres aléatoires compris entre 0 et 9.
    number = random(10);
    Serial.println(number); // Les afficher
  }
  Serial.println(); // Laisser un espace
  delay(2000); // Attendre un peux
  resetFunc(); // Puis redémarrer l'arduino à fin de générer le prochain groupe de chiffre
}

void loop() {
}
