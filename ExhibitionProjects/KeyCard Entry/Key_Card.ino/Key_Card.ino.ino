#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define pins for MFRC522
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance

// Initialize the LCD with the I2C address (usually 0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() 
{
  // Initialize the LCD and RFID
  lcd.init(); // Initialize the LCD
  lcd.backlight(); // Turn on the backlight
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600); // Initiate a serial communication
  SPI.begin(); // Initiate SPI bus
  mfrc522.PCD_Init(); // Initiate MFRC522

  // Initial LCD display
  lcd.setCursor(0, 0);
  lcd.print("Approximate card");
  lcd.setCursor(0, 1);
  lcd.print("to reader...");
  Serial.println("Approximate your card to the reader...");
  Serial.println();
}

void loop() 
{
  // Look for new cards
  if (!mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  
  // Select one of the cards
  if (!mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }

  // Show UID on serial monitor
  Serial.print("UID tag: ");
  String content = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message: ");
  content.toUpperCase();
  
  lcd.clear(); // Clear the LCD screen
  if (content.substring(1).equalsIgnoreCase("F9 D1 F3 6E")) // Change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
    lcd.setCursor(0, 0);
    lcd.print("Welcome");

    for (int i = 0; i < 3; i++) {
      digitalWrite(6, HIGH);
      delay(200);
      digitalWrite(6, LOW);
      delay(200);
    }
  }
  else 
  {
    Serial.println("Access denied");
    Serial.println();
    lcd.setCursor(0, 0);
    lcd.print("NOT READ");
    digitalWrite(6, HIGH); // Light up LED on pin 6

    delay(1000); // Keep the LED and message for 1 second
    digitalWrite(6, LOW); // Turn off the LED
  }
}
