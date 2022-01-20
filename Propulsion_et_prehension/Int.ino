void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);

  motPropulsionVersArriere1.attach(8, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
  motPropulsionVersArriere2.attach(9, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
  
  motPropulsionVersAvant1.attach(10, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
  motPropulsionVersAvant2.attach(11, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);

  

  
  motPropulsionVersArriere1.write(MAX_PULSE_LENGTH);
  motPropulsionVersArriere2.write(MAX_PULSE_LENGTH);
  
  motPropulsionVersAvant1.write(MAX_PULSE_LENGTH);
  motPropulsionVersAvant2.write(MAX_PULSE_LENGTH);
  delay(20000);
  
  motPropulsionVersArriere1.write(MIN_PULSE_LENGTH);
  motPropulsionVersArriere2.write(MIN_PULSE_LENGTH);
  
  motPropulsionVersAvant1.write(MIN_PULSE_LENGTH);
  motPropulsionVersAvant2.write(MIN_PULSE_LENGTH);
  delay(10000);
  
  servoTourner.attach(6);
  servoPince.attach(7);
  stepDescendre.setSpeed(5);
  stepDecaler.setSpeed(5);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
}
