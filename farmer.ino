#include "src/io/monitor.h"
#include "src/io/clock.h"
#include "src/io/light.h"
#include "src/logic.h"


#include <RTClib.h> // Include DateTime

Monitor monitor;
Clock clock;
Logic logic;
Light light;

void setup() {
  monitor.setup();
  clock.setup();
  light.setup();

  delayToFinishSetup();
}

void loop() {
  DateTime now = clock.now();

  monitor.print(now);
 
  if (logic.shouldLightOn(now)) {
    light.turnOn();
    monitor.print("Light on");
  } else {
    light.turnOff();
    monitor.print("Light off");
  }

  delay(logic.getDelayTime());
}

void delayToFinishSetup() {
  delay(1000); // Without this delay, the loop code is executed two time before its delay works
}
