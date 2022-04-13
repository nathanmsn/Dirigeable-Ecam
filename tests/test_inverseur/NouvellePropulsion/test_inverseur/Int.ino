void setup() 
{
  // put your setup code here, to run once:
   Serial.begin(9600);

  motPropulsionGauche.attach(6, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
  motPropulsionDroit.attach(9, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);

  
  motPropulsionGauche.write(MAX_PULSE_LENGTH);
  motPropulsionDroit.write(MAX_PULSE_LENGTH);
  
  Serial.println("plug battery once beeping is done");
  delay(10000);
  
  motPropulsionGauche.write(MIN_PULSE_LENGTH);
  motPropulsionDroit.write(MIN_PULSE_LENGTH);
  
  delay(10000);
  


  pinMode(pinInverseurGauche1, OUTPUT);
  pinMode(pinInverseurGauche2, OUTPUT);
  pinMode(pinInverseurDroit1, OUTPUT);
  pinMode(pinInverseurDroit2, OUTPUT);

  
  pinMode(pinInverseurDroit1, HIGH);
  pinMode(pinInverseurGauche1, HIGH);
  pinMode(pinInverseurDroit2, HIGH);
  pinMode(pinInverseurGauche2, HIGH);

  displayInstructions();

}
