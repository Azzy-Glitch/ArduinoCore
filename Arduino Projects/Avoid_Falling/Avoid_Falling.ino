int trig_pin1=3;
int echo_pin1=4;

int trig_pin2=5;
int echo_pin2=6;

int m1_A=7;
int m1_B=8;
int m2_A=9;
int m2_B=10;

int m1_En=11;
int m2_En=12;

void setup() {
  // put your setup code here, to run once:
pinMode(trig_pin1,OUTPUT);
pinMode(echo_pin1,INPUT);

pinMode(trig_pin2,OUTPUT);
pinMode(echo_pin2,INPUT);

pinMode(m1_A,OUTPUT);
pinMode(m1_B,OUTPUT);
pinMode(m2_A,OUTPUT);
pinMode(m2_B,OUTPUT);

pinMode(m1_En,OUTPUT);
pinMode(m2_En,OUTPUT);

analogWrite(m1_En,110);
analogWrite(m2_En,110);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trig_pin1,HIGH);
digitalWrite(trig_pin2,HIGH);
 delay(500);
digitalWrite(trig_pin1,LOW);
digitalWrite(trig_pin2,LOW);

int duration_1 = pulseIn(echo_pin1,HIGH);
int duration_2 = pulseIn(echo_pin2,HIGH);

int distance_1 = (duration_1 * 0.034) / 2;
int distance_2 = (duration_2 * 0.034) / 2;

if(distance_1 > 5 && distance_2 > 5)
{
Stop();
 //delay(500);

Back();
 //delay(500);

Right();
 //delay(500);

Forward();

}

else if(distance_1 > 5)
{
Stop();
//delay();
Back();
//delay();
Left();
//delay();
Forward();
}
else if(distance_2 > 5)
{
Stop();
//delay();
Back();
//delay();
Right();
//delay();
Forward();
}
else 
{
  Forward();
}

//delay(500);

}

void Forward(void)
{
digitalWrite(m1_A,HIGH);
digitalWrite(m1_B,LOW);

digitalWrite(m2_A,HIGH);
digitalWrite(m2_B,LOW);
}

void Stop(void)
{
digitalWrite(m1_A,LOW);
digitalWrite(m1_B,LOW);

digitalWrite(m2_A,LOW);
digitalWrite(m2_B,LOW);
}

void Back(void)
{
digitalWrite(m1_A,LOW);
digitalWrite(m1_B,HIGH);

digitalWrite(m2_A,LOW);
digitalWrite(m2_B,HIGH);
}

void Right(void)
{
digitalWrite(m1_A,HIGH);
digitalWrite(m1_B,LOW);

digitalWrite(m2_A,LOW);
digitalWrite(m2_B,HIGH);
}

void Left(void)
{
digitalWrite(m1_A,LOW);
digitalWrite(m2_A,HIGH);

digitalWrite(m2_A,HIGH);
digitalWrite(m2_B,LOW);
}
