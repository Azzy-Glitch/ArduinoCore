//                                         Single Button Controlled RGB LED
// this constants won't change:
const int buttonPin = 3; // the pin that the pushbutton is attached to
const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;
// Variables will change:
int buttonPushCounter = 0; // counter for the number of button presses
int buttonState = 0; // current state of the button
int lastButtonState = 0; // previous state of the button
void setup() {
// initialize the button pin as a input:
pinMode(buttonPin, INPUT);
// initialize the LED as an output:
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);
}
void loop() {
// read the pushbutton input pin:
buttonState = digitalRead(buttonPin);
// compare the buttonState to its previous state
if (buttonState != lastButtonState) {
// if the state has changed, increment the counter
if (buttonState == HIGH) {
// if the current state is HIGH then the button went from off to on:
buttonPushCounter++;
}
// Delay a little bit to avoid bouncing
delay(50);
}
// save the current state as the last state, for next time through the
loop
lastButtonState = buttonState;
if (buttonPushCounter == 0) {
digitalWrite(redPin, LOW);
digitalWrite(greenPin, LOW);
digitalWrite(bluePin, LOW);
}
else if (buttonPushCounter == 1) {
digitalWrite(redPin, HIGH);
digitalWrite(greenPin, LOW);
digitalWrite(bluePin, LOW);
}
else if (buttonPushCounter == 2) {
digitalWrite(redPin, LOW);
digitalWrite(greenPin, HIGH);
digitalWrite(bluePin, LOW);
}
else if (buttonPushCounter == 3) {
digitalWrite(redPin, LOW);
digitalWrite(greenPin, LOW);
digitalWrite(bluePin, HIGH);
}
else {
buttonPushCounter = 0;
}
}