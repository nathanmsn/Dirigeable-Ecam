
#include <Servo.h>

#define MIN_PULSE_LENGTH 1000 // Minimum pulse length in µs
#define MAX_PULSE_LENGTH 2000 // Maximum pulse length in µs

char data;

Servo motPropulsionGauche, motPropulsionDroit;



int pinInverseurGauche1 = 7;
int pinInverseurGauche2 = 7;
int pinInverseurDroit1 = 7;
int pinInverseurDroit2 = 7;
