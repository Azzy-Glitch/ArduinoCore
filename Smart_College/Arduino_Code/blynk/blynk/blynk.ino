// /*************************************************************
//   Blynk is a platform with iOS and Android apps to control
//   ESP32, Arduino, Raspberry Pi and the likes over the Internet.
//   You can easily build mobile and web interfaces for any
//   projects by simply dragging and dropping widgets.

//     Downloads, docs, tutorials: https://www.blynk.io
//     Sketch generator:           https://examples.blynk.cc
//     Blynk community:            https://community.blynk.cc
//     Follow us:                  https://www.fb.com/blynkapp
//                                 https://twitter.com/blynk_app

//   Blynk library is licensed under MIT license
//  *************************************************************
//   Blynk.Edgent implements:
//   - Blynk.Inject - Dynamic WiFi credentials provisioning
//   - Blynk.Air    - Over The Air firmware updates
//   - Device state indication using a physical LED
//   - Credentials reset using a physical Button
//  *************************************************************/

// /* Fill in information from your Blynk Template here */
// /* Read more: https://bit.ly/BlynkInject */
// //#define BLYNK_TEMPLATE_ID           "TMPxxxxxx"
// //#define BLYNK_TEMPLATE_NAME         "Device"

// #define BLYNK_FIRMWARE_VERSION        "0.1.0"


// #define smallLEDsPIN 1
// #define GF_Main_LED 2
// #define FF_Main_LED 3
// #define GF_Classrooms_Doors 4
// #define FF_Classrooms_Doors 5

// #define BLYNK_TEMPLATE_ID "TMPL6J2UqXzhh"
// #define BLYNK_TEMPLATE_NAME "Smart College"

// #define BLYNK_PRINT Serial
// //#define BLYNK_DEBUG

// #define APP_DEBUG

// // Uncomment your board, or configure a custom board in Settings.h
// #define USE_ESP32_DEV_MODULE
// //#define USE_ESP32C3_DEV_MODULE
// //#define USE_ESP32S2_DEV_KIT
// //#define USE_WROVER_BOARD
// //#define USE_TTGO_T7
// //#define USE_TTGO_T_OI

// #include "BlynkEdgent.h"


// BLYNK_WRITE(V0) {
//   int pin = param.asInt();
//   digitalWrite(smallLEDsPIN, pin);
// }

// BLYNK_WRITE(V1) {
//   int pin = param.asInt();
//   digitalWrite(GF_Main_LED, pin);
// }
// BLYNK_WRITE(V2) {
//   int pin = param.asInt();
//   digitalWrite(FF_Main_LED, pin);
// }
// BLYNK_WRITE(V3) {
//   int pin = param.asInt();
//   digitalWrite(GF_Classrooms_Doors, pin);
// }
// BLYNK_WRITE(V4) {
//   int pin = param.asInt();
//   digitalWrite(FF_Classrooms_Doors, pin);
// }



// void setup()
// {
//   Serial.begin(115200);
//   delay(100);


//   BlynkEdgent.begin();
// }

// void loop() {
//   BlynkEdgent.run();
// }



/*New blynk app project
   Home Page
*/

//Include the library files
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6J2UqXzhh"
#define BLYNK_TEMPLATE_NAME "Smart College"
#define BLYNK_AUTH_TOKEN "SQpi1YhxutyfDIWY46SGtMJEkyQCdLtD"
#include <ESP8266WiFi.h>
#include <Servo.h>
#include <BlynkSimpleEsp8266.h>
//Enter your blynk auth token

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "smart";        //Enter your WIFI name
char pass[] = "smartsmart";  //Enter your WIFI password

//Get the button value

Servo GF_Dores;
Servo FF_Dores;

#define smallLEDsPIN D1
#define GF_Main_LED D2
#define FF_Main_LED D3
#define GF_Classrooms_Doors D4
#define FF_Classrooms_Doors D5

BLYNK_WRITE(V0) {
  int pin = param.asInt();
  if (pin == 0) {
    digitalWrite(smallLEDsPIN, 1);
  } else {
    digitalWrite(smallLEDsPIN, 0);
  }

  Serial.print("smallLEDsPIN ");
  Serial.println(pin);
}

BLYNK_WRITE(V1) {
  int pin = param.asInt();
  digitalWrite(GF_Main_LED, pin);
  Serial.print("GF_Main_LED ");
  Serial.println(pin);
}
BLYNK_WRITE(V2) {
  int pin = param.asInt();
  digitalWrite(FF_Main_LED, pin);
  Serial.print("FF_Main_LED ");
  Serial.println(pin);
}
BLYNK_WRITE(V3) {
  int pin = param.asInt();
  if (pin == 1) {
    GF_Dores.write(90);
    Serial.print("GF_Classrooms_Doors ");
    Serial.println(pin);
  } else {
    GF_Dores.write(0);
    Serial.print("GF_Classrooms_Doors ");
    Serial.println(pin);
  }
}
BLYNK_WRITE(V4) {
  int pin = param.asInt();
  if (pin == 1) {
    FF_Dores.write(0);
    Serial.print("FF_Classrooms_Doors ");
    Serial.println(pin);
  } else {
    FF_Dores.write(90);
    Serial.print("FF_Classrooms_Doors ");
    Serial.println(pin);
  }
}


void setup() {
  //Set the LED pin as an output pin
  pinMode(smallLEDsPIN, OUTPUT);
  Serial.begin(9600);
  pinMode(GF_Main_LED, OUTPUT);
  pinMode(FF_Main_LED, OUTPUT);
  pinMode(GF_Classrooms_Doors, OUTPUT);
  pinMode(FF_Classrooms_Doors, OUTPUT);

  digitalWrite(smallLEDsPIN, LOW);
  digitalWrite(GF_Main_LED, LOW);
  digitalWrite(FF_Main_LED, LOW);
  digitalWrite(GF_Classrooms_Doors, LOW);
  digitalWrite(FF_Classrooms_Doors, LOW);
  pinMode(D0, OUTPUT);
  GF_Dores.attach(GF_Classrooms_Doors);
  FF_Dores.attach(FF_Classrooms_Doors);
  GF_Dores.write(0);
  FF_Dores.write(0);
  //Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  //Run the Blynk library
  Blynk.run();
}
