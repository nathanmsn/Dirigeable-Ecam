#include <Servo.h>
// ---------------------------------------------------------------------------
// Customize here pulse lengths as needed
#define MIN_PULSE_LENGTH 1000 // Minimum pulse length in µs
#define MAX_PULSE_LENGTH 2000 // Maximum pulse length in µs
// ---------------------------------------------------------------------------
Servo motStabilisationAvantDroit, motStabilisationAvantGauche, motStabilisationArriereDroit, motStabilisationArriereGauche, motPropulsionGauche, motPropulsionDroit, motEtraveDroit, motEtraveGauche;
char data;


void setup() {
    Serial.begin(9600);
    
    motStabilisationAvantDroit.attach(2, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
    motStabilisationAvantGauche.attach(3, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
    motStabilisationArriereDroit.attach(4, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
    motStabilisationArriereGauche.attach(5, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
    motPropulsionGauche.attach(6, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
    motPropulsionDroit.attach(7, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
    motEtraveDroit.attach(11, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
    motEtraveGauche.attach(12, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);

    Serial.println("ça commence dans 2 secondes");
    delay(2000);
    
    
    motStabilisationAvantDroit.writeMicroseconds(MAX_PULSE_LENGTH);
    motStabilisationAvantGauche.writeMicroseconds(MAX_PULSE_LENGTH);
    motStabilisationArriereDroit.writeMicroseconds(MAX_PULSE_LENGTH);
    motStabilisationArriereGauche.writeMicroseconds(MAX_PULSE_LENGTH);
    motPropulsionGauche.writeMicroseconds(MAX_PULSE_LENGTH);
    motPropulsionDroit.writeMicroseconds(MAX_PULSE_LENGTH);
    motEtraveDroit.writeMicroseconds(MAX_PULSE_LENGTH);
    motEtraveGauche.writeMicroseconds(MAX_PULSE_LENGTH);
    
    Serial.println("brancher dans les 10 secondes");
    delay(10000);
    Serial.println("encore 15 secondes");
    delay(15000);

    motStabilisationAvantDroit.writeMicroseconds(MIN_PULSE_LENGTH);
    motStabilisationAvantGauche.writeMicroseconds(MIN_PULSE_LENGTH);
    motStabilisationArriereDroit.writeMicroseconds(MIN_PULSE_LENGTH);
    motStabilisationArriereGauche.writeMicroseconds(MIN_PULSE_LENGTH);
    motPropulsionGauche.writeMicroseconds(MIN_PULSE_LENGTH);
    motPropulsionDroit.writeMicroseconds(MIN_PULSE_LENGTH);
    motEtraveDroit.writeMicroseconds(MIN_PULSE_LENGTH);
    motEtraveGauche.writeMicroseconds(MIN_PULSE_LENGTH);

    
    Serial.println("ça démarre dans 15 secondes");
    delay(15000);

}

void loop() {
  

  for (int i = MIN_PULSE_LENGTH; i <= MAX_PULSE_LENGTH - 800; i += 2) {
    Serial.print("Pulse length = ");
    Serial.println(i);
    
    motStabilisationAvantDroit.writeMicroseconds(i);
    motStabilisationAvantGauche.writeMicroseconds(i);
    motStabilisationArriereDroit.writeMicroseconds(i);
    motStabilisationArriereGauche.writeMicroseconds(i);
    motPropulsionGauche.writeMicroseconds(i);
    motPropulsionDroit.writeMicroseconds(i);
    motEtraveDroit.writeMicroseconds(i);
    motEtraveGauche.writeMicroseconds(i);
    
    delay(200);
  }

  Serial.println("STOP");
  motStabilisationAvantDroit.writeMicroseconds(MIN_PULSE_LENGTH);
  motStabilisationAvantGauche.writeMicroseconds(MIN_PULSE_LENGTH);
  motStabilisationArriereDroit.writeMicroseconds(MIN_PULSE_LENGTH);
  motStabilisationArriereGauche.writeMicroseconds(MIN_PULSE_LENGTH);
  motPropulsionGauche.writeMicroseconds(MIN_PULSE_LENGTH);
  motPropulsionDroit.writeMicroseconds(MIN_PULSE_LENGTH);
  motEtraveDroit.writeMicroseconds(MIN_PULSE_LENGTH);
  motEtraveGauche.writeMicroseconds(MIN_PULSE_LENGTH);

  delay(2000);
  

  

}
