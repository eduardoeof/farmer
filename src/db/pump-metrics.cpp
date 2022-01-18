#include "pump-metrics.h"

#include <SPI.h>
#include <SD.h>
#include <RTClib.h>  // Include DateTime

#include "../model/pump-metrics.h"

#define DATETIME_FORMAT "YYYY-MM-DDThh:mm:ss"

void PumpMetricsDB::setup() {
  pinMode(53, OUTPUT);

  if (!SD.begin(53)) {
    Serial.println("Error: PumpMetricsDB setup failed");
    while (true);
  }
}

void PumpMetricsDB::save(PumpMetrics &p) {
  //File json = SD.open("pump-metrics.json", FILE_WRITE);
  File json = SD.open("write.txt", FILE_WRITE);

  if (json) {
    StaticJsonDocument<200> doc;    

    char *turnedOnAt = p.getTurnedOnAt().toString(DATETIME_FORMAT);

    Serial.println(turnedOnAt);

    doc["turnedOnAt"] = turnedOnAt; 

    if (p.getTurnedOffAt()) {
      char *turnedOffAt = p.getTurnedOffAt()->toString(DATETIME_FORMAT);

      doc["turnedOffAt"] = turnedOffAt; 
    }

    char content[200];
    serializeJsonPretty(doc, content);

    Serial.println(content);

    json.println(content);
    json.close();
  } else {
    Serial.println("Error: PumpMetricsDB save failed");
  }
}

