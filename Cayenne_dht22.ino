#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>
#include "DHT.h"
#include <Wire.h>
#define DHTPIN 4 // DHT22
#define DHTTYPE DHT22
// WiFi network info.
char ssid[] = "name"; 
char wifiPassword[] = "pass";

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "user"; 
char password[] = "pass"; 
char clientID[] = "id";

unsigned long lastMillis = 0;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Cayenne.begin(username, password, clientID, ssid, wifiPassword);
  dht.begin();
  Wire.begin(5, 4); // SDA, SDL
   
}


void loop() {
  Cayenne.loop();

  float humidity = dht.readHumidity();

  float temp = dht.readTemperature();
    
  Cayenne.virtualWrite(1, temp, TYPE_TEMPERATURE, UNIT_CELSIUS);
  Cayenne.virtualWrite(2, humidity, TYPE_RELATIVE_HUMIDITY, UNIT_PERCENT);
    
 }

 // todo - update   sleep mode
