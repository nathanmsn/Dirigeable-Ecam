//Pince
void pince(int arriveeTelFermeture, int arriveeTelRotation){
// rotation de la pince
  servoRotation.write(map(arriveeTelRotation,1000,2000,0,180));
  
 // Fermeture de la pince 
 if (arriveeTelFermeture < 1300){
  servoFermeture.write(70); 
}
// Ouverture de la pince
if (arriveeTelFermeture > 1700){
  servoFermeture.write(160);
 }
 
}
