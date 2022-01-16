#include "pump-metrics.h"

#include <RTClib.h>

PumpMetrics::PumpMetrics(const DateTime &tOnAt) : PumpMetrics(tOnAt, NULL) {}

PumpMetrics::PumpMetrics(const DateTime &tOnAt, const DateTime *tOffAt)
    : turnedOnAt(DateTime(tOnAt)),
      turnedOffAt(tOffAt ? new DateTime(*tOffAt) : tOffAt), 
      on(tOffAt == NULL) {}

bool PumpMetrics::getOn() { return on; }

DateTime PumpMetrics::getTurnedOnAt() { return turnedOnAt; }

DateTime *PumpMetrics::getTurnedOffAt() { return turnedOffAt; }
