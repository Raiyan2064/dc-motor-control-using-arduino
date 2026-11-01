// DC Motor Control using Arduino and L293D
// Experiment 07 - EEE 3100 Lab

const int enA  = 9;   // PWM pin for Enable A (speed control)
const int in1  = 8;   // Direction input 1
const int in2  = 7;   // Direction input 2
const int pot  = A0;  // Potentiometer for speed control
const int btn1 = 4;   // Button: Forward
const int btn2 = 5;   // Button: Reverse

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int potVal  = analogRead(pot);
  int speed   = map(potVal, 0, 1023, 0, 255);
  bool fwd    = (digitalRead(btn1) == LOW);
  bool rev    = (digitalRead(btn2) == LOW);

  if (fwd) {
    // Rotate Forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, speed);
    Serial.print("Forward | Speed (PWM): ");
    Serial.println(speed);
  } else if (rev) {
    // Rotate Reverse
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, speed);
    Serial.print("Reverse | Speed (PWM): ");
    Serial.println(speed);
  } else {
    // Stop
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enA, 0);
    Serial.println("Motor Stopped");
  }
  delay(100);
}
