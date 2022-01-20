void setup() {
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT); //set pinmodes
  pinMode(echoPin,INPUT);


  //Init module GY-512 
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  pinMode(30, OUTPUT);
  
  motStabilisationAvantDroit.attach(4, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
  motStabilisationAvantGauche.attach(3, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
  motStabilisationArriereDroit.attach(5, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
  motStabilisationArriereGauche.attach(2, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
  
  motStabilisationAvantDroit.write(MAX_PULSE_LENGTH);
  motStabilisationAvantGauche.write(MAX_PULSE_LENGTH);
  motStabilisationArriereDroit.write(MAX_PULSE_LENGTH);
  motStabilisationArriereGauche.write(MAX_PULSE_LENGTH); 
  delay(20000);
  motStabilisationAvantDroit.write(MIN_PULSE_LENGTH);
  motStabilisationAvantGauche.write(MIN_PULSE_LENGTH);
  motStabilisationArriereDroit.write(MIN_PULSE_LENGTH);
  motStabilisationArriereGauche.write(MIN_PULSE_LENGTH); 
  delay(10000);
  
  servoAvantGauche.attach(8);
  servoAvantDroit.attach(13);
  servoArriereGauche.attach(11);
  servoArriereDroit.attach(12);

  pinMode(6, INPUT);
  pinMode(7, INPUT);

  ReadGY521(GyAccTemp, GATCorr);
  ComputeAngle(GyAccTemp, PitchRoll);

  pitchInitial = PitchRoll[0];
  rollInitial = PitchRoll[1];
}
