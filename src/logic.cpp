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
  return (now.hour() == PUMP_WATER_ON_START_CICLE_1_HOUR ||
          now.hour() == PUMP_WATER_ON_START_CICLE_2_HOUR ||
          now.hour() == PUMP_WATER_ON_START_CICLE_3_HOUR) &&
         now.minute() <= PUMP_WATER_ON_DURATION_MINUTES;
}

