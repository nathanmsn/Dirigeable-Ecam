void loop() 
{


 measureTelecommande();

 if(arriveeTelecommande[0] <= 500)
 {
    digitalWrite(pinInverseurGauche, LOW);
    
    
 }
 else
 {
    digitalWrite(pinInverseurGauche, HIGH);
  
 }
 }
 if(arriveeTelecommande[1] <= 500)
 {
  digitalWrite(pinInverseurDroit, LOW);
 }
 else
 {
  digitalWrite(pinInverseurDroit, HIGH);
  
 }
 
 motPropulsionGauche.write = map(arriveeTelecommande[2],0,1000,0,90);
 motPropulsionDroit.write = map(arriveeTelecommande[3],0,1000,0,90);
 
 
 
}
