void loop() 
{
 measureTelecommande();

//Servo intérieur (3 positions)
 
if (arriveeTelecommande[5]<0){
  servoInterieur.write(0);
}
if (arriveeTelecommande[5]>400 && arriveeTelecommande[5]<600){
  servoInterieur.write(30);
}
if (arriveeTelecommande[5]>900){
  servoInterieur.write(90);
}

//Servos Extérieurs (2 positions)
if (arriveeTelecommande[4]<0){
  servoDroit.write(55);
  servoGauche.write(90);
}
if (arriveeTelecommande[4]>900){
  servoDroit.write(165);
  servoGauche.write(0);
}

moteurGauche(arriveeTelecommande[joystickGauche]);
moteurDroit(arriveeTelecommande[joystickDroit]);
/*
 //Moteur Gauche
 if(arriveeTelecommande[joystickGauche] <= 480)
 {
    if (sens != "Arriere" && millis()- chronoSwitchG > 5000)
    {
      motPropulsionGauche.write(0);
      chronoSwitchG = millis();
      digitalWrite(pinInverseurGauche, HIGH);
      motPropulsionGauche.write(map(500 - arriveeTelecommande[joystickGauche],0,500,1000,propultionMax));
      sens="Arriere" ;
      
    }
    else
    {
      digitalWrite(pinInverseurGauche, HIGH);
       motPropulsionGauche.write(map(500 - arriveeTelecommande[joystickGauche],0,500,1000,propultionMax));
       sens = "Arriere" ;
    }
 }
 else if (arriveeTelecommande[joystickGauche] >= 520)
 {
  if (sens !="Avant"&& millis() - chronoSwitchG > 5000)
    {
      motPropulsionGauche.write(0);
      chronoSwitchG = millis();
      digitalWrite(pinInverseurGauche, LOW);
      motPropulsionGauche.write(map(arriveeTelecommande[joystickGauche],500,1000,1000,propultionMax));
      sens="Avant" ;
    }
   else
    {
      digitalWrite(pinInverseurGauche, LOW);
      motPropulsionGauche.write(map(arriveeTelecommande[joystickGauche],500,1000,1000,propultionMax));
      sens="Avant" ;
    }

  }
 else if (arriveeTelecommande[joystickGauche] >  480 && arriveeTelecommande[joystickGauche] < 520)
  {
   motPropulsionGauche.write(0);
  }

 //Moteur Droit
 if(arriveeTelecommande[joystickDroit] <= 480)
 {
    if (sens != "Arriere" && millis()- chronoSwitchD > 5000)
    {
      motPropulsionDroit.write(0);
      chronoSwitchD = millis();
      digitalWrite(pinInverseurDroit, HIGH);
      motPropulsionDroit.write(map(500 - arriveeTelecommande[joystickDroit],0,500,1000,propultionMax));
      sens="Arriere" ;
      
    }
    else
    {
      digitalWrite(pinInverseurDroit, HIGH);
       motPropulsionDroit.write(map(500 - arriveeTelecommande[joystickDroit],0,500,1000,propultionMax));
       sens = "Arriere" ;
    }
 }
 else if (arriveeTelecommande[joystickDroit] >= 520)
 {
  if (sens !="Avant" && millis() - chronoSwitchD > 5000)
    {
      motPropulsionDroit.write(0);
      chronoSwitchD = millis();
      digitalWrite(pinInverseurDroit, LOW);
      motPropulsionDroit.write(map(arriveeTelecommande[joystickDroit],500,1000,1000,propultionMax));
      sens="Avant" ;
    }
   else
    {
      digitalWrite(pinInverseurDroit, LOW);
      motPropulsionDroit.write(map(arriveeTelecommande[joystickDroit],500,1000,1000,propultionMax));
      sens="Avant" ;
    }

  }
 else if (arriveeTelecommande[joystickDroit] >  480 && arriveeTelecommande[joystickDroit] < 520)
  {
   motPropulsionGauche.write(0);
  }
 */
}
