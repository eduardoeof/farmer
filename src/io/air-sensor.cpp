#include "air-sensor.h"

#include "DHT.h"

#include "../config.h"

#define DHT_TYPE DHT11

AirSensorIO::AirSensorIO() : dht(new DHT(AIR_SENSOR_DIGITAL_PIN, DHT_TYPE)) {}

void AirSensorIO::setup() {
  dht->begin();
}

float AirSensorIO::getTemperature() {
  return dht->readTemperature();

}

float AirSensorIO::getHumidity() {
  return dht->readHumidity();
}

