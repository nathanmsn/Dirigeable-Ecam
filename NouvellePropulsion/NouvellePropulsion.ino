
#include <Servo.h>

#define MIN_PULSE_LENGTH 1000 // Minimum pulse length in µs
#define MAX_PULSE_LENGTH 2000 // Maximum pulse length in µs
#define propultionMax 1200 //valeur max de propultion

Servo servoInterieur, servoDroit, servoGauche, motPropulsionGauche, motPropulsionDroit;

int tmp;

int arriveeTelecommande[6];
int pinsTelecommande[] = {8,9,10,11,12,13};

//motPropulsionDroit =4;
int pinInverseurDroit = 5;
//motPropulsionGauche = 6;
int pinInverseurGauche = 7;


int joystickDroit = 1;
int joystickGauche = 2;

int valeurTelHaute = 1540; // pour ne pas compter les valeurs 460 et 540
int valeurTelBasse = 1460;
String sensG = "Null";
String sensD = "Null";
int chronoSwitchD = 0;
int chronoSwitchG = 0;
const int tmpsDArret = 5000; // Temps d'arrêt des moteurs de propulsion quand on change de sens 
