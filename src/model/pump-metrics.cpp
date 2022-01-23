#include "pump-metrics.h"

#include <RTClib.h>

/*
PumpMetrics::PumpMetrics(const DateTime &tOnAt) : PumpMetrics(tOnAt, NULL) {}

PumpMetrics::PumpMetrics(const char *tOnAt, const char *tOffAt)
  : PumpMetrics(new DateTime(tOnAt), tOffAt ? new DateTime(tOffAt) : NULL)

PumpMetrics::PumpMetrics(const DateTime *tOnAt, const DateTime *tOffAt)
    : turnedOnAt(new DateTime(*tOnAt)),
      turnedOffAt(tOffAt ? new DateTime(*tOffAt) : NULL),
      on(tOffAt == NULL) {}
*/

PumpMetrics::PumpMetrics(const DateTime &tOnAt) : PumpMetrics(tOnAt, NULL) {}

PumpMetrics::PumpMetrics(const DateTime &tOnAt, const DateTime *tOffAt)
    : PumpMetrics(tOnAt.toString("YYYY-MM-DDThh:mm:ss"),
                  tOffAt ? tOffAt->toString("YYYY-MM-DDThh:mm:ss") : NULL) {}

PumpMetrics::PumpMetrics(const char *tOnAt, const char *tOffAt)
    : turnedOnAt(new DateTime(tOnAt)),
      turnedOffAt(tOffAt ? new DateTime(tOffAt) : NULL), 
      on(tOffAt == NULL) {}

bool PumpMetrics::getOn() { return on; }

DateTime *PumpMetrics::getTurnedOnAt() { return turnedOnAt; }

DateTime *PumpMetrics::getTurnedOffAt() { return turnedOffAt; }
