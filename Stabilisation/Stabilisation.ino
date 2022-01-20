
#include <Servo.h>
#include<Wire.h>
#include <math.h>

/*initialisation gyro*/
#define NumData 7
#define pi      3.1415926535897932384626433832795  
#define MPU     0x68

int  GyAccTemp[NumData];
int  GATCorr[NumData]={0,0,0,0,0,0,0};
//int  GATCorr[NumData]={-950,-300,0,-1600,480,170,210};

const int pinsTelecommande[2] = {6, 7};
int arriveeTelecommande[2];

double PitchRoll[3];
int pitchInitial;
int rollInitial;

#define MIN_PULSE_LENGTH 1000 // Minimum pulse length in µs
#define MAX_PULSE_LENGTH 2000 // Maximum pulse length in µs

const int trigPin = 9; //set pin variables
const int echoPin = 10;

int trigState = LOW; //state of trigPin
int interval = 1; // interval in milliseconds at which trigPin turns on
unsigned long previousMillis = 0; //microsecond at which the pin was last writen
int distance = 0;
int tableauDistances[4];
int compteurMesures = 0;

const uint8_t distanceIdeale = 200;

Servo motStabilisationAvantDroit, motStabilisationAvantGauche, motStabilisationArriereDroit, motStabilisationArriereGauche, servoAvantGauche, servoAvantDroit, servoArriereGauche, servoArriereDroit;

int intensiteMoteursStabilisation = 0; 

int stepsPerRevolution = 125;

const int buterDesServosYaw = 30;
const int buterDesServosSlide = 30;
