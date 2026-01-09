// Line Following Arduino Car
#define enA 10
#define in1 9
#define in2 8
#define in3 7
#define in4 6
#define enB 5

// IR Sensors
#define R_S 14   // Right sensor
#define L_S 15   // Left sensor

void setup() {
  pinMode(R_S, INPUT);
  pinMode(L_S, INPUT);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);

  // Set motor speed
  analogWrite(enA, 255);
  analogWrite(enB, 255);
}

void loop() {
  // Both sensors on white surface
  if (digitalRead(R_S) == 0 && digitalRead(L_S) == 0) {
    forward();
  }
  // Right sensor on black line
  else if (digitalRead(R_S) == 1 && digitalRead(L_S) == 0) {
    turnRight();
  }
  // Left sensor on black line
  else if (digitalRead(R_S) == 0 && digitalRead(L_S) == 1) {
    turnLeft();
  }
  // Both sensors on black line
  else {
    stopCar();
  }
}

// Motor control functions
void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnRight() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnLeft() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void stopCar() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
