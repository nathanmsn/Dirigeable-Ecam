
int moteur1 = 2;
int moteur2 = 3;
int moteur3 = 4;
int moteur4 = 5;



void setup(){
  pinMode(moteur1, OUTPUT);
  pinMode(moteur2, OUTPUT);
  pinMode(moteur3, OUTPUT);
  pinMode(moteur3, OUTPUT);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(moteur1, 0);
  analogWrite(moteur2, 0);
  analogWrite(moteur3, 0);
  analogWrite(moteur4, 0);


}
