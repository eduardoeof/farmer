#include "pump-metrics.h"

#include <RTClib.h> // Include DateTime
#include <SD.h>
#include <SPI.h>

#include "../model/pump-metrics.h"
#include "../config.h"

#define DATETIME_FORMAT "YYYY-MM-DDThh:mm:ss"
#define FILE_NAME "pumpmet.txt"

void PumpMetricsDB::setup() {
  pinMode(SD_CS_DIGITAL_PIN, OUTPUT);

  if (!SD.begin(SD_CS_DIGITAL_PIN)) {
    Serial.println("Error: PumpMetricsDB setup failed");
    while (true);
  }
}

void PumpMetricsDB::save(PumpMetrics &p) {
  SD.remove(FILE_NAME);

  File file = SD.open(FILE_NAME, FILE_WRITE);

  if (file) {
    StaticJsonDocument<200> doc;

    char *turnedOnAt = p.getTurnedOnAt().toString(DATETIME_FORMAT);
    doc["turnedOnAt"] = turnedOnAt;

    if (p.getTurnedOffAt()) {
      char *turnedOffAt = p.getTurnedOffAt()->toString(DATETIME_FORMAT);
      doc["turnedOffAt"] = turnedOffAt;
    }

    char content[200];
    serializeJsonPretty(doc, content);
    file.println(content);

    file.close();
  } else {
    Serial.println("Error: PumpMetricsDB save failed");
  }
}

