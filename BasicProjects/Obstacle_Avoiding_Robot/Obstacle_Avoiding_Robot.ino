// Define pins for ultrasonic sensors
#define TRIG_FRONT 6
#define ECHO_FRONT 7
#define TRIG_LEFT 8
#define ECHO_LEFT 9
#define TRIG_RIGHT 10
#define ECHO_RIGHT 11

// Define motor driver pins
#define m1a 2
#define m1b 3
#define m2a 4
#define m2b 5



void setup() {
  // Initialize motor pins
  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);

  pinMode(ECHO_FRONT, INPUT);
  pinMode(TRIG_FRONT, OUTPUT);
  pinMode(ECHO_LEFT, INPUT);
  pinMode(TRIG_LEFT, OUTPUT);
  pinMode(ECHO_RIGHT, INPUT);
  pinMode(TRIG_RIGHT, OUTPUT);

  moveForward();

  Serial.begin(9600);
}
int distanceFront = distanceFrontCM();
int distanceLeft = distanceLeftCM();
int distanceRight = distanceRightCM();
char leftORright = ' ';

int distanceFrontCM() {
  digitalWrite(TRIG_FRONT, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_FRONT, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_FRONT, LOW);
  int duration = pulseIn(ECHO_FRONT, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}
int distanceLeftCM() {
  digitalWrite(TRIG_LEFT, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_LEFT, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_LEFT, LOW);
  int duration = pulseIn(ECHO_LEFT, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}
int distanceRightCM() {
  digitalWrite(TRIG_RIGHT, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_RIGHT, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_RIGHT, LOW);
  int duration = pulseIn(ECHO_RIGHT, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}


void moveForward()  // Forward
{
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
  Serial.println("Moving Forward");
}
void moveBack()  // Backward
{
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, HIGH);
  Serial.println("Moving Back");
}

void moveLeft()  //Left
{
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
  Serial.println("Moving Left");
}
void moveRight()  //Right
{
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, HIGH);
  Serial.println("Moving Right");
}

void stop()  //Stop
{
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);
}



void loop() {
  distanceFront = distanceFrontCM();

  Serial.print("Front: ");
  Serial.println(distanceFront);

  // Serial.print(" Left: ");
  // Serial.println(distanceLeft);
  // Serial.print(" Right: ");
  // Serial.println(distanceRight);


  if (distanceFront <= 10) {
    stop();
    do {
      distanceLeft = distanceLeftCM();
      distanceRight = distanceRightCM();
      moveBack();
      leftORright = (distanceLeft > 20) ? 'L' : 'R';
      delay(100);
    } while (distanceLeft <= 20 || distanceRight <= 20);
    if (leftORright == 'L') {
      moveLeft();
      delay(100);
      stop();
    }
    if (distanceRight > 'R') {
      moveRight();
      delay(100);
      stop();
    }
  }
}