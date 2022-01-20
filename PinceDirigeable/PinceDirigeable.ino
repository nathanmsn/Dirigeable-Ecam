
/* Code écrit par Louis, Arthur et Nathan*/
//attention ne rien brancher sur les pins 20 et 21,elles sont utilisées pour le gyro


#include <Servo.h> //Ca marche pas à cause des timers 16 bits, prendre le B, penser à tester jsp pourquoi où à quoi ça sert le b mais ça compile
#include <avr/interrupt.h>
#include <Stepper.h> 
#include<Wire.h>
#include <math.h>


/*initialisation gyro*/
#define NumData 7
#define pi      3.1415926535897932384626433832795  
#define MPU     0x68

int  GyAccTemp[NumData];
int  GATCorr[NumData]={0,0,0,0,0,0,0};
//int  GATCorr[NumData]={-950,-300,0,-1600,480,170,210};

double PitchRoll[3];
int angleInitial;

/*début initialisation telecommande*/
int channels[6];
const int pinsTelecommande[6] = {8, 9, 10, 11, 12, 13};


//Pin output pince
const uint8_t servoPinOuvrir = 5; 

//intialisation du servo
//Servo servoOuvrir;


//initialisation du moteur pas à pas
const int stepsPerRevolution = 90;//au pif

Stepper stepDescendre(stepsPerRevolution, 10, 11, 12, 13);
Stepper stepTourner(stepsPerRevolution, 14, 15, 16, 17);
Stepper stepDecaler(stepsPerRevolution, 18, 19, 20, 21);

int nombreDeDemiToursDescendre = 0;
int nombreDeDemiToursTourner = 0;
int nombreDeDemiToursDecaler = 0;

const int nombreDeRevolutionEntreDeuxCremailliere = 10;//au pif, valeur à changer
const int nombreDeRevolutionDeLaTranslationPourPoser = 3;
boolean arreterLesActions = false; //pour arrêter la prise d'info supplémentaire quand le moteur fait déjà quelque chose

int placeARemplir = 0;



/*début initialisation propulsion*/

// Customize here pulse lengths as needed
#define MIN_PULSE_LENGTH 1000 // Minimum pulse length in µs
#define MAX_PULSE_LENGTH 2000 // Maximum pulse length in µs


/*début initialisation stabilisation*/
const int trigPin = 9; //set pin variables
const int echoPin = 10;

int trigState = LOW; //state of trigPin
int interval = 1; // interval in milliseconds at which trigPin turns on
unsigned long previousMillis = 0; //microsecond at which the pin was last writen
int distance = 0;
int tableauDistances[4];
int compteurMesures = 0;

const uint8_t distanceIdeale = 220;
int intensiteMoteursStabilisation = 0;

Servo motStabilisationAvantDroit, motStabilisationAvantGauche, motStabilisationArriereDroit, motStabilisationArriereGauche, motPropulsionGauche, motPropulsionDroit, motEtraveDroit, motEtraveGauche;


