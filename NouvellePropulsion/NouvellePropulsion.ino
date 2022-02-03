
#include <Servo.h>

#define MIN_PULSE_LENGTH 1000 // Minimum pulse length in µs
#define MAX_PULSE_LENGTH 2000 // Maximum pulse length in µs
#define propultionMax 1100 //valeur max de propultion

Servo servoDroit, servoGauche, motPropulsionGauche, motPropulsionDroit;

int arriveeTelecommande[4];
int pinsTelecommande[] = {7, 6};
int pinInverseurGauche = 6;
int pinInverseurDroit = 7;


int joystickGauche = 2;
int joystickDroit = 0;

int chronoSwitchG;
int chronoSwitchD;
