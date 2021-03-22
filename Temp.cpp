#include "Adafruit_DHT.h"

#define DHTPIN 1

#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
	Serial.begin(9600); 
	Serial.println("DHTxx test!");

	dht.begin();
}

void loop() {
	delay(30000);

    // Read temperature as Celsius
	float t = dht.getTempCelcius();

	Particle.publish("temperature", String(t), PRIVATE);
}

