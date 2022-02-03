void setup() 
{
  // put your setup code here, to run once:
   Serial.begin(9600);

  motPropulsionGauche.attach(6, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
  motPropulsionDroit.attach(4, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);

  
  motPropulsionGauche.write(MAX_PULSE_LENGTH);
  motPropulsionDroit.write(MAX_PULSE_LENGTH);
  

  //delay(20000);
  
  motPropulsionGauche.write(MIN_PULSE_LENGTH);
  motPropulsionDroit.write(MIN_PULSE_LENGTH);
  
  //delay(10000);
  
  servoDroit.attach(4);
  servoGauche.attach(5);
  
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);


}
