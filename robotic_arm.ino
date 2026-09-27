#include <Servo.h>

Servo baseServo;
Servo elbowServo;
Servo shoulderServo;
Servo gripperServo;

void setup() {
  baseServo.attach(2);
  elbowServo.attach(3);
  shoulderServo.attach(4);
  gripperServo.attach(5);

  Serial.begin(9600);

  baseServo.write(90);
  elbowServo.write(90);
  shoulderServo.write(90);
  gripperServo.write(90);

  Serial.println("READY");
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    int angle = Serial.parseInt();

    angle = constrain(angle, 0, 180);

    if (command == 'B' || command == 'b') {
      baseServo.write(angle);
      Serial.print("Base: ");
      Serial.println(angle);
    }

    else if (command == 'E' || command == 'e') {
      elbowServo.write(angle);
      Serial.print("Elbow: ");
      Serial.println(angle);
    }

    else if (command == 'S' || command == 's') {
      shoulderServo.write(angle);
      Serial.print("Shoulder: ");
      Serial.println(angle);
    }

    else if (command == 'G' || command == 'g') {
      gripperServo.write(angle);
      Serial.print("Gripper: ");
      Serial.println(angle);
    }
  }
}
