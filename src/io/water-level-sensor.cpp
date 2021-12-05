#include "water-level-sensor.h"

#include "../config.h"

void WaterLevelSensor::setup() {
  pinMode(WATER_LEVEL_POWER_DIGITAL_PIN, OUTPUT);
  digitalWrite(WATER_LEVEL_POWER_DIGITAL_PIN, LOW);
}

int WaterLevelSensor::getLevel() {
  digitalWrite(WATER_LEVEL_POWER_DIGITAL_PIN, HIGH);

  delay(10);

  int level = analogRead(WATER_LEVEL_SIGNAL_ANALOG_PIN);

  digitalWrite(WATER_LEVEL_POWER_DIGITAL_PIN, LOW);

  return level;
} 

