void DCMotor(int arriveeTele, int motorPin1, int motorPin2, int enablePin){


    if (Serial.available() > 0)
    {
      // Lecture de l'entier passé au port série 
      // ATTENTION il faut que ce soit une valeur entre -255 et 255
      

      //
      // Sens du mouvement
      //
      if (arriveeTele > 0) // avant
      {
        digitalWrite(motorPin1, HIGH); 
        digitalWrite(motorPin2, LOW);
        Serial.print("Avant ");
        Serial.println(arriveeTele);
      }
      else if (arriveeTele < 0) // arrière
      {
        digitalWrite(motorPin1, LOW); 
        digitalWrite(motorPin2, HIGH);
        Serial.print("Arriere ");
        Serial.println(arriveeTele);
      }
      else // Stop (freinage)
      {
        digitalWrite(motorPin1, HIGH); 
        digitalWrite(motorPin2, HIGH);
        Serial.println("Stop");
      }

      //
      // Vitesse du mouvement
      //
      analogWrite(enablePin, abs(arriveeTele));
    }
    delay(100); // a changer quand fera code entier
}
