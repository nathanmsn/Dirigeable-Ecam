unsigned long timer1 = 0;
unsigned long timer2 = 0;
unsigned long duty = 0;

void setup() {
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(2), changing_on_two, CHANGE);
}

void rising_on_two(){
  if (micros()>timer1+1000) timer1 = micros();
}

void falling_on_two(){
  if (micros()>timer2+1000) timer2 = micros();
}

void changing_on_two(){
  if (micros()>timer1+100){ 
    unsigned long now = micros();
    duty = timer1 - now;
    timer1 = micros();
  }
  
}

void loop() {
  Serial.println(timer1);
  Serial.println(timer2);
  Serial.println(duty);
  delay(500);
}
