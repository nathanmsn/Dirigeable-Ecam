const int trigPin = 9; //set pin variables
const int echoPin = 10;

int trigState = LOW; //state of trigPin
int interval = 1; // interval in milliseconds at which trigPin turns on
unsigned long previousMillis = 0; //microsecond at which the pin was last writen
int distance = 0;

void setup()
{
  Serial.begin(9600); //begin serial communication
  pinMode(trigPin,OUTPUT); //set pinmodes
  pinMode(echoPin,INPUT);
  
}

void loop()
{

  int test = distanceToGround();
  if(test != 0){
    distance = test;
  }
 
 Serial.print(distance);
 Serial.println("cm");
}
 


int distanceToGround(){
  unsigned long currentMillis = millis(); //time in milliseconds from which the code was started
  if (currentMillis-previousMillis >= interval) { //check "blink without delay" code
    previousMillis = currentMillis;
    if (trigState == LOW){
      (trigState = HIGH);
    }
    else {
      (trigState = LOW);
    }
  }
 
  digitalWrite(trigPin,trigState);
  int duration, distance; //variables
  duration = pulseIn(echoPin,HIGH);
  distance = (duration/2) / 29.1;
  return distance;
}
