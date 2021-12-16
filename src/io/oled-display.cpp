#include "oled-display.h"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RTClib.h> // Include DateTime

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

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

void OLEDDisplay::print(const DateTime &timestamp, float temperature, bool lightOn, int waterLevel) {
  display->clearDisplay();
  display->setTextSize(1);
  display->setTextColor(WHITE);

  char line[20];
  buildTitleLine(timestamp, line);
  display->setCursor(0, 0);
  display->println(line);

  buildTemperatureLine(temperature, line);
  display->setCursor(0, 16);
  display->println(line);

  buildLightLine(lightOn, line);
  display->println(line);

  buildWaterLevelLine(waterLevel, line);
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
  sprintf(line, "Temp: %s oC", temperatureStr);
}

void OLEDDisplay::buildLightLine(bool lightOn, char *line) {
  sprintf(line, "Light: %s", lightOn ? "On" : "Off");
}

void OLEDDisplay::buildWaterLevelLine(int waterLevel, char *line) {
  sprintf(line, "Water level: %d", waterLevel);
}

