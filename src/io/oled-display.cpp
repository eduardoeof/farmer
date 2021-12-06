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

  char title[20];
  sprintf(title, "%d/%d/%d %d:%d:%d", 
      timestamp.day(), timestamp.month(), timestamp.year(), 
      timestamp.hour(), timestamp.minute(), timestamp.second());
  display->setCursor(0, 0);
  display->println(title);

  //String lightOnStr = lightOn ? "On" : "Off";
  char temperatureStr [6];
  dtostrf(temperature, 4, 2, temperatureStr);

  char body[20];
  sprintf(body, "Temp: %s oC\nLight: %s\nWater level: %d", temperatureStr, lightOn ? "On" : "Off", waterLevel);
  //sprintf(body, "Temp: %s oC\nLight: %s\nWater level: %d", temperatureStr, lightOnStr.c_str(), waterLevel);
  display->setCursor(0, 16);
  display->println(body);

  display->display(); 
}

