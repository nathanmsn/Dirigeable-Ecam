
#include <Servo.h> 

Servo myServo;

void setup() {
  myServo.attach(4);
}
  
void loop() {
  myServo.write(0);
  myServo.write(20);
  myServo.write(40);
  myServo.write(60);
  myServo.write(90);
  myServo.write(120);
  myServo.write(150);
  myServo.write(180);

}
