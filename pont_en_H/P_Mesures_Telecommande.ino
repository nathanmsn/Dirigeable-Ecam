void measureTelecommande()
{
  delay(2000);
  for(int i = 0; i <= 3; i++)
  {
    arriveeTelecommande[i] = pulseIn(pinsTelecommande[i],HIGH, 50000);
    Serial.println(i);
    Serial.println(arriveeTelecommande[i]);    
  }
  
}
