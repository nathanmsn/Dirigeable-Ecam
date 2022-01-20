
#include <Servo.h>

#define MIN_PULSE_LENGTH 1000 // Minimum pulse length in µs
#define MAX_PULSE_LENGTH 2000 // Maximum pulse length in µs


Servo servoDroit, servoGauche, motPropulsionGauche, motPropulsionDroit;

int arriveeTelecommande[4];
int pinsTelecommande[] = {3, 2, 4, 5};
int pinInverseurGauche = 6;
int pinInverseurDroit = 7;
