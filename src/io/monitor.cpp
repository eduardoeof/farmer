#include "monitor.h"

#include <Arduino.h>
#include <RTClib.h> // Include DateTime

void Monitor::setup() {
  Serial.begin(9600);
  while (!Serial); // wait for serial port to connect
}

void Monitor::print(const DateTime &timestamp) {
  char datetime[40];
  sprintf(datetime, "%d/%d/%d %d:%d:%d", 
      timestamp.day(), timestamp.month(), timestamp.year(), 
      timestamp.hour(), timestamp.minute(), timestamp.second());

  Serial.println(datetime);
}

void Monitor::print(const char message[]) {
  Serial.println(message);
}

void Monitor::print(const char message[], const DateTime &timestamp, float liquidTemperature, bool lightOn) {
  char data[40];
  String lightOnStr = lightOn ? "On" : "Off";
  char liquidTemperatureStr [6];
  dtostrf(liquidTemperature, 4, 2, liquidTemperatureStr);

  sprintf(data, "[%d/%d/%d %d:%d:%d] [LT %s°C] [Light %s] %s", 
      timestamp.day(), timestamp.month(), timestamp.year(),
      timestamp.hour(), timestamp.minute(), timestamp.second(),
      liquidTemperatureStr, lightOnStr.c_str(), message);

  Serial.println(data);
}
