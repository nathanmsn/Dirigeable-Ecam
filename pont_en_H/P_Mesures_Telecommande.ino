void measureTelecommande()
{

  for(int i = 0; i <= 7; i++)
  {
    arriveeTelecommande[i] = pulseIn(pinsTelecommande[i],HIGH, 50000);
    Serial.println(i);
   Serial.println(arriveeTelecommande[joystickGauche]);    
  }
  
}
