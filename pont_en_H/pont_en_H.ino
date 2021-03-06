#include <Servo.h>

Servo servoRotation, servoFermeture;


// Association des entrées du L298N, aux sorties utilisées sur notre Arduino Uno //
//*******************************************************************************//
//#define borneENA        12     // On associe la borne "ENA" du L298N à la pin D10 de l'arduino
//#define borneIN1        47       // On associe la borne "IN1" du L298N à la pin D9 de l'arduino
//#define borneIN2        36       // On associe la borne "IN2" du L298N à la pin D8 de l'arduino
#define borneIN3        34       // On associe la borne "IN3" du L298N à la pin D7 de l'arduino
#define borneIN4        36       // On associe la borne "IN4" du L298N à la pin D6 de l'arduino
#define borneENB        13       // On associe la borne "ENB" du L298N à la pin D5 de l'arduino
#define pinBalaste1 22
#define pinBalaste2 23




int arriveeTelecommande[4];
int pinsTelecommande[] = {8,9,10,11};

int joystickDroitHB = 2; // joystick droit haut bas
int joystickDroitDG = 0; // Joystick DROIT droite gauche
int gear = 3; //Bouton gear
int valeurTelHaute = 1560; // pour ne pas compter les valeurs 1460 et 1540
int valeurTelBasse = 1440;
