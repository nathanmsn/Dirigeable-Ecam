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

  Serial.println(measureTelecommande()); 
 delay(1000);
}


int measureTelecommande(){
 
  int avg = 0;
  int cpt = 0;
  unsigned long init = millis();
  while(1){
    if ( (millis() - init) > 20 ) break;
    avg += analogRead(A0);
    cpt ++;
    
  }
return(avg/cpt);
  
}
