#include "Arduino.h"
#include "LED.h"
#include "Potentiometer.h"

// Pin Definitions
#define LEDG_1_PIN_VIN	2
#define LEDG_2_PIN_VIN	3
#define LEDG_3_PIN_VIN	4
#define LEDR_PIN_VIN	5
#define POTENTIOMETER_5V_PIN_SIG	A10

// Global variables and defines
LED ledG_1(LEDG_1_PIN_VIN);
LED ledG_2(LEDG_2_PIN_VIN);
LED ledG_3(LEDG_3_PIN_VIN);
LED ledR(LEDR_PIN_VIN);
Potentiometer potentiometer_5v(POTENTIOMETER_5V_PIN_SIG);

// No menu needed anymore
void setup() {
    Serial.begin(9600);
    while (!Serial);  // Wait for serial connection
    Serial.println("Potentiometer LED Position Indicator");
}

void loop() {
    int potValue = potentiometer_5v.read();  // 0 to 1023
    Serial.print("Potentiometer Value: ");
    Serial.println(potValue);

    // Turn off all LEDs first
    ledG_1.off();
    ledG_2.off();
    ledG_3.off();
    ledR.off();

    // Turn on LEDs based on potentiometer value
    if (potValue >= 0)        ledG_1.on();
    if (potValue >= 256)      ledG_2.on();
    if (potValue >= 512)      ledG_3.on();
    if (potValue >= 768)      ledR.on();

    delay(100);  // Small delay for readability
}
