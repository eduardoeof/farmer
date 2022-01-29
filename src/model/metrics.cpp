#include "metrics.h"

Metrics::Metrics(const DateTime &now, float waterTemperature, int waterLevel,
                 bool lightOn, bool waterPumpOn, float airTemperature,
                 float humidity)
    : now(now), 
      waterTemperature(waterTemperature), 
      waterLevel(waterLevel),
      lightOn(lightOn),
      waterPumpOn(waterPumpOn),
      airTemperature(airTemperature),
      humidity(humidity) {}
