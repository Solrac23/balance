#ifndef LEDS_H
#define LEDS_H

/**
 * Function to turn on, turn off the LED and calcule 
 * the percents.
 */

#include <Arduino.h>
class Leds{
  public:
    Leds(int &valR, int &valG, int &valY) = default;
    int percents(int val, float weight);
    int turnOnLeds(int val);

  private:
    const int ledRed;
    const int ledYellow;
    const int ledGreen;
    int var;
    int varFormated;
}
#endif