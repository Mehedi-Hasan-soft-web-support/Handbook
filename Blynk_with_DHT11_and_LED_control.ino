#define BLYNK_TEMPLATE_ID "TMPL6gWs2ltWJ"
#define BLYNK_TEMPLATE_NAME "Home"
#define BLYNK_AUTH_TOKEN "zOzEAmNmbvUz537JoPY3_0f20aMINiFo"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

// WiFi
char ssid[] = "Me";
char pass[] = "mehedi113";

// LED pin
#define LED_PIN 2   // GPIO 2 (change if needed)

// DHT setup
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Timer
BlynkTimer timer;

// 🔘 LED control from Blynk (V2)
BLYNK_WRITE(V2) {
  int value = param.asInt();   // 0 or 1
  digitalWrite(LED_PIN, value);
}

// 🌡️ Send DHT data to Blynk
void sendDHTData() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("DHT read failed!");
    return;
  }

  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" °C | Humidity: ");
  Serial.println(humidity);

  // Send to Blynk
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, humidity);
}

void setup() {
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  dht.begin();

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Read DHT every 2 seconds
  timer.setInterval(2000L, sendDHTData);
}

void loop() {
  Blynk.run();
  timer.run();
}
