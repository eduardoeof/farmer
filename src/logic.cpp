#include "logic.h"

#include "config.h"

#include <RTClib.h> // Include DateTime

bool Logic::shouldLightOn(const DateTime &now) {
  return (now.hour() >= LIGHT_ON_START_HOUR) &&
         (now.hour() < LIGHT_ON_END_HOUR);
}

unsigned long Logic::getDelayTime() {
  return (unsigned long) DELAY_APP_SECONDS * 1000;
}

