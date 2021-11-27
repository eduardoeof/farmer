#ifndef SERIAL_HEADER 
#define SERIAL_HEADER

class DateTime;

class Monitor {

public:
  void setup();
  void print(const DateTime &timestamp);
};

#endif

