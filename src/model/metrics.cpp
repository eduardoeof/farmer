#include "metrics.h"

Metrics::Metrics(const DateTime &now, float waterTemperature, int waterLevel,
                 bool lightOn, bool waterPumpOn)
    : now(now), 
      waterTemperature(waterTemperature), 
      waterLevel(waterLevel),
      lightOn(lightOn),
      waterPumpOn(waterPumpOn) {}
