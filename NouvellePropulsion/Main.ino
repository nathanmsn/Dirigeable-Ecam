void loop() 
{
 measureTelecommande();

//Servo intérieur (4 positions) A CHANGER SUR LA TELECOMMANDE
 
if (arriveeTelecommande[5]<1100){
  servoInterieur.write(30);
}
if (arriveeTelecommande[5]>1200 && arriveeTelecommande[5]<1400){
  servoInterieur.write(75);
}
if (arriveeTelecommande[5]>1500 && arriveeTelecommande[5]<1700){
  servoInterieur.write(120);
}
if (arriveeTelecommande[5]>1800){
  servoInterieur.write(165);

}

//Servos Extérieurs (2 positions)
if (arriveeTelecommande[4]<1300){
  servoDroit.write(180);
  servoGauche.write(78);
}
if (arriveeTelecommande[4]>1700){
  servoDroit.write(70);
  servoGauche.write(180);
}
if (arriveeTelecommande[joystickGauche]<500 && arriveeTelecommande[joystickGauche]>-10 ||arriveeTelecommande[joystickDroit]<500 && arriveeTelecommande[joystickDroit]>-10 ) { // si jamais le recepteur radio se déconnecte, les moteurs s'éteignent automatiquement
moteurGauche(1500);
moteurDroit(1500);
}
else {
// Rajout d'un coefficient pour chaque moteur, si les moteur ne sont pas centrés correctement, changer coefficient pour éviter de tourner 
int arriveemoteurGauche=CoeffGauche*arriveeTelecommande[joystickGauche];
int arriveemoteurDroit=CoeffDroit*arriveeTelecommande[joystickDroit];

moteurGauche(arriveemoteurGauche); // Commander le moteur Gauche
moteurDroit(arriveemoteurDroit); // Commander le moteur Droit
}

}
