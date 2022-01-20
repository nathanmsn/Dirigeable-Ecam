
#include <Servo.h>

#define MIN_PULSE_LENGTH 1000 // Minimum pulse length in µs
#define MAX_PULSE_LENGTH 2000 // Maximum pulse length in µs

char data;

Servo motPropulsionGauche, motPropulsionDroit;



int pinInverseurGauche1 = 3;
int pinInverseurGauche2 = 4;
int pinInverseurDroit1 = 5;
int pinInverseurDroit2 = 6;
