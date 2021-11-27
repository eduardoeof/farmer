#include "logic.h"

#include <RTClib.h> // Include DateTime

#define LIGHT_ON_HOUR_BEGIN 8
#define LIGHT_ON_HOUR_END 20

bool Logic::shouldLightOn(const DateTime &now) {
  return (now.hour() >= LIGHT_ON_HOUR_BEGIN) &&
         (now.hour() < LIGHT_ON_HOUR_END);
}

