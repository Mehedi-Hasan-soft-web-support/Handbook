#define PIR_PIN 2
#define RELAY_PIN 8

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  
  digitalWrite(RELAY_PIN, LOW); // Relay OFF initially
  Serial.begin(9600);
}

void loop() {
  int motion = digitalRead(PIR_PIN);

  if (motion == HIGH) {
    Serial.println("Motion Detected!");
    digitalWrite(RELAY_PIN, HIGH); // Relay ON
  } 
  else {
    Serial.println("No Motion");
    digitalWrite(RELAY_PIN, LOW); // Relay OFF
  }

  delay(500);
}
