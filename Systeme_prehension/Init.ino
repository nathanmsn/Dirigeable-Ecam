void setup() {
    // Configuration des ports en mode "sortie"
    pinMode(motorPin1A, OUTPUT);
    pinMode(motorPin2A, OUTPUT);
    pinMode(enablePinA, OUTPUT);
    pinMode(motorPin1B, OUTPUT);
    pinMode(motorPin2B, OUTPUT);
    pinMode(enablePinB, OUTPUT);
    
    // Initialisation du port série
    Serial.begin(9600);
}
