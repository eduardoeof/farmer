#include "src/io/monitor.h"
#include "src/io/clock.h"
#include "src/logic.h"

#include <RTClib.h> // Include DateTime

Monitor monitor;
Clock clock;
Logic logic;

void setup() {
  monitor.setup();
  clock.setup();
}

void loop() {
  DateTime now = clock.now();

  monitor.print(now);
 
  if (logic.shouldLightOn(now)) {
    monitor.print("YES!!!");
  } else {
    monitor.print("NO!!!");
  }

  delay(1000);
}

