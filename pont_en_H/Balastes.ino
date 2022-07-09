void balastes(int arriveeTelecommande){

  if (arriveeTelecommande > 1700){
 
  digitalWrite(pinBalaste1, HIGH);  
  digitalWrite(pinBalaste2,HIGH);
}

  if (arriveeTelecommande < 1300){
    digitalWrite(pinBalaste1, LOW);  
    digitalWrite(pinBalaste2,LOW);
  }
}
