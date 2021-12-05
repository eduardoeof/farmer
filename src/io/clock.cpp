#include "clock.h"

#include <RTClib.h>
#include <Arduino.h>

Clock::Clock() {
  rtc = new RTC_DS3231();  
}

void Clock::setup() {
  rtc->begin();

  if (rtc->lostPower()) {
    Serial.println("RTC lost power. Adjusting time to now");
    rtc->adjust(DateTime(__DATE__, __TIME__)); // set datetime to the compile time
  }
}

const DateTime Clock::now() {
  return rtc->now();
}

