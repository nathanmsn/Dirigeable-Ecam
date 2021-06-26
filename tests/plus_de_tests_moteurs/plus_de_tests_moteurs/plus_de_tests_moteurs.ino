#include <Servo.h>
// ---------------------------------------------------------------------------
// Customize here pulse lengths as needed
#define MIN_PULSE_LENGTH 1000 // Minimum pulse length in µs
#define MAX_PULSE_LENGTH 2000 // Maximum pulse length in µs
// ---------------------------------------------------------------------------
Servo motA, motB, motC, motD;
char data;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    
  motA.attach(4, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
  motB.attach(5, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
  motC.attach(6, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
  motD.attach(7, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);

  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:
  motA.writeMicroseconds(MIN_PULSE_LENGTH);
  motB.writeMicroseconds(MIN_PULSE_LENGTH);
  motC.writeMicroseconds(MIN_PULSE_LENGTH);
  motD.writeMicroseconds(MIN_PULSE_LENGTH);

  delay(1000);

  motA.writeMicroseconds(MAX_PULSE_LENGTH);
  motB.writeMicroseconds(MAX_PULSE_LENGTH);
  motC.writeMicroseconds(MAX_PULSE_LENGTH);
  motD.writeMicroseconds(MAX_PULSE_LENGTH);

  for (int i = MIN_PULSE_LENGTH; i <= MAX_PULSE_LENGTH; i += 5) {
    Serial.print("Pulse length = ");
    Serial.println(i);
    
    motA.writeMicroseconds(i);
    motB.writeMicroseconds(i);
    motC.writeMicroseconds(i);
    motD.writeMicroseconds(i);
    
    delay(200);
  }

  Serial.println("STOP");
  motA.writeMicroseconds(MIN_PULSE_LENGTH);
  motB.writeMicroseconds(MIN_PULSE_LENGTH);
  motC.writeMicroseconds(MIN_PULSE_LENGTH);
  motD.writeMicroseconds(MIN_PULSE_LENGTH);

  delay(2000);
  

  

}
