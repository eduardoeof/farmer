# SD module and Mega2560 board

## Pins and setup

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

## File name

Because SD library uses short 8.3 names for files, names MUST only have 1-8 characters. Also, for some reason the file extension MUST be `.txt`. For more details, check [SD Library][1] and [8.3 Filename][2] docs.

[1]: https://www.arduino.cc/en/reference/SD
[2]: https://docs.microsoft.com/en-us/openspecs/windows_protocols/ms-fscc/18e63b13-ba43-4f5f-a5b7-11e871b71f14
