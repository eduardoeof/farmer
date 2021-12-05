#include "light.h"

#include "../config.h"

#include <Arduino.h>

void Light::setup() {
  pinMode(LIGHT_DIGITAL_PIN, OUTPUT);
}

void Light::turnOn() {
  digitalWrite(LIGHT_DIGITAL_PIN, HIGH);
}

void Light::turnOff() {
  digitalWrite(LIGHT_DIGITAL_PIN, LOW);
}

