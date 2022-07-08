void loop() {
  

  // Configuration du L298N en "marche avant", pour le moteur connecté au pont A. Selon sa table de vérité, il faut que :
  digitalWrite(borneIN1, HIGH);                 // L'entrée IN1 doit être au niveau haut
  digitalWrite(borneIN2, LOW);                  // L'entrée IN2 doit être au niveau bas

  digitalWrite(borneIN3, HIGH);                 // L'entrée IN1 doit être au niveau haut
  digitalWrite(borneIN4, LOW);                  // L'entrée IN2 doit être au niveau bas

  // Et on lance le moteur (branché sur le pont A du L298N)
  lancerRotationMoteurPontA();
  lancerRotationMoteurPontB();

  // Puis on configure le L298N en "marche arrière", pour le moteur câblé sur le pont A. Selon sa table de vérité, il faut que :
  digitalWrite(borneIN1, LOW);                  // L'entrée IN1 doit être au niveau bas
  digitalWrite(borneIN2, HIGH);                 // L'entrée IN2 doit être au niveau haut

  digitalWrite(borneIN3, LOW);                  // L'entrée IN1 doit être au niveau bas
  digitalWrite(borneIN4, HIGH);                 // L'entrée IN2 doit être au niveau haut

  // Et on relance le moteur (branché sur le pont A du L298N)
  lancerRotationMoteurPontA();
  lancerRotationMoteurPontB();
  // Puis... on boucle à l'infini !
}


//************************************************************************************//
// Fonction : lancerRotationMoteurPontA()                                             //
// But :      Active l'alimentation du moteur branché sur le pont A                   //
//            pendant 2 secondes, puis le met à l'arrêt (au moins 1 seconde)          //
//************************************************************************************//
void lancerRotationMoteurPontA() {
  analogWrite(borneENA, abs(map(arriveeTelecommande[joystickDroit],1000,2000,0,255)));       // Active l'alimentation du moteur 1
 
  
}
void lancerRotationMoteurPontB() {
  analogWrite(borneENB, abs(map(arriveeTelecommande[joystickGauche],1000,2000,0,255)));       // Active l'alimentation du moteur 1
 }
