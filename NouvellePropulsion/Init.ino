void setup() 
{
  // put your setup code here, to run once:
   Serial.begin(9600);

  motPropulsionGauche.attach(6, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
  motPropulsionDroit.attach(4, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);

  
  motPropulsionGauche.write(MAX_PULSE_LENGTH);
  motPropulsionDroit.write(MAX_PULSE_LENGTH);

  
  motPropulsionGauche.write(MIN_PULSE_LENGTH);
  motPropulsionDroit.write(MIN_PULSE_LENGTH);
  
 
  servoInterieur.attach(22);
  servoDroit.attach(2);
  servoGauche.attach(3);

  pinMode(22,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);

}
