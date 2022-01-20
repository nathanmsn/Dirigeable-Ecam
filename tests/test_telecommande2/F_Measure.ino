



void measureTelecommande(){
  int avg[6] = {0, 0, 0, 0, 0, 0};
  int cpt[6] = {0, 0, 0, 0, 0, 0};

  
  unsigned long init = millis();
  while(1){
    if ( (millis() - init) > 19.3 ) break;
    for(int i = 0; i <= 5; i++){
      avg[i] += analogRead(pinsTelecommande[i]);
      cpt[i]++;
    }
    
    
  }
 for(int i = 0; i <= 5; i++){
  channels[i][cmptMesuresTelecommande] = avg[i]/cpt[i];
 }

  
}
