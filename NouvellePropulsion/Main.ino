void loop() 
{
 measureTelecommande();

//Servo intérieur (3 positions)
 
if (arriveeTelecommande[5]<1000){
  servoInterieur.write(0);
}
if (arriveeTelecommande[5]>1400 && arriveeTelecommande[5]<1600){
  servoInterieur.write(30);
}
if (arriveeTelecommande[5]>1900){
  servoInterieur.write(90);
}

//Servos Extérieurs (2 positions)
if (arriveeTelecommande[4]<1000){
  servoDroit.write(55);
  servoGauche.write(90);
}
if (arriveeTelecommande[4]>1900){
  servoDroit.write(165);
  servoGauche.write(0);
}
if (arriveeTelecommande[joystickGauche]<500 && arriveeTelecommande[joystickGauche]>-10 ||arriveeTelecommande[joystickDroit]<500 && arriveeTelecommande[joystickDroit]>-10 ) { // si jamais le recepteur radio se déconnecte, les moteurs s'éteignent automatiquement
moteurGauche(1500);
moteurDroit(1500);
}
else {

moteurGauche(arriveeTelecommande[joystickGauche]); // Commander le moteur Gauche
moteurDroit(arriveeTelecommande[joystickDroit]); // Commander le moteur Droit
}

}
