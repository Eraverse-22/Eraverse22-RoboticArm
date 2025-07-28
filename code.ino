#include <Servo.h>
#include <SoftwareSerial.h>


Servo Servo1;
Servo Servo2;
Servo Servo3;
Servo Servo4;
Servo Servo5;
Servo Servo6;

// Variables to track current positions of the servos
int pos = 90;   // Initialize with a default but not overwrite upon startup
int pos1 = 130;
int pos2 = 0;
int pos3=90;
int pos0 =90;

void setup() {
  Serial.begin(9600);
  
  Servo1.attach(3);
  Servo2.attach(5);
  Servo3.attach(6);
  Servo4.attach(9);
  Servo5.attach(8);
  Servo6.attach(2);

  Serial.println("Servo control ready. Awaiting commands...");
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    Serial.println(command);

    switch (command) {
      case 'R':  // Move Right
        
        Servo1.write(0);
        Serial.println("Moving Forward");
        delay(50);
        break;

      case 'L':  // Move Left
        Servo1.write(180);
        
        Serial.println("Moving Backward");
        delay(50);
        break;

      case 'U':  // Rotate Servo2 and Servo3 Left
        pos = constrain(pos + 10, 0, 180); // Ensure the value stays within bounds
        Servo2.write(pos);
        Servo3.write(pos);
        Serial.println(pos);
        Serial.println("up");
        delay(15);
        break;

      case 'D':  // Rotate Servo2 and Servo3 Right
        pos = constrain(pos - 10, 0, 180);
        Servo2.write(pos);
        Servo3.write(pos);
        Serial.println(pos);
        Serial.println("DOWN");
        delay(15);
        break;

      case 'S':  // Stop
        Servo1.write(90);
        Serial.println("Stop");
        break;

      case 'M':  // Rotate Servo4 Clockwise
        pos1 = constrain(pos1 + 5, 0, 180);
        Servo4.write(pos1);
        Serial.println(pos1);
        Serial.println("Rotating Servo4 Clockwise");
        delay(15);
        break;

      case 'N':  // Rotate Servo4 Counterclockwise
        pos1 = constrain(pos1 - 5, 0, 180);
        Servo4.write(pos1);
        Serial.println(pos1);
        Serial.println("Rotating Servo4 Counterclockwise");
        delay(15);
        break;

      case 'T':  // Rotate Servo5 Upward
        pos2 = constrain(pos2 + 10, 0, 180);
        Servo5.write(pos2);
        Serial.println(pos2);
        Serial.println("Rotating Servo5 Upward");
        delay(15);
        break;

      case 'V':  // Rotate Servo5 Downward
        pos2 = constrain(pos2 - 7, 0, 180);
        Servo5.write(pos2);
        Serial.println(pos2);
        Serial.println("Rotating Servo5 Downward");
        delay(15);
        break;
         case 'C':  // Rotate Servo5 Downward
        pos3 = constrain(pos3 + 20, 0, 180);
        Servo6.write(pos3);
        Serial.println(pos3);
        Serial.println("Rotating Servo6 To close");
        delay(20);
        break;
         case 'O':  // Rotate Servo5 Downward
        pos3 = constrain(pos3 - 20, 0, 180);
        Servo6.write(pos3);
        Serial.println("Rotating Servo to open");
        Serial.println(pos3);
        delay(20);
        break;

      default:
        Serial.println("Invalid command received.");
        break;
    }
  }
}
