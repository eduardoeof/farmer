#ifndef AIR_SENSOR_HEADER
#define AIR_SENSOR_HEADER

class DHT;

class AirSensorIO {

public:
  AirSensorIO();
  void setup();
  float getTemperature();
  float getHumidity();

private:
  DHT *dht;
};

#endif
