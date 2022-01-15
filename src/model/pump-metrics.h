#ifndef PUMP_METRICS_HEADER
#define PUMP_METRICS_HEADER

class DateTime;

class PumpMetrics {

public:
  PumpMetrics(const DateTime &tOnAt);
  PumpMetrics(const DateTime &tOnAt, const DateTime *tOffAt);

  bool getOn();
  DateTime getTurnedOnAt();
  DateTime * getTurnedOffAt();
  
private:
  const bool on;
  const DateTime &turnedOnAt;
  const DateTime *turnedOffAt;
};

#endif
