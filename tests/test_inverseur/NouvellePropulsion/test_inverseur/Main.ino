void loop() 
{
  if (Serial.available()) {
        data = Serial.read();

        switch (data) {
            // 0
            case 48 : Serial.println("Sending minimum throttle");
                      motPropulsionGauche.writeMicroseconds(MIN_PULSE_LENGTH);
                      motPropulsionDroit.writeMicroseconds(MIN_PULSE_LENGTH);

            break;

            // 1
            case 49 : Serial.println("Sending maximum throttle");
                      motPropulsionGauche.writeMicroseconds(MAX_PULSE_LENGTH - 900);
                      motPropulsionDroit.writeMicroseconds(MAX_PULSE_LENGTH - 900);

            break;

            // 2
            case 50 : Serial.print("Running test in 3");
                      delay(1000);
                      Serial.print(" 2");
                      delay(1000);
                      Serial.println(" 1...");
                      delay(1000);
                      test();
            break;
            case 51 : Serial.print("Switching state pin 3 to low");
                      motPropulsionGauche.writeMicroseconds(MIN_PULSE_LENGTH);
                      motPropulsionDroit.writeMicroseconds(MIN_PULSE_LENGTH);
                      pinMode(pinInverseurGauche1, LOW);
                      
                      
            break;
            case 52 : Serial.print("Switching state to pin 3 to high");
                      motPropulsionGauche.writeMicroseconds(MIN_PULSE_LENGTH);
                      motPropulsionDroit.writeMicroseconds(MIN_PULSE_LENGTH);
                      pinMode(pinInverseurGauche1, HIGH);
                      
                                    
            break;
            case 53 : Serial.print("Switching state to pin 4 to low");
                      motPropulsionGauche.writeMicroseconds(MIN_PULSE_LENGTH);
                      motPropulsionDroit.writeMicroseconds(MIN_PULSE_LENGTH);
                      pinMode(pinInverseurGauche2, LOW);
                      
                                    
            break;
            case 54 : Serial.print("Switching state to pin 4 to high");
                      motPropulsionGauche.writeMicroseconds(MIN_PULSE_LENGTH);
                      motPropulsionDroit.writeMicroseconds(MIN_PULSE_LENGTH);
                      pinMode(pinInverseurGauche2, HIGH);
                      
                                    
            break;
            

            
        }
    }

    


 
 
}
