#ifndef METRICS_MODEL_HEADER
#define METRICS_MODEL_HEADER

class DateTime;

class Metrics {
public:
  Metrics(const DateTime &now, float waterTemperature, int waterLevel,
          bool lightOn, bool waterPumpOn, float airTemperature, float humidity);

  const DateTime &now;
  const float waterTemperature;
  const int waterLevel;
  const bool lightOn;
  const bool waterPumpOn;
  const float airTemperature;
  const float humidity;
};

#endif
