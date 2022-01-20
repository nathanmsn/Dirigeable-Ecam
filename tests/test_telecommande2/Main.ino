
void loop() {
  //Serial.println(" a");
  if(cmptMesuresTelecommande <= 4){
    measureTelecommande();
    cmptMesuresTelecommande++;
    //Serial.println(cmptMesuresTelecommande);
    for(int i = 0; i <= 5; i++){   
      Serial.print(pinsTelecommande[i]);
      Serial.print(" : ");
      Serial.println(channels[i][2]); 
  
    }
  }

  if(cmptMesuresTelecommande >= 4){
    
  /* // Serial.println(" compteur à 4");
    for(int i = 0; i <= 5; i++){
        for(int j = 0; j <= 3; j++){
          for(int k = 0; k <= 3; k++){
            if(channels[i][k] >= channels[i][k + 1]){
              int tmp = channels[k][i];
              channels[i][k] = channels[i][k + 1];
              channels[i][k + 1] = tmp;
            }
          }
        }
      }

    
    for(int i = 0; i <= 5; i++){   
      Serial.print(pinsTelecommande[i]);
      Serial.print(" : ");
      Serial.println(channels[i][2]); 
  
    }*/
    cmptMesuresTelecommande = 0;
    delay(1500);
 }
 delay(1500);
 Serial.println(" ");
}
