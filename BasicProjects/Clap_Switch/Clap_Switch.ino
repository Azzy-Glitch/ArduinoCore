//                                              Clap Switch
int mic = 0;
void setup() {
pinMode(A0, INPUT);
pinMode(13, OUTPUT);
digitalWrite(13, LOW);
}
void loop() {
mic = analogRead(A0);
if (mic > 200) {
digitalWrite(13, HIGH);
delay(1000);
}
if (mic < 200) {
digitalWrite(13, LOW);
}
delay(1000);
}