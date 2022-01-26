#ifndef OLED_DISPLAY_HEADER
#define OLED_DISPLAY_HEADER

class Metrics;
class DateTime;
class Adafruit_SSD1306;

class OLEDDisplay {

  public:
    OLEDDisplay();
    void setup();
    void print(const DateTime &timestamp, float temperature, bool lightOn, int waterLevel); 
    void print(const Metrics &metrics); 

  private:
    Adafruit_SSD1306 *display;

    void buildTitleLine(const DateTime &timestamp, char *title);
    void buildTemperatureLine(float temperature, char *line);
    void buildLightLine(bool lightOn, char *line);
    void buildWaterLevelLine(int waterLevel, char *line);
    void buildWaterPumpLine(bool waterPumpOn, char *line);
};

#endif

