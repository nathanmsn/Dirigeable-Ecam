void moteurDroit(int arriveeTele){
  
if ((arriveeTele > valeurTelBasse && arriveeTele < valeurTelHaute) or millis()-chronoSwitchD < 1000)
  {
   motPropulsionDroit.write(0);
  }
else {
  //sens avant
  if (arriveeTele >= valeurTelHaute){
    if (sensD != "Avant") //alors il faut changer le sens de marche, cad mettre le moteur a zéro puis changer de sens
    {
      motPropulsionDroit.write(0);
      chronoSwitchD = millis();
      digitalWrite(pinInverseurDroit, LOW);
      sensD="Avant" ;
    }
   else
    { // fonctionnement normal
      motPropulsionDroit.write(map(arriveeTele,valeurTelHaute,2000,1000,propultionMax));
    }
  }
   //sens arriere
  if (arriveeTele <= valeurTelBasse){
    if (sensD != "Arriere") //alors il faut changer le sens de marche, cad mettre le moteur a zéro puis changer de sens
    {
      motPropulsionDroit.write(0);
      chronoSwitchD = millis();
      digitalWrite(pinInverseurDroit, HIGH);
      sensD="Arriere" ;
    }
   else
    { // fonctionnement normal
      motPropulsionDroit.write(map(1500 - arriveeTele,1500-valeurTelBasse,1500,1000,propultionMax));
    }
  }
}
}
