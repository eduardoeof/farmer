#include "logic.h"

#include "config.h"

#include <RTClib.h> // Include DateTime

#define DATETIME_FORMAT "YYYY-MM-DDThh:mm:ss"
#define DATE_FORMAT "YYYY-MM-DD"

bool Logic::shouldLightOn(const DateTime &now) {
  return (now.hour() >= LIGHT_ON_START_HOUR) &&
         (now.hour() < LIGHT_ON_END_HOUR);
}

unsigned long Logic::getLoopDelay() {
  return (unsigned long)DELAY_APP_SECONDS * 1000;
}

bool Logic::shouldWaterPumpOn(const DateTime &now) {
  return (now.hour() == PUMP_WATER_ON_START_HOUR_1 ||
          now.hour() == PUMP_WATER_ON_START_HOUR_2) &&
         now.minute() <= PUMP_WATER_ON_DURATION_MINUTES;
}

