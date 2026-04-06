#include <DHT.h>
#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("DHT11 Ready!");
}

void loop() {
  delay(2000); // DHT11 is slow
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Sensor error!");
    return;
  }

  Serial.print("Temp: ");
  Serial.print(t);
  Serial.print("°C  Humidity: ");
  Serial.print(h);
  Serial.println("%");
}
