



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);


}

void loop() {
  int A0 = analogRead(A0);
  int A1 = analogRead(A1);
  int A2 = analogRead(A2);
  int A3 = analogRead(A3);
  int A4 = analogRead(A4);
  int A5 = analogRead(A5);

  Serial.print("A0 ");
  Serial.println(A0);
  Serial.print("A1 ");
  Serial.println(A1);
  Serial.print("A2 ");
  Serial.println(A2);
  Serial.print("A3 ");
  Serial.println(A3);
  Serial.print("A4 ");
  Serial.println(A4);
  Serial.print("A5 ");
  Serial.println(A5);
  delay(1000);
  

}
