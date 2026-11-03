// Name: Umme Salma
// Week 8 DAC Part 3

#include <Arduino.h>

#define DAC_PIN 25
#define PWM_PIN 16

void setup()
{
    Serial.begin(115200);

    // PWM: 5 kHz frequency, 8-bit resolution
    ledcSetup(0, 5000, 8);

    ledcAttachPin(PWM_PIN, 0);
}

void loop()
{
    // DAC output code 128
    dacWrite(DAC_PIN, 128);

    // PWM duty value 128 (approximately 50%)
    ledcWrite(0, 128);

    Serial.println("DAC=128 | PWM duty=128");

    delay(1000);
}