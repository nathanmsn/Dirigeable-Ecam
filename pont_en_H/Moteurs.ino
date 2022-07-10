void moteur(int arriveeTele){
  
if ((arriveeTele > valeurTelBasse && arriveeTele < valeurTelHaute))
  {
   analogWrite(borneENB, 0);  
  }
else {
  //sens avant

  
  if (arriveeTele >= valeurTelHaute){
    /*
  }
    // Configuration du L298N en "marche avant", pour le moteur connecté au pont A. Selon sa table de vérité, il faut que :
  digitalWrite(borneIN1, HIGH);                 // L'entrée IN1 doit être au niveau haut
  digitalWrite(borneIN2, LOW);                  // L'entrée IN2 doit être au niveau bas
*/
  digitalWrite(borneIN3, HIGH);                 // L'entrée IN1 doit être au niveau haut
  digitalWrite(borneIN4, LOW);                  // L'entrée IN2 doit être au niveau bas
  analogWrite(borneENB, abs(map(arriveeTele,valeurTelHaute,2000,0,255)));  
    }

   //sens arriere
  if (arriveeTele <= valeurTelBasse){
    // Puis on configure le L298N en "marche arrière", pour le moteur câblé sur le pont A. Selon sa table de vérité, il faut que :
    /*
  digitalWrite(borneIN1, LOW);                  // L'entrée IN1 doit être au niveau bas
  digitalWrite(borneIN2, HIGH);                 // L'entrée IN2 doit être au niveau haut
*/
  digitalWrite(borneIN3, LOW);                  // L'entrée IN1 doit être au niveau bas
  digitalWrite(borneIN4, HIGH);                 // L'entrée IN2 doit être au niveau haut

  analogWrite(borneENB, abs(map(arriveeTele,valeurTelBasse,1000,0,255)));  

    

    }
}
}
