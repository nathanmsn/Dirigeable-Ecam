
int channels[6];
const int pinsTelecommande[6] = {A1, A0, A2, A3, A4, A5};

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
  measureTelecommande();
 for(int i = 0; i <= 5; i++){
  Serial.print(pinsTelecommande[i]);
  Serial.print(" : ");
  Serial.println(channels[i]); 

 }
 Serial.println(" ");
 delay(3000);
}


void measureTelecommande(){
  int avg[6] = {0, 0, 0, 0, 0, 0};
  int cpt = 0;

  
  unsigned long init = millis();
  while(1){
    if ( (millis() - init) > 19.3 ) break;
    for(int i = 0; i <= 1; i++){
      avg[i] += analogRead(pinsTelecommande[i]);
    }
    cpt++;
    
    
  }
 for(int i = 0; i <= 1; i++){
  channels[i] = avg[i]/cpt;
 }
  
}
