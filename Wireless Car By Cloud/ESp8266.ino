#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>

// ===== WiFi =====
const char* WIFI_SSID = "Yes";
const char* WIFI_PASS = "12345678900";

// ===== MQTT =====
const char* MQTT_BROKER = "d926ca8ce9ed4dd7980ecb3cded1608b.s1.eu.hivemq.cloud";
const int   MQTT_PORT   = 8883;
const char* MQTT_USER   = "Wireless_Car";
const char* MQTT_PASS   = "Abdallah2112004";
const char* MQTT_TOPIC = "car/abdallah/car-esp1/cmd";

WiFiClientSecure net;
PubSubClient client(net);

// ================= MQTT CALLBACK =================
void callback(char* topic, byte* payload, unsigned int length) {
  if (length != 1) return;

  char cmd = payload[0];
  Serial.print("CMD -> Arduino: ");
  Serial.println(cmd);

  Serial.write(cmd);
}

// ================= SETUP =================
void setup() {
  Serial.begin(9600);
  delay(1000);

  Serial.println("ESP BOOT");

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi OK");
  Serial.println(WiFi.localIP());

  net.setInsecure();
  client.setServer(MQTT_BROKER, MQTT_PORT);
  client.setCallback(callback);

  while (!client.connected()) {
    Serial.print("MQTT...");
    client.connect("ESP8266_CAR", MQTT_USER, MQTT_PASS);
    delay(500);
  }

  Serial.println("\nMQTT OK");
  client.subscribe(MQTT_TOPIC);
}

// ================= LOOP =================
void loop() {
  client.loop();
}
