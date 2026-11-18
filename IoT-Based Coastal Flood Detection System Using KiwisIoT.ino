#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

// WiFi Credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

// KiwisIoT Topic ID
const char* topic = "YOUR_TOPIC_ID";

// Sensor Pins
#define TRIG_PIN D5
#define ECHO_PIN D6
#define RAIN_PIN D7

// Installation Configuration
// Distance from sensor to ground/reference
const float SENSOR_HEIGHT_CM = 200.0;

// Minimum safe clearance above reference
const float FLOOD_LEVEL_CM = 50.0;

// KiwisIoT
KiwisIoT kiwisiot(ssid, pass, topic);

unsigned long previousMillis = 0;

float readDistance() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration =
    pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    return -1;
  }

  float distance =
    duration * 0.0343 / 2.0;

  return distance;
}

void setup() {

  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(RAIN_PIN, INPUT);

  kiwisiot.begin();

  Serial.println("Coastal Flood Detection Started");
}

void loop() {

  kiwisiot.run();

  if (millis() - previousMillis >= 5000) {

    previousMillis = millis();

    float distance = readDistance();

    int rainStatus = digitalRead(RAIN_PIN);

    String rainCondition =
      (rainStatus == LOW) ? "RAIN" : "NO RAIN";

    if (distance > 0 &&
        distance < SENSOR_HEIGHT_CM) {

      float waterLevel =
        SENSOR_HEIGHT_CM - distance;

      float clearance =
        distance;

      String floodStatus =
        (clearance <= FLOOD_LEVEL_CM)
        ? "FLOOD ALERT"
        : "NORMAL";

      Serial.println("\n--- COASTAL FLOOD DATA ---");

      Serial.print("Water Distance: ");
      Serial.print(distance);
      Serial.println(" cm");

      Serial.print("Water Level: ");
      Serial.print(waterLevel);
      Serial.println(" cm");

      Serial.print("Rain Status: ");
      Serial.println(rainCondition);

      Serial.print("Flood Status: ");
      Serial.println(floodStatus);

      // Send data to KiwisIoT
      kiwisiot.send("0", String(distance, 2));

      kiwisiot.send("1", String(waterLevel, 2));

      kiwisiot.send("2", rainCondition);

      kiwisiot.send("3", floodStatus);

    } else {

      Serial.println("Invalid Ultrasonic Reading");

    }
  }
}