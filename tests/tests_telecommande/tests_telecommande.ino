
int tableauDistances[50];
int compteurMesures = 0;


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
  int Aa0 = analogRead(A0);
  int Aa1 = analogRead(A1);
  int Aa2 = analogRead(A2);
  int Aa3 = analogRead(A3);
  int Aa4 = analogRead(A4);
  int Aa5 = analogRead(A5);
/*
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
  Serial.println(A5);*/
  
  if(Aa4 != 0){
    tableauDistances[compteurMesures] = Aa4;
    compteurMesures++;
  }

  if(compteurMesures == 49){
    /*for(int j = 0; j <= 199; j++){
      for(int i = 0; i <= 199; i++){
        if(tableauDistances[i] >= tableauDistances[i + 1]){
          int tmp = tableauDistances[i];
          tableauDistances[i] = tableauDistances[i + 1];
          tableauDistances[i + 1] = tmp;
        }
      }
    }*/

    for(int i = 0; i <= 49; i++){
          Aa4 = Aa4 + tableauDistances[i];
      
      }
      Aa4 = Aa4/50;
    compteurMesures = 0;

    Serial.print("A4 ");
    Serial.println(Aa4);
    delay(300);
  }
  
  



}
