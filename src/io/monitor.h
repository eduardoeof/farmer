#ifndef SERIAL_HEADER 
#define SERIAL_HEADER

class DateTime;
class Metrics;

class Monitor {

public:
  void setup();
  void print(const DateTime &timestamp);
  void print(const char message[]);
  void print(const char message[], const DateTime &timestamp, float liquidTemperature, bool lightOn, int waterLevel);
  void print(const char message[], const Metrics &metrics);
};

#endif

