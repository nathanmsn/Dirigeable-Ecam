void loop() 
{
   measureTelecommande();

DCMotor(map(arriveeTelecommande[joystickA],0,1000,-255,255),motorPin1A, motorPin2A, enablePinA);
DCMotor(map(arriveeTelecommande[joystickB],0,1000,-255,255),motorPin1B, motorPin2B, enablePinB);

}
