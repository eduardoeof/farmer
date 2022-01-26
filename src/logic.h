#ifndef LOGIC_HEADER
#define LOGIC_HEADER

class DateTime;
class PumpMetrics;

class Logic {

public:
  unsigned long getLoopDelay();
  bool shouldLightOn(const DateTime &now);
  bool shouldWaterPumpOn(const DateTime &now);
};

#endif
