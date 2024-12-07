#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>
#include <MPU6050.h>

// Define servo motor pins
#define NECK_PAN_PIN 2
#define NECK_TILT_PIN 3
#define SHOULDER_R_PIN 4
#define SHOULDER_L_PIN 5
#define ELBOW_R_PIN 6
#define ELBOW_L_PIN 7
#define WRIST_R_PIN 8
#define WRIST_L_PIN 9
#define HIP_R_PIN 10
#define HIP_L_PIN 11
#define KNEE_R_PIN 12
#define KNEE_L_PIN 13
#define ANKLE_R_PIN 14
#define ANKLE_L_PIN 15

// Define servo motor objects
Servo neckPan, neckTilt;
Servo shoulderR, shoulderL;
Servo elbowR, elbowL;
Servo wristR, wristL;
Servo hipR, hipL;
Servo kneeR, kneeL;
Servo ankleR, ankleL;

// Define MPU6050 object
MPU6050 mpu;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize servo motors
  neckPan.attach(NECK_PAN_PIN);
  neckTilt.attach(NECK_TILT_PIN);
  shoulderR.attach(SHOULDER_R_PIN);
  shoulderL.attach(SHOULDER_L_PIN);
  elbowR.attach(ELBOW_R_PIN);
  elbowL.attach(ELBOW_L_PIN);
  wristR.attach(WRIST_R_PIN);
  wristL.attach(WRIST_L_PIN);
  hipR.attach(HIP_R_PIN);
  hipL.attach(HIP_L_PIN);
  kneeR.attach(KNEE_R_PIN);
  kneeL.attach(KNEE_L_PIN);
  ankleR.attach(ANKLE_R_PIN);
  ankleL.attach(ANKLE_L_PIN);

  // Initialize MPU6050
  Wire.begin();
  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("Failed to connect to MPU6050");
    while (1) {
      delay(10);
    }
  }

  Serial.println("MPU6050 Connected!");
}

void loop() {
  // Read MPU6050 data
  int16_t ax, ay, az;
  int16_t gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Calculate roll and pitch from accelerometer data
  float roll = atan2(ay, az) * 180 / PI;
  float pitch = atan2(-ax, az) * 180 / PI;

  // Balance the robot
  balanceRobot(roll, pitch);

  // Check if the robot has fallen
  if (isFalling()) {
    standUp();
  }

  // Example movement commands (replace with your control logic)
   moveForward();
   moveBackward();
   moveRight();
   moveLeft();

}

void balanceRobot(float roll, float pitch) {
  // Example balancing logic (you may need to fine-tune the mappings)
  int hipRAngle = map(roll, -45, 45, 45, 135);
  int hipLAngle = map(roll, -45, 45, 135, 45);
  int ankleRAngle = map(pitch, -45, 45, 135, 45);
  int ankleLAngle = map(pitch, -45, 45, 135, 45);

  hipR.write(hipRAngle);
  hipL.write(hipLAngle);
  ankleR.write(ankleRAngle);
  ankleL.write(ankleLAngle);
}

bool isFalling() {
  // Check if the robot is falling based on MPU6050 data
  int16_t ax, ay, az;
  int16_t gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Calculate the total acceleration magnitude
  float accelerationMagnitude = sqrt(ax * ax + ay * ay + az * az) / 16384.0;

  // If the magnitude is below a threshold, the robot is falling
  return accelerationMagnitude < 0.5;
}

void standUp() {
  // Move servos to stand up the robot (example sequence)
  hipR.write(90);
  hipL.write(90);
  kneeR.write(90);
  kneeL.write(90);
  ankleR.write(90);
  ankleL.write(90);
  delay(2000);

  // Additional movements to ensure proper standing posture
  hipR.write(45);
  hipL.write(45);
  kneeR.write(45);
  kneeL.write(45);
  delay(1000);
  hipR.write(90);
  hipL.write(90);
}

void moveForward() {
  // Move the robot forward using a walking motion
  // Example sequence (you may need to fine-tune these values)
  hipR.write(45);
  hipL.write(45);
  kneeR.write(90);
  kneeL.write(90);
  ankleR.write(45);
  ankleL.write(45);
  delay(1000);
  hipR.write(90);
  hipL.write(90);
  kneeR.write(45);
  kneeL.write(45);
  ankleR.write(90);
  ankleL.write(90);
  delay(1000);
}

void moveBackward() {
  // Move the robot backward using a walking motion
  // Example sequence (you may need to fine-tune these values)
  hipR.write(135);
  hipL.write(135);
  kneeR.write(90);
  kneeL.write(90);
  ankleR.write(135);
  ankleL.write(135);
  delay(1000);
  hipR.write(90);
  hipL.write(90);
  kneeR.write(135);
  kneeL.write(135);
  ankleR.write(90);
  ankleL.write(90);
  delay(1000);
}

void moveRight() {
  // Move the robot to the right using a stepping motion
  // Example sequence (you may need to fine-tune these values)
  hipR.write(45);
  hipL.write(90);
  kneeR.write(90);
  kneeL.write(90);
  ankleR.write(45);
  ankleL.write(90);
  delay(1000);
  hipR.write(90);
  hipL.write(45);
  kneeR.write(45);
  kneeL.write(90);
  ankleR.write(90);
  ankleL.write(45);
  delay(1000);
}

void moveLeft() {
  // Move the robot to the left using a stepping motion
  // Example sequence (you may need to fine-tune these values)
  hipR.write(90);
  hipL.write(45);
  kneeR.write(90);
  kneeL.write(90);
  ankleR.write(90);
  ankleL.write(45);
  delay(1000);
  hipR.write(45);
  hipL.write(90);
  kneeR.write(90);
  kneeL.write(45);
  ankleR.write(45);
  ankleL.write(90);
  delay(1000);
}

