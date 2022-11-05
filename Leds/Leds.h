#ifndef LEDS_H
#define LEDS_H

/**
 * Function to turn on, turn off the LED and calcule 
 * the percents.
 */

#include "Arduino.h"
class Leds{
  public:
    Leds(); // uctor definido como padrão
    virtual ~Leds();

    // Initialize the library and data to turn on the LED
    void begin(int valR, int valG, int valY);

    // Calculete the percents to LED and turn on the LED
    // according to the values
    float percents(float val, float weight);

    // Conditions to turn on the LED
    float turnOnLeds(float val);

  private:
    int ledRed; // variable to store the red value
    int ledYellow; // variable to store the yellow value
    int ledGreen; // variable to store the green value
    float var; // variable to store the calcule
    float varFormated; // variable to store the formated value
};
#endif