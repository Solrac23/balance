#ifndef LEDS_H
#define LEDS_H

/**
 * Function to turn on, turn off the LED and calcule 
 * the percents.
 */

#include <Arduino.h>
class Leds{
  public:
    Leds() = default; // constructor definido como padrão
    virtual ~Leds();

    // Initialize the library and data to turn on the LED
    void begin(int &valR, int &valG, int &valY);

    // Calculete the percents to LED and turn on the LED
    // according to the values
    int percents(int val, float weight);

    // Conditions to turn on the LED
    int turnOnLeds(int val);

  private:
    const int ledRed; // variable to store the red value
    const int ledYellow; // variable to store the yellow value
    const int ledGreen; // variable to store the green value
    int var; // variable to store the calcule
    int varFormated; // variable to store the formated value
}
#endif