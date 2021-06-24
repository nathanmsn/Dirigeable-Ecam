int channel1;
int channel2;
int channel3;
int channel4;
int channel5;
int channel6;
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
 /*Serial.println(channel1);
 Serial.println(channel2);
 Serial.println(channel3);
 Serial.println(channel4);
 Serial.println(channel5);
 Serial.println(channel6);*/
 Serial.println(" ");
 delay(3000);
}


void measureTelecommande(){
  int avg[6] = {0, 0, 0, 0, 0, 0};
  int cpt = 0;
 /* int avg1 = 0;
  int avg2 = 0;
  int avg3 = 0;
  int avg4 = 0;
  int avg5 = 0;
  int avg6 = 0;
  int cpt1 = 0;
  int cpt2 = 0;
  int cpt3 = 0;
  int cpt4 = 0;
  int cpt5 = 0;
  int cpt6 = 0;*/
  
  unsigned long init = millis();
  while(1){
    if ( (millis() - init) > 19.3 ) break;
    /*avg1 += analogRead(A1);
    cpt1 ++;
    avg2 += analogRead(A0);
    cpt2 ++;
    avg3 += analogRead(A2);
    cpt3 ++;
    avg4 += analogRead(A3);
    cpt4 ++;
    avg5 += analogRead(A4);
    cpt5 ++;
    avg6 += analogRead(A5);
    cpt6 ++;*/
    for(int i = 0; i <= 1; i++){
      avg[i] += analogRead(pinsTelecommande[i]);
    }
    cpt++;
    
    
  }
 for(int i = 0; i <= 1; i++){
  channels[i] = avg[i]/cpt;
 }
 /* channel1 = avg1/cpt1;
  channel2 = avg2/cpt2;
  channel3 = avg3/cpt3;
  channel4 = avg4/cpt4;
  channel5 = avg5/cpt5;
  channel6 = avg6/cpt6;*/
  
}
