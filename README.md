epd2in13d
====

Code to control Waveshare EPD2in13D E-ink screens on Raspberry PI, ported to CMake.

## Build
This should be done on the target device, i.e. Raspberry Pi.
```bash
mkdir build && cd build
cmake .. -G Ninja
ninja
```

## Example
This will display a checkerboard pattern on the screen.
```bash
build/epd2in13d-display
```