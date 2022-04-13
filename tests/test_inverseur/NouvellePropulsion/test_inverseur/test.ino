  void test()
{
    for (int i = MIN_PULSE_LENGTH; i <= 1200; i += 4) {
        Serial.print("Pulse length = ");
        Serial.println(i);
        
        motPropulsionGauche.writeMicroseconds(i);
        motPropulsionDroit.writeMicroseconds(i);

        
        delay(200);
    }

    Serial.println("STOP");
    motPropulsionGauche.writeMicroseconds(MIN_PULSE_LENGTH);
    motPropulsionDroit.writeMicroseconds(MIN_PULSE_LENGTH);

}
