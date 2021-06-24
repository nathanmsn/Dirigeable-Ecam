
/* Code écrit par Louis, Arthur et Nathan*/
//attention ne rien brancher sur les pins 20 et 21,elles sont utilisées pour le gyro


//#include <Servo.h> //Ca marche pas à cause des timers 16 bits, prendre le B, penser à tester jsp pourquoi où à quoi ça sert le b mais ça compile
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

/*début initialisation pince*/

//Pin input pince
const uint8_t pinOuvrir = A1;
const uint8_t pinDescendre = A2;
const uint8_t pinTourner = A3;
const uint8_t pinDecaler = A4;

//Pin input propulsion
const uint8_t pinArret=A5;
const uint8_t pinDemarrer=A6;
const uint8_t pinRalentir=A7;
const uint8_t pinAccelerer=A9;
const uint8_t pinGauche=A10;
const uint8_t pinDroite=A11;

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

float ouvrir;
float descendre;
float tourner;
float decaler;

/*début initialisation propulsion*/
boolean arreter;
boolean accelerer;
boolean ralentir;
boolean demarrer;
boolean gauche;
boolean droite; 
int Power = 80;

const uint8_t pinMoteur1=3;
const uint8_t pinMoteur2=7;


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
int intensiteMoteurs = 0;


void setup() {

  Serial.println("c'est lancé");

  Serial.begin(9600);

  pinMode(pinOuvrir, INPUT);
  pinMode(pinDescendre, INPUT);
  pinMode(pinTourner, INPUT);
  pinMode(pinDecaler, INPUT);
  
  //servoOuvrir.attach(servoPinOuvrir);


  //pour la propulsion 
  pinMode(pinMoteur1,OUTPUT);
  pinMode(pinMoteur2,OUTPUT);
  pinMode(pinGauche,INPUT);
  pinMode(pinDroite,INPUT);
  pinMode(pinDemarrer,INPUT);
  pinMode(pinArret,INPUT);
  pinMode(pinRalentir,INPUT);
  pinMode(pinAccelerer,INPUT);

  pinMode(trigPin,OUTPUT); //set pinmodes
  pinMode(echoPin,INPUT);

  //Init module GY-512 
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);


  
   
 //set timer4 interrupt at 1Hz
 TCCR4A = 0;// set entire TCCR1A register to 0
 TCCR4B = 0;// same for TCCR1B
 TCNT4  = 0;//initialize counter value to 0
 // set compare match register for 1hz increments
 OCR4A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
 // turn on CTC mode
 TCCR4B |= (1 << WGM12);
 // Set CS12 and CS10 bits for 1024 prescaler
 TCCR4B |= (1 << CS12) | (1 << CS10);  
 // enable timer compare interrupt
 TIMSK4 |= (1 << OCIE4A);


  sei();//allow interrupts
  
  stepDescendre.setSpeed(5); //vitesse de 60 rpm, jsp pas trop pourquoi il faut mettre 5 mais bon on a pas mieux
  stepTourner.setSpeed(5);
  stepDecaler.setSpeed(5);
  
  ReadGY521(GyAccTemp, GATCorr);
  ComputeAngle(GyAccTemp, PitchRoll);

  angleInitial = PitchRoll[0];

}

void loop() {

  Serial.println("ça a passé le setup");
  int  intensiteMoteur = 0;
 
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
 
  //Serial.print(distance);
  //Serial.println("cm");

  
  if(arreterLesActions == false){
    ouvrirPince();
    nombreDeDemiToursDescendre = bougerMoteurPasAPas(descendre, 10, 11, 12, 13, nombreDeDemiToursDescendre);
    nombreDeDemiToursTourner = bougerMoteurPasAPas(tourner, 14, 15, 16, 17, nombreDeDemiToursTourner);
    nombreDeDemiToursDecaler = bougerMoteurPasAPas(decaler, 18, 19, 20, 21, nombreDeDemiToursDecaler);

    MiseEnMarche();
  
    if(arreter==true){
      Arreter();
    }
    if(ralentir==true){
      Ralentir();
    }
    
    if(accelerer==true){
      Accelerer();
    }
    if(gauche==true){
      Gauche();
    }
    if(droite==true){
      Droite();
    }
    arreterLesActions = true;
    
  }
  
  if(tableauDistances[2] >= distanceIdeale + 10){
    intensiteMoteur = intensiteMoteur - 100;
  }
  else if(tableauDistances[2] <= distanceIdeale - 10){
    intensiteMoteur = intensiteMoteur + 100;
  }

  int  intensiteMoteur1 = intensiteMoteur;
  int  intensiteMoteur2 = intensiteMoteur;
  int  intensiteMoteur3 = intensiteMoteur;
  int  intensiteMoteur4 = intensiteMoteur;

  ComputeAngle(GyAccTemp, PitchRoll);
  
  if(PitchRoll[0] = angleInitial - 3){
    intensiteMoteur1 = intensiteMoteur1 - 100;
    intensiteMoteur2 = intensiteMoteur2 - 100;
    intensiteMoteur3 = intensiteMoteur3 + 100;
    intensiteMoteur3 = intensiteMoteur4 + 100;
  }
  else if(PitchRoll[0] = angleInitial + 3){
    intensiteMoteur1 = intensiteMoteur1 + 100;
    intensiteMoteur2 = intensiteMoteur2 + 100;
    intensiteMoteur3 = intensiteMoteur3 - 100;
    intensiteMoteur3 = intensiteMoteur4 - 100;
  }

  
/*
  moteurDC(sens1, intensite1, pinSens1, pinIntensite1);
  moteurDC(sens2, intensite2, pinSens2, pinIntensite2);
  moteurDC(sens3, intensite3, pinSens3, pinIntensite3);
  moteurDC(sens4, intensite4, pinSens4, pinIntensite4);*/

  

  Serial.println("c'est reparti");
  
}


ISR(TIMER4_COMPA_vect){//timer1 interrupt 1Hz
  ouvrir = analogRead(pinOuvrir)*5.00/1023;
  descendre = analogRead(pinDescendre)*5.00/1023;
  tourner = analogRead(pinTourner)*5.00/1023;
  decaler = analogRead(pinDecaler)*5.00/1023;
  ReadGY521(GyAccTemp, GATCorr);
  arreterLesActions = false; 
 
 Serial.println("ça marche");

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
 
  if(ouvrir <= 2.5 && ouvrir > 0){

  }
  else if(ouvrir > 2.5 ){      
        
  }
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


void moteurDC(int sens, int intensite, int pinSens, int pinIntensite){
    digitalWrite(pinSens, sens);
    analogWrite(pinIntensite, intensite);
    
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


void Arreter(){
  analogWrite(pinMoteur1,0);
  analogWrite(pinMoteur2,0);
}
void MiseEnMarche(){
  analogWrite(pinMoteur1,1);
  analogWrite(pinMoteur2,1);
}
void Ralentir(){
  Power = 40;
  analogWrite(pinMoteur1,Power);
  analogWrite(pinMoteur2,Power);
}

void Accelerer(){
  Power=255;
  analogWrite(pinMoteur1,Power);
  analogWrite(pinMoteur2,Power);
}
void Gauche(){
  analogWrite(pinMoteur1,0);
  analogWrite(pinMoteur2,1);
}
void Droite(){
  analogWrite(pinMoteur1,1);
  analogWrite(pinMoteur2,0);
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
