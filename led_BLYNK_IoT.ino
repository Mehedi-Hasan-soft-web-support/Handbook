#define BLYNK_TEMPLATE_ID "TMPL6gWs2ltWJ"
#define BLYNK_TEMPLATE_NAME "Home"
#define BLYNK_AUTH_TOKEN "zOzEAmNmbvUz537JoPY3_0f20aMINiFo"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Me";
char pass[] = "mehedi113";

void setup(){
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop(){
  Blynk.run();
}