void setup() {

  Serial.println("c'est lancé");

  Serial.begin(9600);
  motStabilisationAvantDroit.attach(4, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
  motStabilisationAvantGauche.attach(3, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
  motStabilisationArriereDroit.attach(5, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
  motStabilisationArriereGauche.attach(2, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
  motPropulsionGauche.attach(7, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
  motPropulsionDroit.attach(6, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
  motEtraveDroit.attach(12, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
  motEtraveGauche.attach(11, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);

  Serial.println("ça commence dans 2 secondes");
  delay(2000);
  
  
  motStabilisationAvantDroit.writeMicroseconds(MAX_PULSE_LENGTH);
  motStabilisationAvantGauche.writeMicroseconds(MAX_PULSE_LENGTH);
  motStabilisationArriereDroit.writeMicroseconds(MAX_PULSE_LENGTH);
  motStabilisationArriereGauche.writeMicroseconds(MAX_PULSE_LENGTH);
  motPropulsionGauche.writeMicroseconds(MAX_PULSE_LENGTH);
  motPropulsionDroit.writeMicroseconds(MAX_PULSE_LENGTH);
  motEtraveDroit.writeMicroseconds(MAX_PULSE_LENGTH);
  motEtraveGauche.writeMicroseconds(MAX_PULSE_LENGTH);
  
  Serial.println("brancher dans les 10 secondes");
  delay(10000);
  Serial.println("encore 15 secondes");
  delay(15000);

  motStabilisationAvantDroit.writeMicroseconds(MIN_PULSE_LENGTH);
  motStabilisationAvantGauche.writeMicroseconds(MIN_PULSE_LENGTH);
  motStabilisationArriereDroit.writeMicroseconds(MIN_PULSE_LENGTH);
  motStabilisationArriereGauche.writeMicroseconds(MIN_PULSE_LENGTH);
  motPropulsionGauche.writeMicroseconds(MIN_PULSE_LENGTH);
  motPropulsionDroit.writeMicroseconds(MIN_PULSE_LENGTH);
  motEtraveDroit.writeMicroseconds(MIN_PULSE_LENGTH);
  motEtraveGauche.writeMicroseconds(MIN_PULSE_LENGTH);

  
  Serial.println("ça démarre dans 15 secondes");
  delay(15000);
  
  //servoOuvrir.attach(servoPinOuvrir);

 

  pinMode(trigPin,OUTPUT); //set pinmodes
  pinMode(echoPin,INPUT);

  //Init module GY-512 
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  


  sei();//allow interrupts
  
  stepDescendre.setSpeed(5); //vitesse de 60 rpm, jsp pas trop pourquoi il faut mettre 5 mais bon on a pas mieux
  stepTourner.setSpeed(5);
  stepDecaler.setSpeed(5);
  
  ReadGY521(GyAccTemp, GATCorr);
  ComputeAngle(GyAccTemp, PitchRoll);

  angleInitial = PitchRoll[0];

}

void loop() {


  measureTelecommande();
  for(int i = 0; i <= 5; i++){
    Serial.print(pinsTelecommande[i]);
    Serial.print(" : ");
    Serial.println(channels[i]); 
  }
  Serial.println(" ");

  

  
   /* ouvrirPince();
    nombreDeDemiToursDescendre = bougerMoteurPasAPas(descendre, 10, 11, 12, 13, nombreDeDemiToursDescendre);
    nombreDeDemiToursTourner = bougerMoteurPasAPas(tourner, 14, 15, 16, 17, nombreDeDemiToursTourner);
    nombreDeDemiToursDecaler = bougerMoteurPasAPas(decaler, 18, 19, 20, 21, nombreDeDemiToursDecaler);*/
  
  if(channels[2] < 40){
    if(channels[3] >= 55){//decaler à droite
      motPropulsionGauche.writeMicroseconds(MIN_PULSE_LENGTH);
      motPropulsionDroit.writeMicroseconds(MIN_PULSE_LENGTH);
      motEtraveDroit.writeMicroseconds(MIN_PULSE_LENGTH);
      motEtraveGauche.writeMicroseconds(MIN_PULSE_LENGTH + 500);
      
    }
    else if(channels[3] >= 40 && channels[3] < 55){ //arret complet
      motPropulsionGauche.writeMicroseconds(MIN_PULSE_LENGTH);
      motPropulsionDroit.writeMicroseconds(MIN_PULSE_LENGTH);
      motEtraveDroit.writeMicroseconds(MIN_PULSE_LENGTH);
      motEtraveGauche.writeMicroseconds(MIN_PULSE_LENGTH);
      
    }
    else if(channels[3] < 40){//decaler à gauche
      motPropulsionGauche.writeMicroseconds(MIN_PULSE_LENGTH);
      motPropulsionDroit.writeMicroseconds(MIN_PULSE_LENGTH);
      motEtraveDroit.writeMicroseconds(MIN_PULSE_LENGTH + 500);
      motEtraveGauche.writeMicroseconds(MIN_PULSE_LENGTH);
          
    }
      
  }
  else if(channels[2] >= 40 && channels[3] < 60){//vitesse moyenne
    if(channels[3] >= 55){//vers la droite
      motPropulsionGauche.writeMicroseconds(MIN_PULSE_LENGTH + 500);
      motPropulsionDroit.writeMicroseconds(MIN_PULSE_LENGTH + 200);
      motEtraveDroit.writeMicroseconds(MIN_PULSE_LENGTH);
      motEtraveGauche.writeMicroseconds(MIN_PULSE_LENGTH);
      
    }
    else if(channels[3] >= 40 && channels[3] < 60){//tout droit
      motPropulsionGauche.writeMicroseconds(MIN_PULSE_LENGTH + 400);
      motPropulsionDroit.writeMicroseconds(MIN_PULSE_LENGTH + 400);
      motEtraveDroit.writeMicroseconds(MIN_PULSE_LENGTH);
      motEtraveGauche.writeMicroseconds(MIN_PULSE_LENGTH);
      
    }
    else if(channels[3] < 40){//vers la gauche
      motPropulsionGauche.writeMicroseconds(MIN_PULSE_LENGTH + 200);
      motPropulsionDroit.writeMicroseconds(MIN_PULSE_LENGTH + 500);
      motEtraveDroit.writeMicroseconds(MIN_PULSE_LENGTH);
      motEtraveGauche.writeMicroseconds(MIN_PULSE_LENGTH);
    }
      
  }
    
  else if(channels[2] >= 60){
    if(channels[3] >= 60){//vers la droite
      motPropulsionGauche.writeMicroseconds(MIN_PULSE_LENGTH + 900);
      motPropulsionDroit.writeMicroseconds(MIN_PULSE_LENGTH + 600);
      motEtraveDroit.writeMicroseconds(MIN_PULSE_LENGTH);
      motEtraveGauche.writeMicroseconds(MIN_PULSE_LENGTH);
    }
    else if(channels[3] >= 40 && channels[3] < 60){
      motPropulsionGauche.writeMicroseconds(MIN_PULSE_LENGTH + 800);
      motPropulsionDroit.writeMicroseconds(MIN_PULSE_LENGTH + 800);
      motEtraveDroit.writeMicroseconds(MIN_PULSE_LENGTH);
      motEtraveGauche.writeMicroseconds(MIN_PULSE_LENGTH);
    }
    else if(channels[3] < 40){
      motPropulsionGauche.writeMicroseconds(MIN_PULSE_LENGTH + 600);
      motPropulsionDroit.writeMicroseconds(MIN_PULSE_LENGTH + 900);
      motEtraveDroit.writeMicroseconds(MIN_PULSE_LENGTH);
      motEtraveGauche.writeMicroseconds(MIN_PULSE_LENGTH);
    }

  }   


  int  intensiteMoteursStabilisation = 0;
 
  int test = distanceToGround();//pour enlever les mesures qui font 0
  if(test != 0){
    distance = test;
    tableauDistances[compteurMesures] = distance;
    compteurMesures++;
  }

  if(compteurMesures == 4){
    for(int j = 0; j <= 3; j++){
      for(int i = 0; i <= 3; i++){
        if(tableauDistances[i] >= tableauDistances[i + 1]){
          int tmp = tableauDistances[i];
          tableauDistances[i] = tableauDistances[i + 1];
          tableauDistances[i + 1] = tmp;
        }
      }
    }
    compteurMesures = 0;
  }
 
  Serial.print(distance);
  Serial.println(" cm");
  
  if(tableauDistances[2] >= distanceIdeale + 10){//on prends la médiane
    intensiteMoteursStabilisation = intensiteMoteursStabilisation - 100;
  }
  else if(tableauDistances[2] <= distanceIdeale - 10){
    intensiteMoteursStabilisation += 100;
    if(tableauDistances[2] <= distanceIdeale - 20){
      intensiteMoteursStabilisation += 100;
      if(tableauDistances[2] <= distanceIdeale - 30){
        intensiteMoteursStabilisation += 100;
      }
    }
  }

  int  intensiteMoteur1 = intensiteMoteursStabilisation;
  int  intensiteMoteur2 = intensiteMoteursStabilisation;
  int  intensiteMoteur3 = intensiteMoteursStabilisation;
  int  intensiteMoteur4 = intensiteMoteursStabilisation;
  
  ReadGY521(GyAccTemp, GATCorr);
  ComputeAngle(GyAccTemp, PitchRoll);
  Serial.print(PitchRoll[0]);
  Serial.println("°");
  Serial.print(PitchRoll[1]);
  Serial.println("°");
  
  
  if(PitchRoll[0] <= angleInitial + 7){//si il penche un peu à l'arrière
    intensiteMoteur1 = intensiteMoteur1 - 100;
    intensiteMoteur2 = intensiteMoteur2 - 100;
    intensiteMoteur3 = intensiteMoteur3 + 100;
    intensiteMoteur4 = intensiteMoteur4 + 100;
    if(PitchRoll[0] <= angleInitial + 15){//si ça penche beaucoup
      intensiteMoteur1 = intensiteMoteur1 - 100;
      intensiteMoteur2 = intensiteMoteur2 - 100;
      intensiteMoteur3 = intensiteMoteur3 + 100;
      intensiteMoteur4 = intensiteMoteur4 + 100;
    
    }
  }
  else if(PitchRoll[0] >= angleInitial - 7){
    intensiteMoteur1 = intensiteMoteur1 + 100;
    intensiteMoteur2 = intensiteMoteur2 + 100;
    intensiteMoteur3 = intensiteMoteur3 - 100;
    intensiteMoteur4 = intensiteMoteur4 - 100;
    if(PitchRoll[0] >= angleInitial - 15){
      intensiteMoteur1 = intensiteMoteur1 + 100;
      intensiteMoteur2 = intensiteMoteur2 + 100;
      intensiteMoteur3 = intensiteMoteur3 - 100;
      intensiteMoteur4 = intensiteMoteur4 - 100;
    }
  }

  
  if(PitchRoll[1] <= angleInitial + 7){//si il penche un peu à droite
    intensiteMoteur1 = intensiteMoteur1 + 100;
    intensiteMoteur2 = intensiteMoteur2 - 100;
    intensiteMoteur3 = intensiteMoteur3 + 100;
    intensiteMoteur4 = intensiteMoteur4 - 100;
    if(PitchRoll[1] <= angleInitial + 15){//si ça penche beaucoup
      intensiteMoteur1 = intensiteMoteur1 + 100;
      intensiteMoteur2 = intensiteMoteur2 - 100;
      intensiteMoteur3 = intensiteMoteur3 + 100;
      intensiteMoteur4 = intensiteMoteur4 - 100;
    
    }
  }
  else if(PitchRoll[1] >= angleInitial - 7){// a gauche
    intensiteMoteur1 = intensiteMoteur1 - 100;
    intensiteMoteur2 = intensiteMoteur2 + 100;
    intensiteMoteur3 = intensiteMoteur3 - 100;
    intensiteMoteur4 = intensiteMoteur4 + 100;
    if(PitchRoll[1] >= angleInitial - 15){
      intensiteMoteur1 = intensiteMoteur1 - 100;
      intensiteMoteur2 = intensiteMoteur2 + 100;
      intensiteMoteur3 = intensiteMoteur3 - 100;
      intensiteMoteur4 = intensiteMoteur4 + 100;
    }
  }

  motStabilisationAvantDroit.writeMicroseconds(MIN_PULSE_LENGTH + intensiteMoteur1);
  motStabilisationAvantGauche.writeMicroseconds(MIN_PULSE_LENGTH + intensiteMoteur2);
  motStabilisationArriereDroit.writeMicroseconds(MIN_PULSE_LENGTH + intensiteMoteur3);
  motStabilisationArriereGauche.writeMicroseconds(MIN_PULSE_LENGTH + intensiteMoteur4);


}







//penser à faire des essaies sur les voltages en input

int bougerMoteurPasAPas(float mesure, int pin1, int pin2, int pin3, int pin4, int nombreDeDemiTours){
  Stepper thisStep(stepsPerRevolution, pin1, pin2, pin3, pin4);
  thisStep.setSpeed(5);
   
  if(mesure <= 2.5 && mesure != 0){
      thisStep.step(stepsPerRevolution/2); //fait un demi tour de moteur d vers le bas
      nombreDeDemiTours++;      
  }
  else{
      thisStep.step(-stepsPerRevolution/2); //va vers le haut
      nombreDeDemiTours--;  
  }
    return nombreDeDemiTours; 
}


void ouvrirPince(){
 

}

void remonterEtDeposer(){
  stepDecaler.step(nombreDeDemiToursDecaler*stepsPerRevolution/2);
  nombreDeDemiToursDecaler = 0;
  stepTourner.step(nombreDeDemiToursTourner*stepsPerRevolution/2); 
  nombreDeDemiToursTourner = 0;
  stepDescendre.step(nombreDeDemiToursDescendre*stepsPerRevolution/2-placeARemplir*nombreDeRevolutionEntreDeuxCremailliere*stepsPerRevolution);
  nombreDeDemiToursDescendre = nombreDeRevolutionEntreDeuxCremailliere*placeARemplir/2;
  //servoOuvrir.write(0);  //jsp si ça sera vraiment 0 pour l'ouvrir
  placeARemplir++;
}



int distanceToGround(){
  unsigned long currentMillis = millis(); //time in milliseconds from which the code was started
  if (currentMillis-previousMillis >= interval) { //check "blink without delay" code
    previousMillis = currentMillis;
    if (trigState == LOW){
      (trigState = HIGH);
    }
    else {
      (trigState = LOW);
    }
  }
 
  digitalWrite(trigPin,trigState);
  int duration, distance; //variables
  duration = pulseIn(echoPin,HIGH);
  distance = (duration/2) / 29.1;
  return distance;
}


//pour le gyro
void ReadGY521( int *GyAccTempp, int *GATCorrr)
{
  // Init du module GY-521
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,14,true);

  // Lecture des données (3 axes accéléromètre + température + 3 axes gyroscope
  for  (int i=0;i<NumData;i++)
  {
    if(i!=3)
    {
      GyAccTempp[i]=(Wire.read()<<8|Wire.read()) + GATCorrr[i];
    }
    else
    {
      GyAccTempp[i]=(Wire.read()<<8|Wire.read()) + GATCorrr[i];
      GyAccTempp[i] = GyAccTempp[i]/340 + 36.53;
    }
  }
}

//Conversion des données accéléromètre en pitch/roll/yaw
void ComputeAngle(int *GyAccTempp,  double *PitchRol)
{
  double x = GyAccTempp[0];
  double y = GyAccTempp[1];
  double z = GyAccTempp[2];

  PitchRol[0] = atan(x/sqrt((y*y) + (z*z))); //  pitch 
  PitchRol[1] = atan(y/sqrt((x*x) + (z*z))); // roll
  PitchRol[2] = atan(z/sqrt((x*x) + (y*y))); // pitch
  
  //Conversion Radian en degré
  PitchRol[0] = PitchRol[0] * (180.0/pi);
  PitchRol[1] = PitchRol[1] * (180.0/pi) ;
  PitchRol[2] = PitchRol[2] * (180.0/pi) ;
}

void measureTelecommande(){
  int avg[6] = {0, 0, 0, 0, 0, 0};
  int cpt[6] = {0, 0, 0, 0, 0, 0};

  for(int i = 0; i <= 5; i++){
    channels[i] = pulseIn(pinsTelecommande,i, 50000);
    
  }


  
}
