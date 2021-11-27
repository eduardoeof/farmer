#include "light.h"

#include <Arduino.h>

#define RELAY_PIN 11

void Light::setup() {
  pinMode(RELAY_PIN, OUTPUT);
}

void Light::turnOn() {
  digitalWrite(RELAY_PIN, HIGH);
}

void Light::turnOff() {
  digitalWrite(RELAY_PIN, LOW);
}

