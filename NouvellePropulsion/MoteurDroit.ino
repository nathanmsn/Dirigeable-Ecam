void moteurDroit(int arriveeTele){
  
if ((arriveeTele >  valeurTelBasse && arriveeTele < valeurTelHaute) or millis()-chronoSwitchD < 1000)
  {
   motPropulsionDroit.write(0);
  }
else {
  //sens avant
  if (arriveeTele >= valeurTelHaute){
    if (sens != "Avant") //alors il faut changer le sens de marche, cad mettre le moteur a zéro puis changer de sens
    {
      motPropulsionDroit.write(0);
      chronoSwitchD = millis();
      digitalWrite(pinInverseurDroit, LOW);
      sens="Avant" ;
    }
   else
    { // fonctionnement normal
      motPropulsionDroit.write(map(arriveeTele,valeurTelHaute,1000,1000,propultionMax));
    }
  }
   //sens arriere
  if (arriveeTele <= valeurTelBasse){
    if (sens != "Arriere") //alors il faut changer le sens de marche, cad mettre le moteur a zéro puis changer de sens
    {
      motPropulsionDroit.write(0);
      chronoSwitchD = millis();
      digitalWrite(pinInverseurDroit, HIGH);
      sens="Arriere" ;
    }
   else
    { // fonctionnement normal
      motPropulsionDroit.write(map(500 - arriveeTele,500-valeurTelBasse,500,1000,propultionMax));
    }
  }
}
}
