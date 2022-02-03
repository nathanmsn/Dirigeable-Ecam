
#include <Servo.h>

#define MIN_PULSE_LENGTH 1000 // Minimum pulse length in µs
#define MAX_PULSE_LENGTH 2000 // Maximum pulse length in µs
#define propultionMax 1100 //valeur max de propultion

Servo servoDroit, servoGauche, motPropulsionGauche, motPropulsionDroit;

int arriveeTelecommande[6];
int pinsTelecommande[] = {8,9,10,11,12,13};

//motPropulsionDroit =4;
int pinInverseurDroit = 5;
//motPropulsionGauche = 6;
int pinInverseurGauche = 7;


int joystickGauche = 2;
int joystickDroit = 8;

int sens;
