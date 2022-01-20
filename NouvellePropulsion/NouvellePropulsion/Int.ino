void setup() 
{
  // put your setup code here, to run once:
   Serial.begin(9600);

  motPropulsionGauche.attach(8, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
  motPropulsionDroit.attach(9, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);

  
  motPropulsionGauche.write(MAX_PULSE_LENGTH);
  motPropulsionDroit.write(MAX_PULSE_LENGTH);
  

  delay(20000);
  
  motPropulsionGauche.write(MIN_PULSE_LENGTH);
  motPropulsionDroit.write(MIN_PULSE_LENGTH);
  
  delay(10000);
  
  servoDroit.attach(6);
  servoGauche.attach(7);

  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);

}
