/**
 * Usage, according to documentation(https://www.firediy.fr/files/drone/HW-01-V4.pdf) : 
 *     1. Plug your Arduino to your computer with USB cable, open terminal, then type 1 to send max throttle to every ESC to enter programming mode
 *     2. Power up your ESCs. You must hear "beep1 beep2 beep3" tones meaning the power supply is OK
 *     3. After 2sec, "beep beep" tone emits, meaning the throttle highest point has been correctly confirmed
 *     4. Type 0 to send min throttle
 *     5. Several "beep" tones emits, which means the quantity of the lithium battery cells (3 beeps for a 3 cells LiPo)
 *     6. A long beep tone emits meaning the throttle lowest point has been correctly confirmed
 *     7. Type 2 to launch test function. This will send min to max throttle to ESCs to test them
 *
 * @author lobodol <grobodol@gmail.com>
 */
// ---------------------------------------------------------------------------
#include <Servo.h>
// ---------------------------------------------------------------------------
// Customize here pulse lengths as needed
#define MIN_PULSE_LENGTH 1000 // Minimum pulse length in µs
#define MAX_PULSE_LENGTH 2000 // Maximum pulse length in µs
// ---------------------------------------------------------------------------
Servo motA, motB, motC, motD, motE, motF, motG, motH;
<<<<<<< HEAD
=======

>>>>>>> develop
char data;
// ---------------------------------------------------------------------------

/**
 * Initialisation routine
 */
void setup() {
    Serial.begin(9600);
    
    motA.attach(2, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
    motB.attach(3, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
    motC.attach(4, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
    motD.attach(5, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
<<<<<<< HEAD
    motA.attach(6, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
    motB.attach(7, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
    motC.attach(11, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
    motD.attach(12, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
=======
    motE.attach(6, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
    motF.attach(7, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
    motG.attach(11, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
    motH.attach(12, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
>>>>>>> develop
    
    
    displayInstructions();
}

/**
 * Main function
 */
void loop() {
    if (Serial.available()) {
        data = Serial.read();

        switch (data) {
            // 0
            case 48 : Serial.println("Sending minimum throttle");
                      motA.writeMicroseconds(MIN_PULSE_LENGTH);
                      motB.writeMicroseconds(MIN_PULSE_LENGTH);
                      motC.writeMicroseconds(MIN_PULSE_LENGTH);
                      motD.writeMicroseconds(MIN_PULSE_LENGTH);
                      motE.writeMicroseconds(MIN_PULSE_LENGTH);
                      motF.writeMicroseconds(MIN_PULSE_LENGTH);
                      motG.writeMicroseconds(MIN_PULSE_LENGTH);
                      motH.writeMicroseconds(MIN_PULSE_LENGTH);
            break;

            // 1
            case 49 : Serial.println("Sending maximum throttle");
                      motA.writeMicroseconds(MAX_PULSE_LENGTH);
                      motB.writeMicroseconds(MAX_PULSE_LENGTH);
                      motC.writeMicroseconds(MAX_PULSE_LENGTH);
                      motD.writeMicroseconds(MAX_PULSE_LENGTH);
                      motE.writeMicroseconds(MAX_PULSE_LENGTH);
                      motF.writeMicroseconds(MAX_PULSE_LENGTH);
                      motG.writeMicroseconds(MAX_PULSE_LENGTH);
                      motH.writeMicroseconds(MAX_PULSE_LENGTH);
            break;

            // 2
            case 50 : Serial.print("Running test in 3");
                      delay(1000);
                      Serial.print(" 2");
                      delay(1000);
                      Serial.println(" 1...");
                      delay(1000);
                      test();
            break;
        }
    }
    

}

/**
 * Test function: send min throttle to max throttle to each ESC.
 */
void test()
{
<<<<<<< HEAD
    for (int i = MIN_PULSE_LENGTH; i <= MAX_PULSE_LENGTH; i += 5) {
=======
    for (int i = MIN_PULSE_LENGTH + 200; i <= MAX_PULSE_LENGTH-800; i += 5) {
>>>>>>> develop
        Serial.print("Pulse length = ");
        Serial.println(i);
        
        motA.writeMicroseconds(i);
        motB.writeMicroseconds(i);
        motC.writeMicroseconds(i);
        motD.writeMicroseconds(i);
        motE.writeMicroseconds(i);
        motF.writeMicroseconds(i);
        motG.writeMicroseconds(i);
        motH.writeMicroseconds(i);
        
<<<<<<< HEAD
        delay(200);
=======
        delay(2000);
>>>>>>> develop
    }

    Serial.println("STOP");
    motA.writeMicroseconds(MIN_PULSE_LENGTH);
    motB.writeMicroseconds(MIN_PULSE_LENGTH);
    motC.writeMicroseconds(MIN_PULSE_LENGTH);
    motD.writeMicroseconds(MIN_PULSE_LENGTH);
    motE.writeMicroseconds(MIN_PULSE_LENGTH);
    motF.writeMicroseconds(MIN_PULSE_LENGTH);
    motG.writeMicroseconds(MIN_PULSE_LENGTH);
    motH.writeMicroseconds(MIN_PULSE_LENGTH);
}

/**
 * Displays instructions to user
 */
void displayInstructions()
{  
    Serial.println("READY - PLEASE SEND INSTRUCTIONS AS FOLLOWING :");
    Serial.println("\t0 : Send min throttle");
    Serial.println("\t1 : Send max throttle");
    Serial.println("\t2 : Run test function\n");
}
