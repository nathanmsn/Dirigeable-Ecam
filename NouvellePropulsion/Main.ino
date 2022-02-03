void loop() 
{


 measureTelecommande();



//Moteur Droit
 if(arriveeTelecommande[joystickDroit] <= 500)
 {
  if (pinInverseurDroit != LOW){
    motPropulsionDroit.write(0);
    chronoSwitchD = millis();
  }
    if (millis() - chronoSwitchD >= 1000){ 
      digitalWrite(pinInverseurDroit, LOW);
      motPropulsionDroit.write(map(500 - arriveeTelecommande[joystickDroit],0,500,1000,propultionMax));
    }
 }
 else
 {  
 if (pinInverseurDroit != HIGH){
    motPropulsionDroit.write(0);
    chronoSwitchD = millis();
  }
    if (millis() - chronoSwitchD >= 1000){ 
    digitalWrite(pinInverseurDroit, HIGH);
    motPropulsionDroit.write(map(arriveeTelecommande[joystickDroit],500,1000,1000,propultionMax));
  }
 }

 //Moteur Gauche
 if(arriveeTelecommande[joystickGauche] <= 500)
 {
 if (pinInverseurDroit != LOW){
    motPropulsionDroit.write(0);
    chronoSwitchG = millis();
  }
    if (millis() - chronoSwitchG >= 1000){ 
  digitalWrite(pinInverseurGauche, LOW);
  motPropulsionGauche.write(map(500 - arriveeTelecommande[joystickGauche],0,500,1000,propultionMax));
    }
 }
 else
 {  
 if (pinInverseurDroit != HIGH){
    motPropulsionDroit.write(0);
    chronoSwitchG = millis();
  }
    if (millis() - chronoSwitchG >= 1000){ 
  digitalWrite(pinInverseurGauche, HIGH);
  motPropulsionGauche.write(map(arriveeTelecommande[joystickGauche],500,1000,1000,propultionMax));
    }
 }
 
//motPropulsionGauche.write = map(arriveeTelecommande[2],0,1000,0,90);
//motPropulsionDroit.write = map(arriveeTelecommande[3],0,1000,0,90);
 
 
 
}
