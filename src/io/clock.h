#ifndef CLOCK_HEADER 
#define CLOCK_HEADER

class RTC_DS3231;
class DateTime;

class Clock {

public:
  Clock();
  void setup();
  const DateTime now();

private:
  RTC_DS3231 *rtc;
};

#endif

