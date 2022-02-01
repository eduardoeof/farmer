#include "water-pump.h"

#include "../config.h"

#include <Arduino.h>

void WaterPump::setup() {
  pinMode(WATER_PUMP_DIGITAL_PIN, OUTPUT);
}

void WaterPump::turnOn() {
  // For some reason, the relay used turn on when the port gets LOW
  digitalWrite(WATER_PUMP_DIGITAL_PIN, LOW);
}

void WaterPump::turnOff() {
  digitalWrite(WATER_PUMP_DIGITAL_PIN, HIGH);
}

