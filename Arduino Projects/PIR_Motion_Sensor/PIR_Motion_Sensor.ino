//                                           PIR Motion Sensor
int pirsensor = 0;
// Data Type Variable Name Value
void setup() {
// put your setup code here, to run once:
pinMode(13, OUTPUT);
pinMode(2, INPUT);
}
void loop() {
// put your main code here, to run repeatedly:
pirsensor = digitalRead(2);
if (pirsensor == HIGH)
{
digitalWrite(13, HIGH);
}
else
{
digitalWrite(13, LOW);
}
delay(10);
}
