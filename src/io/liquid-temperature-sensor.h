#ifndef LIQUID_TEMPERATURE_SENSOR_HEADER
#define LIQUID_TEMPERATURE_SENSOR_HEADER
 
class DallasTemperature;
class OneWire;

class LiquidTemperatureSensor {

public:
  LiquidTemperatureSensor();
  void setup();
  float getTemperature(); 

private:
  DallasTemperature *sensor;
  OneWire *oneWire;
};

#endif
