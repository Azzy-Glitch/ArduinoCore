// Pin Definitions
const int downToUpLift_TrigPin = 2;  // Trig pin of ultrasonic sensor 1
const int downToUpLift_EchoPin = 3;  // Echo pin of ultrasonic sensor 1
const int upToDownLift_TrigPin = 4;  // Trig pin of ultrasonic sensor 2
const int upToDownLift_EchoPin = 5;  // Echo pin of ultrasonic sensor 2
const int motor1Input1Pin = 6;       // Input 1 pin of motor 1 on L298N
const int motor1Input2Pin = 7;       // Input 2 pin of motor 1 on L298N
const int motor2Input1Pin = 8;       // Input 1 pin of motor 2 on L298N
const int motor2Input2Pin = 9;       // Input 2 pin of motor 2 on L298N

// Variables
int downToUpLift = 0;  // Variables for ultrasonic sensor 1
int upToDownLift = 0;  // Variables for ultrasonic sensor 1

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Define pin modes
  pinMode(downToUpLift_TrigPin, OUTPUT);
  pinMode(downToUpLift_EchoPin, INPUT);
  pinMode(upToDownLift_TrigPin, OUTPUT);
  pinMode(upToDownLift_EchoPin, INPUT);
  pinMode(motor1Input1Pin, OUTPUT);
  pinMode(motor1Input2Pin, OUTPUT);
  pinMode(motor2Input1Pin, OUTPUT);
  pinMode(motor2Input2Pin, OUTPUT);
}

void loop() {
  digitalWrite(motor2Input1Pin, HIGH);  // Set motor 1 direction
  digitalWrite(motor2Input2Pin, LOW);   // Set motor 1 direction
  digitalWrite(motor1Input1Pin, LOW);   // Set motor 1 direction
  digitalWrite(motor1Input2Pin, LOW);   // Set motor 1 direction

  downToUpLift = Return_US_Value(downToUpLift_TrigPin, downToUpLift_EchoPin);
  upToDownLift = Return_US_Value(upToDownLift_TrigPin, upToDownLift_EchoPin);

  if (downToUpLift <= 4) {
    delay(5000);
    Serial.println("Lift 1 going up ");
    digitalWrite(motor2Input1Pin, LOW);  // Set motor 1 direction
    digitalWrite(motor2Input2Pin , HIGH);   // Set motor 1 direction
    delay(5000);
    Serial.println("Lift 1 Staying at top ");
    digitalWrite(motor2Input1Pin, LOW);  // Set motor 1 direction
    digitalWrite(motor2Input2Pin, LOW);  // Set motor 1 direction
    delay(10000);
    Serial.println("Lift 1 coming down ");
    digitalWrite(motor2Input1Pin, HIGH);   // Set motor 1 direction
    digitalWrite(motor2Input2Pin, LOW);  // Set motor 1 direction
    delay(5000);
    Serial.println("Lift 1 stopped down ");
    digitalWrite(motor2Input1Pin, LOW);  // Set motor 1 direction
    digitalWrite(motor2Input2Pin, LOW);  // Set motor 1 direction
    delay(2000);
  } else {
    digitalWrite(motor2Input1Pin, LOW);  // Set motor 1 direction
    digitalWrite(motor2Input2Pin, LOW);  // Set motor 1 direction
  }

  if (upToDownLift <= 7) {
    delay(5000);
    Serial.println("Lift 2 going down ");
    digitalWrite(motor1Input1Pin, HIGH);  // Set motor 1 direction
    digitalWrite(motor1Input2Pin, LOW);   // Set motor 1 direction
    delay(5000);
    Serial.println("Lift 2 Staying down ");
    digitalWrite(motor1Input1Pin, LOW);  // Set motor 1 direction
    digitalWrite(motor1Input2Pin, LOW);  // Set motor 1 direction
    delay(10000);
    Serial.println("Lift 2 coming up ");
    digitalWrite(motor1Input1Pin, LOW);   // Set motor 1 direction
    digitalWrite(motor1Input2Pin, HIGH);  // Set motor 1 direction
    delay(5000);
    Serial.println("Lift 2 stopped up ");
    digitalWrite(motor1Input1Pin, LOW);  // Set motor 1 direction
    digitalWrite(motor1Input2Pin, LOW);  // Set motor 1 direction
    delay(1000);
  } else {
    digitalWrite(motor1Input1Pin, LOW);  // Set motor 1 direction
    digitalWrite(motor1Input2Pin, LOW);  // Set motor 1 direction
  }

  // Print distances for debugging
  Serial.print("downToUpLift: ");
  Serial.print(downToUpLift);
  Serial.println(" cm\t");
  Serial.print("upToDownLift: ");
  Serial.print(upToDownLift);
  Serial.println(" cm");

  delay(50);  // Delay for stability
}


int Return_US_Value(int trigPin, int echoPin) {

  // Ultrasonic sensor 1: Measure distance and turn on motor 1 if distance is less than 20 cm
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}