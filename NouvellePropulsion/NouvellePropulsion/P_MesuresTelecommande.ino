
void measureTelecommande()
{

  for(int i = 0; i <= 3; i++)
  {
    arriveeTelecommande[i] = pulseIn(pinsTelecommande[i],HIGH, 50000) - 1000;
    
  }
}
