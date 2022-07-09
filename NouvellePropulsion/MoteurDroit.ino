void moteurDroit(int arriveeTele){
  
if ((arriveeTele > valeurTelBasse && arriveeTele < valeurTelHaute) || millis()-chronoSwitchD < tmpsDArret)
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
      digitalWrite(pinInverseurDroit, HIGH);
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
      digitalWrite(pinInverseurDroit, LOW);
      sensD="Arriere" ;
    }
   else
    { // fonctionnement normal
      motPropulsionDroit.write(map(arriveeTele,valeurTelBasse,1000,1000,propultionMax));
    }
  }
}
}
