
#include <Servo.h>

#define MIN_PULSE_LENGTH 1000 // Minimum pulse length in µs
#define MAX_PULSE_LENGTH 2000 // Maximum pulse length in µs
#define propultionMax 1350 //valeur max de propultion

Servo servoInterieur, servoDroit, servoGauche, motPropulsionGauche, motPropulsionDroit;

int tmp;
int CoeffGauche = 1 ;
int CoeffDroit = 1 ;

int arriveeTelecommande[6];
int pinsTelecommande[] = {8,9,10,11,12,13};

//motPropulsionDroit =4;
int pinInverseurDroit = 22;  //anciennement 5
//motPropulsionGauche = 6;
int pinInverseurGauche = 23; //anciennement 7


int joystickDroit = 1;
int joystickGauche = 2;

int valeurTelHaute = 1560; // pour ne pas compter les valeurs 1460 et 1540
int valeurTelBasse = 1440;
String sensG = "Null";
String sensD = "Null";
int chronoSwitchD = 0;
int chronoSwitchG = 0;
const int tmpsDArret = 3000; // Temps d'arrêt des moteurs de propulsion quand on change de sens 
