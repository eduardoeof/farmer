#include "water-pump.h"

#include "../config.h"

#include <Arduino.h>

void WaterPump::setup() {
  pinMode(WATER_PUMP_DIGITAL_PIN, OUTPUT);
}

void WaterPump::turnOn() {
  digitalWrite(WATER_PUMP_DIGITAL_PIN, LOW);
}

void WaterPump::turnOff() {
  digitalWrite(WATER_PUMP_DIGITAL_PIN, HIGH);
}

