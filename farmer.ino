#include "src/io/monitor.h"
#include "src/io/clock.h"
#include "src/io/light.h"
#include "src/io/liquid-temperature-sensor.h"
#include "src/io/water-level-sensor.h"
#include "src/io/oled-display.h"
#include "src/io/water-pump.h"
#include "src/io/air-sensor.h"
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
AirSensorIO airSensor;

void setup() {
  monitor.setup();
  clock.setup();
  light.setup();
  liquidTemperatureSensor.setup();
  waterLevelSensor.setup();
  display.setup();
  waterPump.setup();
  airSensor.setup();

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

  float liquidTemp = liquidTemperatureSensor.getTemperature();
  float airTemp = airSensor.getTemperature();
  float humidity = airSensor.getHumidity();
  int waterLevel = waterLevelSensor.getLevel();
  Metrics metrics(now, liquidTemp, waterLevel, lightOn, waterPumpOn, airTemp, humidity);

  display.print(metrics);
  monitor.print("Heath check", metrics);

  delay(logic.getLoopDelay());
}

void delayToFinishSetup() {
  delay(1000); // Without this delay, the loop code is executed two time before its delay works
}
