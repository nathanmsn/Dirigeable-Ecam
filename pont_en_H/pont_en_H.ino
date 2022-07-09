#include <Servo.h>

Servo servoRotation, servoFermeture;


// Association des entrées du L298N, aux sorties utilisées sur notre Arduino Uno //
//*******************************************************************************//
#define borneENA        12     // On associe la borne "ENA" du L298N à la pin D10 de l'arduino
#define borneIN1        47       // On associe la borne "IN1" du L298N à la pin D9 de l'arduino
#define borneIN2        36       // On associe la borne "IN2" du L298N à la pin D8 de l'arduino
#define borneIN3        37       // On associe la borne "IN3" du L298N à la pin D7 de l'arduino
#define borneIN4        42       // On associe la borne "IN4" du L298N à la pin D6 de l'arduino
#define borneENB        13       // On associe la borne "ENB" du L298N à la pin D5 de l'arduino
#define pinBalaste1 34
#define pinBalaste2 35




int arriveeTelecommande[8];
int pinsTelecommande[] = {4,5,6,7,8,9,10,11};

int joystickDroitHB = 7; // joystick droit haut bas
int joystickDroitDG = 6; // Joystick DROIT droite gauche
int AileDR = 3; //Bouton AILE D/R
int valeurTelHaute = 1560; // pour ne pas compter les valeurs 1460 et 1540
int valeurTelBasse = 1440;