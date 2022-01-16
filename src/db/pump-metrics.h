#ifndef PUMP_METRICS_DB
#define PUMP_METRICS_DB

#include <ArduinoJson.h>

class PumpMetrics;

class PumpMetricsDB {
public:
  void setup();
  void save(PumpMetrics &p);
  //PumpMetrics load();
};

#endif
