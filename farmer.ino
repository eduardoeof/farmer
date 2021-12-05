#include "src/io/monitor.h"
#include "src/io/clock.h"
#include "src/io/light.h"
#include "src/io/liquid-temperature-sensor.h"
#include "src/logic.h"

#include <RTClib.h> // Include DateTime

Monitor monitor;
Clock clock;
Logic logic;
Light light;
LiquidTemperatureSensor liquidTemp;

void setup() {
  monitor.setup();
  clock.setup();
  light.setup();
  liquidTemp.setup();

  delayToFinishSetup();
}

void loop() {
  DateTime now = clock.now();
  float liquidTemperature = liquidTemp.getTemperature();
  bool lightOn = logic.shouldLightOn(now);

  if (lightOn) {
    light.turnOn();
  } else {
    light.turnOff();
  }

  monitor.print("Heath check", now, liquidTemperature, lightOn);

  delay(logic.getDelayTime());
}

void delayToFinishSetup() {
  delay(1000); // Without this delay, the loop code is executed two time before its delay works
}
