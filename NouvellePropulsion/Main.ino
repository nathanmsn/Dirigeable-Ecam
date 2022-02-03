void loop() 
{


 measureTelecommande();


 //Moteur Gauche
 if(arriveeTelecommande[joystickGauche] <= 480)
 {
    if (sens != 1)
    {
      motPropulsionGauche.write(0);
      delay(1000);
      digitalWrite(pinInverseurGauche, HIGH);
      motPropulsionGauche.write(map(500 - arriveeTelecommande[joystickGauche],0,500,1000,propultionMax));
      sens=1;
      
    }
    else
    {
      digitalWrite(pinInverseurGauche, HIGH);
       motPropulsionGauche.write(map(500 - arriveeTelecommande[joystickGauche],0,500,1000,propultionMax));
       sens = 1;
    }
 }
 else if (arriveeTelecommande[joystickGauche] >= 520)
 {
  if (sens != 0)
    {
      motPropulsionGauche.write(0);
      delay(1000);
      digitalWrite(pinInverseurGauche, LOW);
      motPropulsionGauche.write(map(arriveeTelecommande[joystickGauche],500,1000,1000,propultionMax));
      sens=0;
    }
   else
    {
      digitalWrite(pinInverseurGauche, LOW);
      motPropulsionGauche.write(map(arriveeTelecommande[joystickGauche],500,1000,1000,propultionMax));
      sens=0;
    }

  }
 else if (arriveeTelecommande[joystickGauche] >  480 && arriveeTelecommande[joystickGauche] < 520)
  {
   motPropulsionGauche.write(0);
  }
}
 
//motPropulsionGauche.write = map(arriveeTelecommande[2],0,1000,0,90);
//motPropulsionDroit.write = map(arriveeTelecommande[3],0,1000,0,90);
