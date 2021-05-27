//#include <Servo.h> //Ca marche pas à cause des timers 16 bits, prendre le B, penser à tester jsp pourquoi où à quoi ça sert le b mais ça compile
#include <avr/interrupt.h>
#include <Stepper.h> 

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
const int stepsPerRevolution = 90;
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


void setup() {

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


}

void loop() {
  // put your main code here, to run repeatedly:
  if(arreterLesActions == false){
    ouvrirPince();
    nombreDeDemiToursDescendre = bougerMoteurPasAPas(descendre, 10, 11, 12, 13, nombreDeDemiToursDescendre);
    nombreDeDemiToursTourner = bougerMoteurPasAPas(tourner, 14, 15, 16, 17, nombreDeDemiToursTourner);
    nombreDeDemiToursDecaler = bougerMoteurPasAPas(decaler, 18, 19, 20, 21, nombreDeDemiToursDecaler);
    arreterLesActions = true;
    
  }

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





  
  
}


ISR(TIMER4_COMPB_vect){//timer1 interrupt 1Hz
  ouvrir = analogRead(pinOuvrir)*5.00/1023;
  descendre = analogRead(pinDescendre)*5.00/1023;
  tourner = analogRead(pinTourner)*5.00/1023;
  decaler = analogRead(pinDecaler)*5.00/1023;
  arreterLesActions = false; 
 
 // Serial.println("ça marche");

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
