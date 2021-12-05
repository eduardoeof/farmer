#include "liquid-temperature-sensor.h"

#include "../config.h"

#include <OneWire.h> 
#include <DallasTemperature.h>

LiquidTemperatureSensor::LiquidTemperatureSensor() {
  oneWire = new OneWire(LIQUID_TEMPERATURE_SENSOR_DIGITAL_PIN);
  sensor = new DallasTemperature(oneWire);
}

void LiquidTemperatureSensor::setup() {
  sensor->begin();
}

float LiquidTemperatureSensor::getTemperature() {
  sensor->requestTemperatures(); 
  return sensor->getTempCByIndex(0);
}

