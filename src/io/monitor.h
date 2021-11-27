#ifndef SERIAL_HEADER 
#define SERIAL_HEADER

class DateTime;
class String;

class Monitor {

public:
  void setup();
  void print(const DateTime &timestamp);
  void print(const char message[]);
};

#endif

