
int moteur1 = 2;
int moteur2 = 3;
int moteur3 = 4;
int moteur4 = 5;



void setup(){

  Serial.begin(9600);

  pinMode(moteur1, OUTPUT);
  pinMode(moteur2, OUTPUT);
  pinMode(moteur3, OUTPUT);
  pinMode(moteur3, OUTPUT);

  
}

void loop() {
  /*// put your main code here, to run repeatedly:
  analogWrite(moteur1, 0);
  analogWrite(moteur2, 0);
  analogWrite(moteur3, 0);
  analogWrite(moteur4, 0);

  Serial.println("ça marche1");

  delay(500);
  
  analogWrite(moteur1, 100);
  analogWrite(moteur2, 100);
  analogWrite(moteur3, 100);
  analogWrite(moteur4, 100);

  Serial.println("ça marche2");

  delay(500);

  analogWrite(moteur1, 255);
  analogWrite(moteur2, 255);
  analogWrite(moteur3, 255);
  analogWrite(moteur4, 255);

  Serial.println("ça marche3");

  analogWrite(moteur1, 511);
  analogWrite(moteur2, 511);
  analogWrite(moteur3, 511);
  analogWrite(moteur4, 511);

  Serial.println("ça marche4");

  delay(500);
  
  analogWrite(moteur1, 1023);
  analogWrite(moteur2, 1023);
  analogWrite(moteur3, 1023);
  analogWrite(moteur4, 1023);

  Serial.println("ça marche5");

  delay(500);
*/


  digitalWrite(moteur1, HIGH);
  digitalWrite(moteur2, HIGH);
  digitalWrite(moteur3, HIGH);
  digitalWrite(moteur4, HIGH);
  
  Serial.println("ça marche1");

  delay(500);
  
  digitalWrite(moteur1, HIGH);
  digitalWrite(moteur2, LOW);
  digitalWrite(moteur3, HIGH);
  digitalWrite(moteur4, HIGH);
 
  Serial.println("ça marche2");

  delay(500);

  digitalWrite(moteur1, LOW);
  digitalWrite(moteur2, HIGH);
  digitalWrite(moteur3, HIGH);
  digitalWrite(moteur4, HIGH);
  
 
  Serial.println("ça marche3");

  digitalWrite(moteur1, LOW);
  digitalWrite(moteur2, LOW);
  digitalWrite(moteur3, HIGH);
  digitalWrite(moteur4, HIGH);
  
 
  Serial.println("ça marche4");
  digitalWrite(moteur1, HIGH);
  digitalWrite(moteur2, HIGH);
  digitalWrite(moteur3, LOW);
  digitalWrite(moteur4, HIGH);
  
  Serial.println("ça marche1");

  delay(500);
  
  digitalWrite(moteur1, HIGH);
  digitalWrite(moteur2, HIGH);
  digitalWrite(moteur3, LOW);
  digitalWrite(moteur4, LOW);
 
  Serial.println("ça marche2");

  delay(500);

  digitalWrite(moteur1, LOW);
  digitalWrite(moteur2, HIGH);
  digitalWrite(moteur3, HIGH);
  digitalWrite(moteur4, HIGH);
  
 
  Serial.println("ça marche3");

  digitalWrite(moteur1, LOW);
  digitalWrite(moteur2, LOW);
  digitalWrite(moteur3, HIGH);
  digitalWrite(moteur4, HIGH);
  
 
  Serial.println("ça marche4");

 
  

  

  delay(2000);
  


}
