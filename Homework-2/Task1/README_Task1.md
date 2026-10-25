# Task 1: Dual-LED PWM Fading with Different Frequencies

## Task Name
Dual-LED fading using PWM at different frequencies on the ESP32

## Components Required
- ESP32 DevKit board
- Two LEDs
- Two 220-ohm resistors
- Breadboard and jumper wires
- USB cable
- Computer with VS Code and PlatformIO

## Circuit Connection
- GPIO18 -> 220-ohm resistor -> LED 1 anode, LED 1 cathode -> GND
- GPIO19 -> 220-ohm resistor -> LED 2 anode, LED 2 cathode -> GND

## Working
The ESP32 uses its LEDC peripheral to make two PWM signals. LED 1 runs at 1000 Hz and LED 2 runs at 5000 Hz, both with 10-bit resolution (duty 0 to 1023). Every 10 ms the duty value of each LED changes by 5, and the direction flips at 0 and at 1023. LED 1 fades up while LED 2 fades down. The values are stored in duty1 and duty2, so Task 2 can show them on the OLED.

## Effect of Duty Cycle on Brightness
Duty cycle (%) = (duty value / 1023) x 100. The eye averages the fast ON/OFF flashes, so a higher duty cycle keeps the LED ON for longer in each period and it looks brighter.

## Effect of PWM Frequency on the Output Signal
Frequency is the number of ON/OFF cycles per second. The period is T = 1 / f, which is 1 ms at 1000 Hz and 0.2 ms at 5000 Hz. Frequency does not change the average brightness for the same duty cycle. A low frequency can flicker on a camera, and a higher frequency looks smoother but allows fewer resolution bits.

## LEDC Timer Limitation
Channels that share an LEDC timer must use the same frequency, so two different frequencies need two different timers. The classic ESP32 has 4 timers per speed group, so this works. With Arduino-ESP32 core 3.x, ledcAttach() picks the timers automatically. With core 2.x the code uses channel 0 and channel 2, which are on different timers. Other chips (S2, S3, C3) have fewer channels, so check the datasheet.

## Wokwi Result
In Wokwi both LEDs fade smoothly up and down. LED 1 and LED 2 move in opposite directions, and the Serial Monitor shows the duty values and the two frequencies.

Wokwi project link: [Paste your project link here]

## Hardware Result
On the physical ESP32 board both LEDs fade smoothly. The LEDs use separate resistors and the fading matches the Wokwi simulation.

## Wokwi vs Hardware
The behavior is the same in both. On hardware the brightness depends on the LED type and the resistor, and the 1000 Hz LED can show faint flicker on a phone camera.

## Screenshots
The screenshots folder contains all evidence.
