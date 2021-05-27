// Include the Arduino Stepper Library
#include <Stepper.h>

// Number of steps per output rotation
const int stepsPerRevolution = 125;

// Create Instance of Stepper library
Stepper myStepper(stepsPerRevolution, 22, 23, 24, 25);



void setup() {
  // put your setup code here, to run once:
  // set the speed at 20 rpm:
  myStepper.setSpeed(10);
  // initialize the serial port:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  // step one revolution in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);

// step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);

}
