#define BLYNK_TEMPLATE_ID "TMPL6IfsLuBda"
#define BLYNK_TEMPLATE_NAME "Azzy"
#define BLYNK_AUTH_TOKEN "z1HsYmxscnCDy_a9LFVYsc3ApXlU4s8H"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "z1HsYmxscnCDy_a9LFVYsc3ApXlU4s8H";
char ssid[] = "OG";
char pass[] = "mega peer";

// Relay pins
int lightRelay = D1;
int fanRelay   = D2;

void setup()
{
  Serial.begin(9600);

  pinMode(lightRelay, OUTPUT);
  pinMode(fanRelay, OUTPUT);

  digitalWrite(lightRelay, HIGH);
  digitalWrite(fanRelay, HIGH);

  Blynk.begin(auth, ssid, pass);
}

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  digitalWrite(lightRelay, value == 1 ? LOW : HIGH);
}

BLYNK_WRITE(V1)
{
  int value = param.asInt();
  digitalWrite(fanRelay, value == 1 ? LOW : HIGH);
}

void loop()
{
  Blynk.run();
}
