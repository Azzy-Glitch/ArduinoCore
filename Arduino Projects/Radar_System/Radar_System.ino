#include <Servo.h>

#define T 3
#define E 4
Servo s1;

void setup() {

pinMode(T,OUTPUT);
pinMode(E,INPUT);
Serial.begin(9600);
s1.attach(5);

}

void loop() {
  for(int i=0;i<=180;i++){
    s1.write(i);
    delay(50);
    int distance=myfunction();
    Serial.print(distance);
  }
  for(int i=180;i>0;i--){
    s1.write(i);
    delay(50);
    int distance=myfunction();
    Serial.print(distance);
  }

}
int myfunction(){
  digitalWrite(T,LOW);
  delay(10);
  digitalWrite(T,HIGH);
  delay(20);
  digitalWrite(T,LOW);
  delay(20);
  int duration=pulseIn(E,HIGH);
  int distance=duration*0.034/2;
  return distance;
}