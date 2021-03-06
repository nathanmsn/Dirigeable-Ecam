void setup() {
  
  // Configuration de toutes les pins de l'Arduino en "sortie" (car elles attaquent les entrées du module L298N)
  Serial.begin(9600);
//  pinMode(borneENA, OUTPUT);
//  pinMode(borneIN1, OUTPUT);
// pinMode(borneIN2, OUTPUT);
  pinMode(borneIN3, OUTPUT);
  pinMode(borneIN4, OUTPUT);
  pinMode(borneENB, OUTPUT);
  // pin mode pour la telecommande
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);

  // pin balastes
  pinMode(22,OUTPUT); // Balaste 1
  pinMode(35,OUTPUT); // Balaste 2

  // pin Servo
  pinMode(2,OUTPUT); // fermeture
  pinMode(3,OUTPUT); // rotation
  
  servoFermeture.attach(2);
  servoRotation.attach(3);
 
}
