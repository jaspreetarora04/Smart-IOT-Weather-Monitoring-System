// Replace with your Blynk credentials
#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <Adafruit_BMP280.h>
#include <HTTPClient.h>

// Replace with your WiFi credentials
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

DHT dht(4, DHT22);
Adafruit_BMP280 bmp;

#define RAIN_PIN 34
String apiKey = "YOUR_THINGSPEAK_APIKEY";

BlynkTimer timer;

void sendData() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  float p = bmp.readPressure() / 100.0;
  int rain = analogRead(RAIN_PIN);

  // Error check
  if (isnan(t) || isnan(h) || p == 0) return;

  // Blynk
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  Blynk.virtualWrite(V2, p);
  Blynk.virtualWrite(V3, rain);

  // Alerts
  if (t > 35) Blynk.logEvent("temp_alert");
  if (h > 80) Blynk.logEvent("humidity_alert");

  // Decision logic
  if (h > 70 && p < 1000) Blynk.logEvent("rain_alert");

  // ThingSpeak
  HTTPClient http;
  String url = "http://api.thingspeak.com/update?api_key=" + apiKey +
               "&field1=" + t + "&field2=" + h +
               "&field3=" + p + "&field4=" + rain;
  http.begin(url);
  http.GET();
  http.end();
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  bmp.begin(0x76);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(3000L, sendData);
}

void loop() {
  Blynk.run();
  timer.run();
}
