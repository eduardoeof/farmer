#ifndef LOGIC_HEADER
#define LOGIC_HEADER

class DateTime;

class Logic {

public:
  bool shouldLightOn(const DateTime &now);
  unsigned long getDelayTime();
};

#endif
