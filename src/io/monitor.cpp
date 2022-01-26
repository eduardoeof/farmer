#include "monitor.h"

#include <Arduino.h>
#include <RTClib.h> // Include DateTime

#include "../model/metrics.h"

void Monitor::setup() {
  Serial.begin(9600);
  while (!Serial)
    ; // wait for serial port to connect
}

void Monitor::print(const DateTime &timestamp) {
  char datetime[40];
  sprintf(datetime, "%d/%d/%d %d:%d:%d", timestamp.day(), timestamp.month(),
          timestamp.year(), timestamp.hour(), timestamp.minute(),
          timestamp.second());

  Serial.println(datetime);
}

void Monitor::print(const char message[]) { Serial.println(message); }

void Monitor::print(const char message[], const DateTime &timestamp,
                    float liquidTemperature, bool lightOn, int waterLevel) {
  String lightOnStr = lightOn ? "On" : "Off";
  char liquidTemperatureStr[6];
  dtostrf(liquidTemperature, 4, 2, liquidTemperatureStr);

  char data[100];
  sprintf(data, "%d/%d/%d %d:%d:%d | LT %s°C | Light %s | WL %d | %s", 
          timestamp.day(), timestamp.month(), timestamp.year(),
          timestamp.hour(), timestamp.minute(), timestamp.second(),
          liquidTemperatureStr, lightOnStr.c_str(), waterLevel, message);

  Serial.println(data);
}

void Monitor::print(const char message[], const Metrics &metrics) {
  DateTime now = metrics.now;
  String lightOn = metrics.lightOn ? "On" : "Off";
  String waterPumpOn = metrics.waterPumpOn ? "On" : "Off";
  char waterTemperatureStr[6];
  dtostrf(metrics.waterTemperature, 4, 2, waterTemperatureStr);

  char data[100];
  sprintf(data, "%d/%d/%d %d:%d:%d | LT %s°C | Light %s | Pump %s | WL %d | %s", 
          now.day(), now.month(), now.year(),
          now.hour(), now.minute(), now.second(),
          waterTemperatureStr, lightOn.c_str(), waterPumpOn.c_str(),
          metrics.waterLevel, message);

  Serial.println(data);
}
