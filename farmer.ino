#include "src/io/monitor.h"
#include "src/io/clock.h"
#include "src/io/light.h"
#include "src/io/liquid-temperature-sensor.h"
#include "src/io/water-level-sensor.h"
#include "src/io/oled-display.h"
#include "src/logic.h"

#include <RTClib.h> // Include DateTime

Monitor monitor;
Clock clock;
Logic logic;
Light light;
LiquidTemperatureSensor liquidTemperatureSensor;
WaterLevelSensor waterLevelSensor;
OLEDDisplay display;

void setup() {
  monitor.setup();
  clock.setup();
  light.setup();
  liquidTemperatureSensor.setup();
  waterLevelSensor.setup();
  display.setup();

  delayToFinishSetup();
}

void loop() {
  DateTime now = clock.now();
  float temperature = liquidTemperatureSensor.getTemperature();
  bool lightOn = logic.shouldLightOn(now);
  int waterLevel = waterLevelSensor.getLevel();

  if (lightOn) {
    light.turnOn();
  } else {
    light.turnOff();
  }

  display.print(now, temperature, lightOn, waterLevel);
  monitor.print("Heath check", now, temperature, lightOn, waterLevel);

  delay(logic.getLoopDelay());
}

void delayToFinishSetup() {
  delay(1000); // Without this delay, the loop code is executed two time before its delay works
}
