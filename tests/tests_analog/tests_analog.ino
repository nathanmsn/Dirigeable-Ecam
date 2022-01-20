
int pinOut = 2;
int pinIn = 8;
long cpt = 0;
int lecture_old = 0;
int start[6] = {A1, A0, A2, A3, A4, A5};
int alpha[6] = {0, 0, 0, 0, 0, 0};


unsigned long time_old = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(pinOut, OUTPUT);
  analogWrite(pinOut, 111);
  for(int i = 8; i <=13; i++){
    pinMode(i, INPUT);
  }
  Serial.begin(9600);

}

void loop() {
  /*// put your main code here, to run repeatedly:
  if( micros() - time_old >= 80){
    int lecture = PINB;
    
    //  Serial.println(lecture,BIN);
      
    time_old = micros();
    if(lecture_old != lecture){
     
      for(int i = 0; i <= 7; i++){
        bool etat_old = lecture_old & (1 << i);
        bool etat = lecture & (1 << i);
        if(etat_old == 0 && etat == 1){
          start[i] = micros(); Serial.println(lecture_old);
        }
        if(etat_old == 1 && etat == 0){
          float tmp = float(micros() - start[i])/20.0f - 50.0f;
          alpha[i] = byte(tmp)*5;
          if(i = 0){
            Serial.println(alpha[i]);
          }
        }
      }
      lecture_old = lecture;
    }
  }*/
  for(int i =0; i <= 5; i++){
    alpha[i] = pulseIn(8+i, HIGH, 50000) - 1000;
    //Serial.print(alpha[i]);
   // Serial.print(" ");
  }
  Serial.print(alpha[1]);
  Serial.print(" ");
  Serial.println(map(alpha[1], 500, 1000, 0, 100));

  Serial.println();
  delay(1000);
 

}
