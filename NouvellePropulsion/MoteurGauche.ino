void moteurGauche(int arriveeTele){
  
if ((arriveeTele >  valeurTelBasse && arriveeTele < valeurTelHaute) or millis()-chronoSwitchG < 1000)
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
      motPropulsionGauche.write(map(arriveeTele,valeurTelHaute,1000,1000,propultionMax));
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
      motPropulsionGauche.write(map(500 - arriveeTele,500-valeurTelBasse,500,1000,propultionMax));
    }
  }
}
}
