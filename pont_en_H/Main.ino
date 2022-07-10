void loop() {
  
  measureTelecommande();
// moteur Haut Bas  
moteur(arriveeTelecommande[joystickDroitHB]);
// moteur Translation
//moteur(arriveeTelecommande[joystickDroitDG],borneENA);


//Balastes
balastes(arriveeTelecommande[0]);

//Pinces
pince(arriveeTelecommande[gear],arriveeTelecommande[1]);
  
}
