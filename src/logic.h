#ifndef LOGIC_HEADER
#define LOGIC_HEADER

class DateTime;
class PumpMetrics;
class String;

enum class WaterLevelStatus { HIGH, LOW };

class Logic {

public:
  unsigned long getLoopDelay();
  bool shouldLightOn(const DateTime &now);
  bool shouldWaterPumpOn(const DateTime &now);
  WaterLevelStatus waterLevelStatus(int level);
};

#endif
