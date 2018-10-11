#include <Arduino.h>
#include <ESP8266WiFi.h>

const char* ssid = "BYU-WiFi";
const char* password = "";

long rssi;

void setup() {
  Serial.begin(9600);
  Serial.println("\nESP8266 WiFi Signal Strength");
  Serial.print("Connecting to '");
  Serial.print(ssid);
  Serial.println("' network");
  Serial.print("MAC: ");
  Serial.println(WiFi.macAddress());
  
  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.hostname("todddb-arduino");
  WiFi.begin(ssid,password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Print the IP address
  Serial.print("IP address: ");
  Serial.print(WiFi.localIP());
}


void loop() {
  // put your main code here, to run repeatedly:
  rssi = WiFi.RSSI();
  Serial.println(rssi);
  delay(1000);
}
