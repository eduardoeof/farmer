#include "oled-display.h"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RTClib.h> // Include DateTime

#include "../model/metrics.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define WATER_TEMPERATURE_LINE "WTemp:  %s C"
#define LIGHT_LINE             "Light:  %s"
#define WATER_LEVEL_LINE       "Wlevel: %d"
#define WATER_PUMP_LINE        "WPump:  %s" 

OLEDDisplay::OLEDDisplay() {
  display = new Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
}

void OLEDDisplay::setup() {
  bool displayStarted = display->begin(SSD1306_SWITCHCAPVCC, 0x3C);

  if(!displayStarted) {
    Serial.println(F("ERROR - SSD1306 allocation failed"));
    while(true);
  }
}

void OLEDDisplay::print(const Metrics &metrics) {
  display->clearDisplay();
  display->setTextSize(1);
  display->setTextColor(WHITE);

  char line[20];
  buildTitleLine(metrics.now, line);
  display->setCursor(0, 0);
  display->println(line);

  buildTemperatureLine(metrics.waterTemperature, line);
  display->setCursor(0, 16);
  display->println(line);

  buildLightLine(metrics.lightOn, line);
  display->println(line);

  buildWaterLevelLine(metrics.waterLevel, line);
  display->println(line);

  buildWaterPumpLine(metrics.waterPumpOn, line);
  display->println(line);

  display->display(); 
}

void OLEDDisplay::buildTitleLine(const DateTime &timestamp, char *line) {
  sprintf(line, "%d/%d/%d %d:%d:%d", 
      timestamp.day(), timestamp.month(), timestamp.year(), 
      timestamp.hour(), timestamp.minute(), timestamp.second());
}

void OLEDDisplay::buildTemperatureLine(float temperature, char *line) {
  char temperatureStr[10];
  dtostrf(temperature, 4, 2, temperatureStr);
  sprintf(line, WATER_TEMPERATURE_LINE, temperatureStr);
}

void OLEDDisplay::buildLightLine(bool lightOn, char *line) {
  sprintf(line, LIGHT_LINE, lightOn ? "On" : "Off");
}

void OLEDDisplay::buildWaterLevelLine(int waterLevel, char *line) {
  sprintf(line, WATER_LEVEL_LINE, waterLevel);
}

void OLEDDisplay::buildWaterPumpLine(bool waterPumpOn, char *line) {
  sprintf(line, WATER_PUMP_LINE, waterPumpOn ? "On" : "Off");
}
