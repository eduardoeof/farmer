#include "pump-metrics.h"

#include <SPI.h>
#include <SD.h>
#include <RTClib.h>  // Include DateTime

#include "../model/pump-metrics.h"

void PumpMetricsDB::setup() {
  //pinMode(53, OUTPUT);

  if (!SD.begin(53)) {
    Serial.println("Error: PumpMetricsDB setup failed");
    while (true);
  }
}

void PumpMetricsDB::save(PumpMetrics &p) {
  File json = SD.open("pump-metrics.json", FILE_WRITE);

  if (json) {
    StaticJsonDocument<200> doc;    

    char turnedOnAt[20];
    p.getTurnedOnAt().toString(turnedOnAt);

    doc["turnedOnAt"] = turnedOnAt; 

    if (p.getTurnedOffAt()) {
      char turnedOffAt[20];
      p.getTurnedOffAt()->toString(turnedOffAt);

      doc["turnedOffAt"] = turnedOffAt; 
    }

    char content[40];
    serializeJsonPretty(doc, content);

    Serial.println(content);

    json.println(content);
    json.close();
  } else {
    Serial.println("Error: PumpMetricsDB save failed");
  }
}

