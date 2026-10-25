# Task 2: OLED Monitoring of PWM Parameters

## Task Name
PWM monitoring on an SSD1306 I2C OLED display

## Components Required
- ESP32 DevKit board
- Two LEDs
- Two 220-ohm resistors
- SSD1306 I2C OLED display
- Breadboard and jumper wires
- USB cable
- Computer with VS Code and PlatformIO

## Circuit Connection
- LEDs are connected the same way as Task 1 (GPIO18 and GPIO19, each through a 220-ohm resistor, cathodes to GND)
- OLED SDA -> GPIO21
- OLED SCL -> GPIO22
- OLED VCC -> 3V3
- OLED GND -> GND

## Working
The SSD1306 OLED is added to the same project. It shows the duty-cycle percentage and the PWM frequency of LED 1 and LED 2. The OLED reads the same variables (duty1 and duty2) and frequency values that are used for the LEDs, so the screen always matches the program. The percentage is calculated as (duty x 100 + 511) / 1023. The screen refreshes every 100 ms while the LEDs change every 10 ms, using the Adafruit GFX and Adafruit SSD1306 libraries.

Example of the OLED screen:
PWM MONITOR
LED1: 25% F:1000Hz
LED2: 75% F:5000Hz

## Wokwi Result
In Wokwi both LEDs fade and the OLED updates live. The OLED shows the duty cycle of both LEDs changing and the frequencies 1000 Hz and 5000 Hz.

Wokwi project link: [Paste your project link here]

## Hardware Result
On the physical ESP32 board both LEDs fade and the OLED shows the live duty-cycle percentages and frequencies. The values on the OLED match the values used by the program.

## Wokwi vs Hardware
The results are the same. The OLED I2C address is 0x3C, and some boards use 0x3D, which is the only setting that may need a change on hardware. OLED pin order can also differ between boards, so the pin labels should be checked.

## Screenshots
The screenshots folder contains all ecvidence.