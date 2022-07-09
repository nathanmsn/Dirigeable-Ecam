void loop() {
  
  measureTelecommande();
// moteur Haut Bas  
moteur(arriveeTelecommande[joystickDroitHB],borneENB);
// moteur Translation
moteur(arriveeTelecommande[joystickDroitDG],borneENA);


//Balastes
balastes(arriveeTelecommande[0]);

//Pinces
pince(arriveeTelecommande[AileDR],arriveeTelecommande[3]);
  
}
