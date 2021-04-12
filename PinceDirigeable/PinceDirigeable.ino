
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






//intialisation du servo
Servo servoOuvrir;
int anglePince = 0;
boolean arreterDOuvrir = false;

//initialisation du moteur pas à pas
const int stepsPerRevolution = 90;
Stepper stepDescendre(stepsPerRevolution, 10, 11, 12, 13);
Stepper stepTourner(stepsPerRevolution, 14, 15, 16, 17);
Stepper stepDecaler(stepsPerRevolution, 18, 19, 20, 21);


int nombreDeDemiToursDescendre = 0;
int conteurHautDescendre = 0;
int conteurBasDescendre = 0;

int nombreDeDemiToursTourner = 0;
int conteurHautTourner = 0;
int conteurBasTourner = 0;

int nombreDeDemiToursDecaler = 0;
int conteurHautDecaler = 0;
int conteurBasDecaler = 0;


boolean arreterLesMesures = false; //pour arrêter la prise d'info supplémentaire quand le moteur fait déjà quelque chose


float ouvrir;
float descendre;
float tourner;
float decaler;


void setup() {


  pinMode(pinOuvrir, INPUT);
  pinMode(pinDescendre, INPUT);
  pinMode(pinTourner, INPUT);
  pinMode(pinDecaler, INPUT);


  
  servoOuvrir.attach(servoPinOuvrir);
  

  
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
  if(arreterLesMesures == false){
    ouvrirPince();
    descendrePince();
    tournerPince();
    decalerPince();
    arreterLesMesures = true;
    
  }

 

  
}


ISR(TIMER4_COMPB_vect){//timer1 interrupt 1Hz
  ouvrir = analogRead(pinOuvrir)*5.00/1023;
  descendre = analogRead(pinDescendre)*5.00/1023;
  tourner = analogRead(pinTourner)*5.00/1023;
  decaler = analogRead(pinDecaler)*5.00/1023;
  arreterLesMesures = false; 
 
 // Serial.println("ça marche");

}






//penser à faire des essaies sur les voltages en input

void descendrePince(){

    
  if(descendre <= 2.5 && descendre != 0){
      stepDescendre.step(stepsPerRevolution/2); //fait un demi tour de moteur d vers le bas
      nombreDeDemiToursDescendre++;
      conteurBasDescendre++;
      
    
    }
    else{
      stepDescendre.step(-stepsPerRevolution/2); //va vers le haut
      nombreDeDemiToursDescendre--;
      conteurHautDescendre++;
      if(conteurHautDescendre >= 2){ //Si ça fait 2s que on appuit sur le boutton
         stepDescendre.step(-stepsPerRevolution*nombreDeDemiToursDescendre/2);//On revient jusqu'en haut
      }
   
    }
  
}


void tournerPince(){

    
  if(tourner <= 2.5 && tourner != 0){
      stepTourner.step(stepsPerRevolution/2); //fait un demi tour de moteur d vers le bas
      nombreDeDemiToursTourner++;
      conteurBasTourner++;
      
    
    }
    else{
      stepTourner.step(-stepsPerRevolution/2); //va vers le haut
      nombreDeDemiToursTourner--;
      conteurHautTourner++;
      if(conteurHautTourner >= 2){ //Si ça fait 2s que on appuit sur le boutton
         stepTourner.step(-stepsPerRevolution*nombreDeDemiToursTourner/2);//On revient jusqu'en haut
      }
   
    }


}


void decalerPince(){
 
  if(decaler <= 2.5 && decaler != 0){
      stepDecaler.step(stepsPerRevolution/2); //fait un demi tour de moteur d vers le bas
      nombreDeDemiToursDecaler++;
      conteurBasDecaler++;
      
    
    }
    else{
      stepDecaler.step(-stepsPerRevolution/2); //va vers le haut
      nombreDeDemiToursDecaler--;
      conteurHautDecaler++;
      if(conteurHautDecaler >= 2){ //Si ça fait 2s que on appuit sur le boutton
         stepDecaler.step(-stepsPerRevolution*nombreDeDemiToursDecaler/2);//On revient jusqu'en haut
      }
    }
  

}



void ouvrirPince(){
  if(arreterDOuvrir == false){
    if(ouvrir == 0){
      
    }
    else if(ouvrir <= 2.5){
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




  
