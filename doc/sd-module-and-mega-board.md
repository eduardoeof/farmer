# SD module and Mega2560 board

1. Pins

- Pin 50: MISO
- Pin 51: MOSI
- Pin 52: SCK
- Pin 53: CS

2. Set pin 53 to OUTPUT 

```cpp
pinMode(53, OUTPUT);
```

3. Start SD lib passing CS pin

```cpp
if (!SD.begin(53)) {
  Serial.println("Error: PumpMetricsDB setup failed");
  while (true);
}
```

