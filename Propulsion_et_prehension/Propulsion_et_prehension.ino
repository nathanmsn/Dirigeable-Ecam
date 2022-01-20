

#include <Servo.h>
#include <Stepper.h> 

#define MIN_PULSE_LENGTH 1000 // Minimum pulse length in µs
#define MAX_PULSE_LENGTH 2000 // Maximum pulse length in µs

//int pinServoPince = 13;
//int pinServoTourner = 12;

const int stepsPerRevolution = 90;

Stepper stepDecaler(stepsPerRevolution, 32, 34, 36, 38);
Stepper stepDescendre(stepsPerRevolution, 40, 42, 44, 46);

Servo motPropulsionVersAvant1,motPropulsionVersAvant2,motPropulsionVersArriere1, motPropulsionVersArriere2, servoTourner, servoPince;

int arriveeTelecommande[4];
int pinsTelecommande[] = {3, 2, 4, 5};
