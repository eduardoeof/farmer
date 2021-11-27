#include "monitor.h"

#include <Arduino.h>
#include <RTClib.h> // Include DateTime

void Monitor::setup() {
  Serial.begin(9600);
  while (!Serial); // wait for serial port to connect
}

void Monitor::print(const DateTime &timestamp) {
  char datetime[40];
  sprintf(datetime, "%d/%d/%d %d:%d:%d", timestamp.day(), timestamp.month(), timestamp.year(), timestamp.hour(), timestamp.minute(), timestamp.second());

  Serial.println(datetime);
}

void Monitor::print(const char message[]) {
  Serial.println(message);
}

