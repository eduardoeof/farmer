#include "src/io/monitor.h"
#include "src/io/clock.h"
#include "src/io/light.h"
#include "src/io/liquid-temperature-sensor.h"
#include "src/io/water-level-sensor.h"
#include "src/io/oled-display.h"
#include "src/io/water-pump.h"
#include "src/logic.h"
#include "src/model/metrics.h"

#include <RTClib.h> // Include DateTime

Monitor monitor;
Clock clock;
Logic logic;
Light light;
LiquidTemperatureSensor liquidTemperatureSensor;
WaterLevelSensor waterLevelSensor;
OLEDDisplay display;
WaterPump waterPump;

void setup() {
  monitor.setup();
  clock.setup();
  light.setup();
  liquidTemperatureSensor.setup();
  waterLevelSensor.setup();
  display.setup();
  waterPump.setup();

  delayToFinishSetup();
}

void loop() {
  DateTime now = clock.now();

  bool lightOn = logic.shouldLightOn(now);

  if (lightOn) {
    light.turnOn();
  } else {
    light.turnOff();
  }

  bool waterPumpOn = logic.shouldWaterPumpOn(now);

  if (waterPumpOn) {
    waterPump.turnOn();
  } else {
    waterPump.turnOff();
  }

  float temperature = liquidTemperatureSensor.getTemperature();
  int waterLevel = waterLevelSensor.getLevel();
  Metrics metrics(now, temperature, waterLevel, lightOn, waterPumpOn);

  display.print(metrics);
  monitor.print("Heath check", now, temperature, lightOn, waterLevel);

  delay(logic.getLoopDelay());
}

void delayToFinishSetup() {
  delay(1000); // Without this delay, the loop code is executed two time before its delay works
}
