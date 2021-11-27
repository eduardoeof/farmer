#include "src/io/monitor.h"
#include "src/io/clock.h"

#include <RTClib.h> // Include DateTime

Monitor monitor;
Clock clock;

void setup() {
  monitor.setup();
  clock.setup();
}

void loop() {
  monitor.print(clock.now());
  
  delay(1000);
}

