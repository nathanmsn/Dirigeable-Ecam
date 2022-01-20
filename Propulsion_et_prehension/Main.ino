void loop(){
  // put your main code here, to run repeatedly:
  measureTelecommande();
  
  /*if(arriveeTelecommande[3] >= 500){
    
    
    /*if(arriveeTelecommande[2] <= 500){
      pinServoTourner.write(0);     
    }
    else if(arriveeTelecommande[2] >= 500){
      pinServoTourner.write(180);
    }

    servoTourner.write(map(arriveeTelecommande[1], 0, 1000, 0, 180));

    if(arriveeTelecommande[0] <= 200){
      stepDecaler.step(stepsPerRevolution);
      Serial.println("mode 1");
    }
    else if(arriveeTelecommande[0] >= 800){
      Serial.println("mode 2");
      stepDecaler.step(-stepsPerRevolution);
    }

      
  }
  else if(arriveeTelecommande[3] < 500){

    if(arriveeTelecommande[0] <= 200){
      servoPince.write(0);
    }
    else if(arriveeTelecommande[0] >= 800){
      servoPince.write(180);
    }

    if(arriveeTelecommande[1] <= 200){
      stepDescendre.step(stepsPerRevolution);    
    }
    else if(arriveeTelecommande[1] >= 800){
       stepDescendre.step(-stepsPerRevolution);
    }
    
  }*/

  /*if(arriveeTelecommande[0] <= 500){
    motPropulsionVersArriere.writeMicroseconds(MIN_PULSE_LENGTH + map(arriveeTelecommande[0], 0, 500, 0, 1000));
    motPropulsionVersAvant.writeMicroseconds(MIN_PULSE_LENGTH);
  }
  else if(arriveeTelecommande[0] >= 500{
    motPropulsionVersAvant.writeMicroseconds(MIN_PULSE_LENGTH + map(arriveeTelecommande[0], 500, 1000, 0, 1000));
    motPropulsionVersArriere.writeMicroseconds(MIN_PULSE_LENGTH);
  }*/

  int intensiteMoteurAvant = map(arriveeTelecommande[2], 0, 1000, 0, 500);
  int intensiteMoteurArriere = map(arriveeTelecommande[2], 0, 1000, 0, 500);

  if(arriveeTelecommande[3] < 500){
 
    motPropulsionVersArriere1.writeMicroseconds(MIN_PULSE_LENGTH + intensiteMoteurAvant);
    motPropulsionVersArriere2.writeMicroseconds(MIN_PULSE_LENGTH + intensiteMoteurAvant + map(arriveeTelecommande[3], 0, 500, 0, 200));
    motPropulsionVersAvant1.writeMicroseconds(MIN_PULSE_LENGTH + intensiteMoteurArriere);
    motPropulsionVersAvant2.writeMicroseconds(MIN_PULSE_LENGTH + intensiteMoteurArriere);
    
  }
  if(arriveeTelecommande[3] >= 500){
    motPropulsionVersArriere1.writeMicroseconds(MIN_PULSE_LENGTH + intensiteMoteurAvant + map(arriveeTelecommande[3], 500, 1000, 0, 200));
    motPropulsionVersArriere2.writeMicroseconds(MIN_PULSE_LENGTH + intensiteMoteurAvant);
    motPropulsionVersAvant1.writeMicroseconds(MIN_PULSE_LENGTH + intensiteMoteurArriere);
    motPropulsionVersAvant2.writeMicroseconds(MIN_PULSE_LENGTH + intensiteMoteurArriere);

   
  }
  
  

}
