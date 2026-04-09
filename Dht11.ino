#include <DHT.h>

#define DHTPIN 2      // Arduino UNO te digital pin 2 use koro
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);   // UNO te 9600 better
  dht.begin();
  Serial.println("DHT11 Ready!");
}

void loop() {
  delay(2000); // DHT11 slow sensor

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Sensor error!");
    return;
  }

  Serial.print("Temp: ");
  Serial.print(t);
  Serial.print(" °C  |  Humidity: ");
  Serial.print(h);
  Serial.println("%");
}
