#include<WiFiClient.h>
#include<ESP8266WiFi.h>
#include<SoftwareSerial.h>
// #include <ArduinoJson.h>
// SoftwareSerial nodemcu(D6, D5); // Rx=D6, TX = D5
String apiKey = "3HCHS5G28VE0GULR";  
String network_name =  "Mega_Pro";   
String network_pass =  "Mega_Pro";
String network_server = "api.thingspeak.com";
   WiFiClient client;
void setup(){
Serial.begin(9600);
//  nodemcu.begin(9600);
//  while(!Serial) continue;
  WiFi.begin(network_name, network_pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  Serial.println("connected");
}
void loop (){
  // StaticJsonDocument<1000> data;
  // DeserializationError error = deserializeJson(data, nodemcu);
  // if(error){
  //   return; 
  // }
  // int soil_temperature = data["soil_temp"];
  // int air_temperature = data["air_temp"];
  // int air_humidity_per = data["air_hum"];
  // int light_level =  data["light"]; ;
  // int soilMoisture_per = data["soil_Moisture;"];
  // int air_quality_per = data["air_quality"];
  // int water_toUse_level_per = data["water_toUse_level"];
  // int water_storage_level_per = data["water_storage_level"];
  
if (Serial.available()) {
  String data = Serial.readStringUntil('\n');
  int commaIndex = 0;
  float soil_temperature = data.substring(0, commaIndex = data.indexOf(',')).toInt();
  data.remove(0, commaIndex + 1);
  int soilMoisture_per = data.substring(0, commaIndex = data.indexOf(',')).toInt();
  data.remove(0, commaIndex + 1);
  float air_temperature =  data.substring(0, commaIndex = data.indexOf(',')).toInt();
  data.remove(0, commaIndex + 1);
  int air_humidity_per = data.substring(0, commaIndex = data.indexOf(',')).toInt();
  data.remove(0, commaIndex + 1);
  int air_quality_per = data.substring(0, commaIndex = data.indexOf(',')).toInt();
  data.remove(0, commaIndex + 1);
  int light_level = data.substring(0, commaIndex = data.indexOf(',')).toInt();
  data.remove(0, commaIndex + 1);
  int water_storage_level_per =data.substring(0, commaIndex = data.indexOf(',')).toInt();
  data.remove(0);
  int water_toUse_level_per = data.substring(0, commaIndex = data.indexOf(',')).toInt();
  data.remove(0, commaIndex + 1);
// Serial.println(soil_temperature);
// Serial.println(air_temperature);
// Serial.println(air_humidity_per);
// Serial.println(light_level);
// Serial.println(soilMoisture_per);
// Serial.println(air_quality_per);
// Serial.println(water_toUse_level_per);
// Serial.println(water_storage_level_per);
  
    if (client.connect(network_server, 80)){
    String postStr = apiKey;
    postStr += "&field1=";
    postStr += String(soil_temperature);
    postStr += "&field2=";
    postStr += String(soilMoisture_per);
    postStr += "&field3=";
    postStr += String(air_temperature);
    postStr += "&field4=";
    postStr += String(air_humidity_per);
    postStr += "&field5=";
    postStr += String(air_quality_per);
    postStr += "&field6=";
    postStr += String(light_level);
    postStr += "&field7=";
    postStr += String(water_storage_level_per);
    postStr += "&field8=";
    postStr += String(water_toUse_level_per);
    postStr += "\r\n\r\n";
    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);
    }
  client.stop();
}
delay(1500);
}
 