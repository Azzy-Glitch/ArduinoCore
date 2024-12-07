#include <Servo.h>

const int IR1 = 10;
const int IR2 = 11;

const int LED_Green= 2;
const int LED_Red = 3;
int Count;
Servo ServoIn;

int count = 0;


void setup() {
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);

  pinMode(LED_Green, OUTPUT);
  pinMode(LED_Red, OUTPUT);

  ServoIn.attach(7);
 
  ServoIn.write(180);

  Serial.begin(9600); 
}

void loop() {
  // Handling IR1
  if (digitalRead(IR1) == LOW || digitalRead(IR2) == LOW) {
  if (Count<8)
 {
    ServoIn.write(90);
    digitalWrite(LED_Green, HIGH);
    delay(3000);
      count++;
  
    }
   
   else if(count >= 8) {
    ServoIn.write(180);
    digitalWrite(LED_Red, HIGH);
  }
  }
  // Handling IR2
  if (digitalRead(IR2) == LOW) {
    if (ServoIn.read() == 180) {
      ServoIn.write(90);
      digitalWrite(LED_Green, HIGH);
      delay(3000);
      count--;

    }
   else {
    ServoIn.write(180);
    digitalWrite(LED_Red, HIGH);
    delay(3000);
  }
}
}