
void measureTelecommande()
{

  for(int i = 0; i <= 5; i++)
  {
    arriveeTelecommande[i] = pulseIn(pinsTelecommande[i],HIGH, 50000) - 1000;
    //Serial.println(i);
    Serial.println(arriveeTelecommande[2]);
    
  }


  
}
