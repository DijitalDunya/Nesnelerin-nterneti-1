#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
#define FIREBASE_HOST "https://iot1-c13c7.firebaseio.com"
#define FIREBASE_AUTH "wrRl3OwKogTjnkVWdqjV4zqytImKpic13kKIuqHC"
#define WIFI_SSID "IOT_NETWORK"
#define WIFI_PASSWORD "12345678"
FirebaseData Data;
String gelen;
void setup() {
    Serial.begin(9600);
   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
   Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  pinMode(14,OUTPUT);//D5 led_pin
  digitalWrite(14,LOW);
 
}

void loop() {
Firebase.getString(Data,"deger",gelen);
delay(50);
if(gelen=="1"){
  digitalWrite(14,HIGH);
  delay(50);
}
else if(gelen=="0"){
  digitalWrite(14,LOW);
  delay(50);
}

}
