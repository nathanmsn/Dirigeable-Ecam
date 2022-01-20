void loop() {
  
  intensiteMoteursStabilisation = 0; 
  for(int i = 0; i <= 1; i++){
    Serial.println(arriveeTelecommande[i]);
  }
  int test = distanceToGround();//pour enlever les mesures qui font 0
  if(test != 0){
    distance = test;
    tableauDistances[compteurMesures] = distance;
    compteurMesures++;
  }

  if(compteurMesures == 4){
    for(int j = 0; j <= 3; j++){
      for(int i = 0; i <= 3; i++){
        if(tableauDistances[i] >= tableauDistances[i + 1]){
          int tmp = tableauDistances[i];
          tableauDistances[i] = tableauDistances[i + 1];
          tableauDistances[i + 1] = tmp;
        }
      }
    }
    compteurMesures = 0;
  }
  
  int alphaSlideGauche;
  int alphaSlideDroit;
  int alphaYawGauche;
  int alphaYawDroit;
  measureTelecommande();

  int th = 100;
  int  intensiteMoteurAvantDroit = 0;
  int  intensiteMoteurAvantGauche = 0;
  int  intensiteMoteurArriereDroit = 0;
  int  intensiteMoteurArriereGauche = 0;


  
  if(arriveeTelecommande[1] > 600){
    arriveeTelecommande[1] = arriveeTelecommande[1] - 500;
    alphaSlideDroit = arriveeTelecommande[1]/6 ;//(map(arriveeTelecommande[0], 0, 500, 0, buterDesServosSlide));
    servoAvantGauche.write(0);
    servoArriereGauche.write(180);
    servoAvantDroit.write(180 - alphaSlideDroit);  
    servoArriereDroit.write(alphaSlideDroit);
    intensiteMoteurAvantDroit += arriveeTelecommande[1];
    intensiteMoteurArriereDroit += arriveeTelecommande[1];
    motStabilisationAvantDroit.writeMicroseconds(MIN_PULSE_LENGTH + th + int(float(intensiteMoteurAvantDroit)/3.0f));
    motStabilisationAvantGauche.writeMicroseconds(MIN_PULSE_LENGTH + th + int(float(intensiteMoteurAvantGauche)/3.0f));
    motStabilisationArriereDroit.writeMicroseconds(MIN_PULSE_LENGTH + th + int(float(intensiteMoteurArriereDroit)/3.0f));
    motStabilisationArriereGauche.writeMicroseconds(MIN_PULSE_LENGTH + th + int(float(intensiteMoteurArriereGauche)/3.0f));
    
  }
  else if(arriveeTelecommande[1] < 400){
    arriveeTelecommande[1] = 500 - arriveeTelecommande[1];
    alphaSlideGauche = arriveeTelecommande[1]  /6 ;//map(arriveeTelecommande[0], 0, 500, 0, buterDesServosSlide);
    servoAvantGauche.write(alphaSlideGauche);
    servoArriereGauche.write(180-alphaSlideGauche);
    servoAvantDroit.write(180);
    servoArriereDroit.write(0);
    
    intensiteMoteurArriereGauche += arriveeTelecommande[1] ;
    intensiteMoteurAvantGauche += arriveeTelecommande[1];
    motStabilisationAvantDroit.writeMicroseconds(MIN_PULSE_LENGTH + th + int(float(intensiteMoteurAvantDroit)/3.0f));
    motStabilisationAvantGauche.writeMicroseconds(MIN_PULSE_LENGTH + th + int(float(intensiteMoteurAvantGauche)/3.0f));
    motStabilisationArriereDroit.writeMicroseconds(MIN_PULSE_LENGTH + th + int(float(intensiteMoteurArriereDroit)/3.0f));
    motStabilisationArriereGauche.writeMicroseconds(MIN_PULSE_LENGTH + th + int(float(intensiteMoteurArriereGauche)/3.0f));
  }
  else if(arriveeTelecommande[0] > 600){
    arriveeTelecommande[0] = arriveeTelecommande[0] - 500;
    alphaYawDroit =  arriveeTelecommande[0] /6 ;//(map(arriveeTelecommande[1], 0, 400, 0, buterDesServosYaw));
    servoAvantGauche.write(0);
    servoArriereGauche.write(180-alphaYawDroit);
    servoAvantDroit.write(180-alphaYawDroit);
    servoArriereDroit.write(0);  
    intensiteMoteurArriereGauche += arriveeTelecommande[0];
    intensiteMoteurAvantDroit += arriveeTelecommande[0];
    motStabilisationAvantDroit.writeMicroseconds(MIN_PULSE_LENGTH + th + int(float(intensiteMoteurAvantDroit)/3.0f));
    motStabilisationAvantGauche.writeMicroseconds(MIN_PULSE_LENGTH + th + int(float(intensiteMoteurAvantGauche)/3.0f));
    motStabilisationArriereDroit.writeMicroseconds(MIN_PULSE_LENGTH + th + int(float(intensiteMoteurArriereDroit)/3.0f));
    motStabilisationArriereGauche.writeMicroseconds(MIN_PULSE_LENGTH + th + int(float(intensiteMoteurArriereGauche)/3.0f));
  }
  else if(arriveeTelecommande[0] < 400){
    arriveeTelecommande[0] = 500 - arriveeTelecommande[0];
    alphaSlideGauche =  arriveeTelecommande[0]  /6 ;//map(arriveeTelecommande[1], 0, 500, 0, buterDesServosYaw);
    servoAvantGauche.write(alphaSlideGauche);
    servoArriereGauche.write(180);
    servoAvantDroit.write(180);
    servoArriereDroit.write(alphaSlideGauche);
    intensiteMoteurAvantGauche += arriveeTelecommande[0];
    intensiteMoteurArriereDroit += arriveeTelecommande[0];
    motStabilisationAvantDroit.writeMicroseconds(MIN_PULSE_LENGTH + th + int(float(intensiteMoteurAvantDroit)/3.0f));
    motStabilisationAvantGauche.writeMicroseconds(MIN_PULSE_LENGTH + th + int(float(intensiteMoteurAvantGauche)/3.0f));
    motStabilisationArriereDroit.writeMicroseconds(MIN_PULSE_LENGTH + th + int(float(intensiteMoteurArriereDroit)/3.0f));
    motStabilisationArriereGauche.writeMicroseconds(MIN_PULSE_LENGTH + th + int(float(intensiteMoteurArriereGauche)/3.0f));
  }
  else{
    servoAvantGauche.write(0);
    servoArriereGauche.write(180);
    servoAvantDroit.write(180);
    servoArriereDroit.write(0);

    if(tableauDistances[2] -  distanceIdeale <=  -10){
      intensiteMoteursStabilisation += 50;

      if(tableauDistances[2] - distanceIdeale <= -20){
        intensiteMoteursStabilisation += 80;

        if(tableauDistances[2] - distanceIdeale <= -30){
          intensiteMoteursStabilisation += 80;
          if(tableauDistances[2] <= 70)
            intensiteMoteursStabilisation += 100;

        }
       }
    }
    motStabilisationAvantDroit.writeMicroseconds(MIN_PULSE_LENGTH + intensiteMoteursStabilisation);
    motStabilisationAvantGauche.writeMicroseconds(MIN_PULSE_LENGTH + intensiteMoteursStabilisation);
    motStabilisationArriereDroit.writeMicroseconds(MIN_PULSE_LENGTH + intensiteMoteursStabilisation);
    motStabilisationArriereGauche.writeMicroseconds(MIN_PULSE_LENGTH + intensiteMoteursStabilisation);
    

    
  }




  
  
  /*int alphaYawGauche = map(arriveeTelecommande[1], 0, 500, 0, buterDesServosYaw);
  int alphaYawDroit = map(arriveeTelecommande[1], 500, 1000, 0, buterDesServosYaw);
  int alphaSlideGauche = map(arriveeTelecommande[0], 0, 500, 0, buterDesServosSlide);
  int alphaSlideDroit = map(arriveeTelecommande[0], 500, 1000, 0, buterDesServosSlide);
  

  if(alphaYawGauche > buterDesServosYaw){
    alphaYawGauche = 0;
  }
  if(alphaYawDroit < 0){
    alphaYawDroit = 0;
  }  
  if(alphaSlideGauche > buterDesServosSlide){
    alphaYawGauche = 0;
  }
  if(alphaSlideGauche < 0){
    alphaYawDroit = 0;
  }


  servoAvantGauche.write(alphaYawDroit + alphaSlideGauche);

  servoAvantDroit.write(180 - alphaYawGauche - alphaSlideGauche);
  servoArriereGauche.write(180 - alphaYawGauche - alphaSlideDroit);
  servoArriereDroit.write(alphaYawDroit + alphaSlideDroit);*/
  
/*
  int  intensiteMoteurAvantDroit = intensiteMoteursStabilisation;
  int  intensiteMoteurAvantGauche = intensiteMoteursStabilisation;
  int  intensiteMoteurArriereDroit = intensiteMoteursStabilisation;
  int  intensiteMoteurArriereGauche = intensiteMoteursStabilisation;
  ReadGY521(GyAccTemp, GATCorr);
  ComputeAngle(GyAccTemp, PitchRoll);
  //Serial.println(PitchRoll[0]);
  //Serial.println(PitchRoll[1]);
  
  int difInitRoll = rollInitial - PitchRoll[1];
  int sumInitRoll = rollInitial + PitchRoll[1];
  int difInitPitch = pitchInitial - PitchRoll[0];
  int sumInitPitch = pitchInitial + PitchRoll[0];
  if(difInitRoll <= 0){
    difInitRoll = 0;
  }
  if(sumInitRoll <= 0){
    sumInitRoll = 0;
  }
  if(difInitPitch <= 0){
    difInitPitch = 0;
  }
  if(sumInitPitch <= 0){
    sumInitPitch = 0;
  }
 
  intensiteMoteurAvantDroit += (sumInitPitch)*10 + (difInitRoll)*10;
  intensiteMoteurAvantGauche += (sumInitPitch)*10 + (sumInitRoll)*10;
  intensiteMoteurArriereDroit += (difInitPitch)*10 + (difInitRoll)*10;
  intensiteMoteurArriereGauche += (difInitPitch)*10 + (sumInitRoll)*10;
 */
  /*Serial.println(intensiteMoteurAvantDroit);
  Serial.println(intensiteMoteurAvantGauche);
  Serial.println(intensiteMoteurArriereDroit);
  Serial.println(intensiteMoteurArriereGauche);
  Serial.println();


  Serial.println(intensiteMoteurAvantDroit/cos((alphaYawGauche + alphaSlideGauche)*2*pi));
  Serial.println(intensiteMoteurAvantGauche/cos((alphaYawDroit + alphaSlideGauche)*2*pi));
  Serial.println(intensiteMoteurArriereDroit/cos((alphaYawGauche + alphaSlideDroit)*2*pi));
  Serial.println(intensiteMoteurArriereGauche/cos((alphaYawDroit + alphaSlideDroit)*2*pi));
  Serial.println();*/

/*
    if(intensiteMoteurAvantDroit >= 200){
      intensiteMoteurAvantDroit = 200;
    }
    if(intensiteMoteurAvantGauche >= 200){
      intensiteMoteurAvantGauche = 200;
    }
    if(intensiteMoteurArriereDroit >= 200){
      intensiteMoteurArriereDroit = 200;
    }
    if(intensiteMoteurArriereGauche >= 200){
      intensiteMoteurArriereGauche = 200;
    }
*/
  
 /* motStabilisationAvantDroit.writeMicroseconds(MIN_PULSE_LENGTH + intensiteMoteurAvantDroit/cos((alphaYawGauche + alphaSlideGauche)*2*pi));
  motStabilisationAvantGauche.writeMicroseconds(MIN_PULSE_LENGTH + intensiteMoteurAvantGauche/cos((alphaYawDroit + alphaSlideGauche)*2*pi));
  motStabilisationArriereDroit.writeMicroseconds(MIN_PULSE_LENGTH + intensiteMoteurArriereDroit/cos((alphaYawGauche + alphaSlideDroit)*2*pi));
  motStabilisationArriereGauche.writeMicroseconds(MIN_PULSE_LENGTH + intensiteMoteurArriereGauche/cos((alphaYawDroit + alphaSlideDroit)*2*pi));*/

}
