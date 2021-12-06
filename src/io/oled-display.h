#ifndef OLED_DISPLAY_HEADER
#define OLED_DISPLAY_HEADER

class DateTime;
class Adafruit_SSD1306;

class OLEDDisplay {

  public:
    OLEDDisplay();
    void setup();
    void print(const DateTime &timestamp, float temperature, bool lightOn, int waterLevel); 

  private:
    Adafruit_SSD1306 *display;
};

#endif

