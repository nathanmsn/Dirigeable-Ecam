void moteurGauche(int arriveeTele){
  
if ((arriveeTele >  valeurTelBasse && arriveeTele < valeurTelHaute) || millis()-chronoSwitchG < tmpsDArret)
  {
   motPropulsionGauche.write(0);
  }
else {
  //sens avant
  if (arriveeTele >= valeurTelHaute){
    if (sensG != "Avant") //alors il faut changer le sens de marche, cad mettre le moteur a zéro puis changer de sens
    {
      motPropulsionGauche.write(0);
      chronoSwitchG = millis();
      digitalWrite(pinInverseurGauche, LOW);
      sensG="Avant" ;
    }
   else
    { // fonctionnement normal
      motPropulsionGauche.write(map(arriveeTele,valeurTelHaute,2000,1000,propultionMax));
    }
  }
   //sens arriere
  if (arriveeTele <= valeurTelBasse){
    if (sensG != "Arriere") //alors il faut changer le sens de marche, cad mettre le moteur a zéro puis changer de sens
    {
      motPropulsionGauche.write(0);
      chronoSwitchG = millis();
      digitalWrite(pinInverseurGauche, HIGH);
      sensG="Arriere" ;
    }
   else
    { // fonctionnement normal
      motPropulsionGauche.write(map(arriveeTele,valeurTelBasse,1000,1000,propultionMax));
    }
  }
}
}
