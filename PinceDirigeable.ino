
#include <Servo.h> //Ca marche pas à cause des timers 16 bits, prendre le B, penser à tester jsp pourquoi où à quoi ça sert le b mais ça compile
#include <avr/interrupt.h>
#include <Stepper.h> 

//Pin input pince
const uint8_t pinOuvrir = A1;
const uint8_t pinDescendre = A2;
const uint8_t pinTourner = A3;
const uint8_t pinDecaler = A4;


//Pin output pince
const uint8_t servoPinOuvrir = 5; 

const uint8_t pinTournerDirection = 6;
const uint8_t pinDecalerDirection = 8;

const uint8_t pinTournerPower = 7;
const uint8_t pinDecalerPower = 9;



int ouvrir;
int descendre;
int tourner;
int decaler;


//intialisation du servo
Servo servoOuvrir;
int anglePince = 0;
boolean arreterDOuvrir = false;

//initialisation du moteur pas à pas
const int stepsPerRevolution = 90;
Stepper stepDescendre(stepsPerRevolution, 10, 11, 12, 13);
int nombreDeDemiTours = 0;
int conteurHaut = 0;
int conteurBas = 0;
boolean arreterDeDescendre = false; //pour arrêter la prise d'info supplémentaire quand le moteur fait déjà quelque chose




void setup() {


  pinMode(pinOuvrir, INPUT);
  pinMode(pinDescendre, INPUT);
  pinMode(pinTourner, INPUT);
  pinMode(pinDecaler, INPUT);

  pinMode(pinTournerDirection, OUTPUT);
  pinMode(pinDecalerDirection, OUTPUT);
  pinMode(pinTournerPower, OUTPUT);
  pinMode(pinDecalerPower, OUTPUT);

  
  servoOuvrir.attach(servoPinOuvrir);
  
  //set timer0 interrupt at 1kHz
  TCCR0A = 0;// set entire TCCR2A register to 0
  TCCR0B = 0;// same for TCCR2B
  TCNT0  = 0;//initialize counter value to 0
  // set compare match register for 2khz increments
  OCR0A = 250;// = (16*10^6) / (1000*64) - 1 (must be <256)
  // turn on CTC mode
  TCCR0A |= (1 << WGM01);
  // Set CS01 and CS00 bits for 64 prescaler
  TCCR0B |= (1 << CS01) | (1 << CS00);   
  // enable timer compare interrupt
  TIMSK0 |= (1 << OCIE0A);

  //set timer1 interrupt at 4Hz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 3906;// = (16*10^6) / (4*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12 and CS10 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);

  
 //set timer4 interrupt at 1Hz
 TCCR4A = 0;// set entire TCCR1A register to 0
 TCCR4B = 0;// same for TCCR1B
 TCNT4  = 0;//initialize counter value to 0
 // set compare match register for 1hz increments
 OCR4A = 15624/1;// = (16*10^6) / (1*1024) - 1 (must be <65536)
 // turn on CTC mode
 TCCR4B |= (1 << WGM12);
 // Set CS12 and CS10 bits for 1024 prescaler
 TCCR4B |= (1 << CS12) | (1 << CS10);  
 // enable timer compare interrupt
 TIMSK4 |= (1 << OCIE4A);



sei();//allow interrupts

stepDescendre.setSpeed(5); //vitesse de 60 rpm, jsp pas trop pourquoi il faut mettre 5 mais bon on a pas mieux


}

void loop() {
  // put your main code here, to run repeatedly:

  moteurDC(pinTournerDirection, pinTournerPower, tourner);
  moteurDC(pinDecalerDirection, pinDecalerPower, decaler);
  ouvrirPince();
  descendrePince();

  
}

ISR(TIMER0_COMPA_vect){//timer0 interrupt 1kHz
  tourner = analogRead(pinTourner)*5.00/1023;
  decaler = analogRead(pinDecaler)*5.00/1023;
}

/*ISR(TIMER1_COMPA_vect){//timer1 interrupt 4Hz
  ouvrir = analogRead(pinOuvrir)*5.00/1023;
  descendre = analogRead(pinDescendre)*5.00/1023;
  arreterDeDescendre = false; 


}*/

ISR(TIMER4_COMPB_vect){//timer1 interrupt 4Hz
  ouvrir = analogRead(pinOuvrir)*5.00/1023;
  descendre = analogRead(pinDescendre)*5.00/1023;
  arreterDeDescendre = false; 
  arreterDOuvrir = false;
 // Serial.println("ça marche");

}




void ouvrirPince(){
  if(arreterDOuvrir == false){
    if(ouvrir == 0){
      
    }
    else if(ouvrir <= 512){
      anglePince = anglePince + 2;
      servoOuvrir.write(anglePince);
    
    }
    else{
      anglePince = anglePince - 2;
      servoOuvrir.write(anglePince);
   
    }

    arreterDOuvrir = true;
  }

   

  

}

//penser à faire des essaies sur les voltages en input

void descendrePince(){
  if(arreterDeDescendre == false){//Pour qu'on execute la fonction que une fois par mesure
    
    if(descendre == 0){
    }
    else if(descendre <= 512){
      stepDescendre.step(stepsPerRevolution/2); //fait un demi tour de moteur d vers le bas
      nombreDeDemiTours++;
      conteurBas++;
      
    
    }
    else{
      stepDescendre.step(-stepsPerRevolution/2); //va vers le haut
      nombreDeDemiTours--;
      conteurHaut++;
      if(conteurHaut >= 6){ //Si ça fait 1,5s que on appuit sur le boutton
         stepDescendre.step(-stepsPerRevolution*nombreDeDemiTours/2);//On revient jusqu'en haut
      }
   
    }
  
    arreterDeDescendre = true; //On ne referra plus la fonction
   
  }

}

void moteurDC(int pinDirection, int pinPower, int valeurSensor){
  if(valeurSensor == 0){
    digitalWrite(pinPower, LOW);
  }
  else if(valeurSensor <= 512){
    digitalWrite(pinDirection, HIGH);
    digitalWrite(pinPower, HIGH);
  }
  else{
    digitalWrite(pinDirection, LOW);
    digitalWrite(pinPower, HIGH);
  
}


}

//Ca sert plus à rien j'ai fusionner les deux fonctions pour en faire qu'une avec des inputs je le garde juste au cas où
/*void tournerPince(){
  if(descendre == 0){
    digitalWrite(pinTournerPower, LOW);
  }
  else if(descendre <= 512){
    digitalWrite(pinTournerDirection, HIGH);
    digitalWrite(pinTournerPower, HIGH);
  }
  else{
    digitalWrite(pinTournerDirection, LOW);
    digitalWrite(pinTournerPower, HIGH);
  }
 

}

void decalerPince(){
  if(descendre == 0){
    digitalWrite(pinDecalerPower, LOW);
  }
  else if(descendre <= 512){
    digitalWrite(pinDecalerDirection, HIGH);
    digitalWrite(pinDecalerPower, HIGH);
  }
  else{
    digitalWrite(pinDecalerDirection, LOW);
    digitalWrite(pinDecalerPower, HIGH);
  }*/




  
