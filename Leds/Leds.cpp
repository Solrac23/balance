#include <Leds/Leds.hpp>
#include <math.h>

Leds::Leds(int &valG, int &valY, int &valR){
	pindMode(valG, OUTPUT);
	pindMode(valY, OUTPUT);
	pindMode(valR, OUTPUT);
	ledGreen = valG;
	ledYellow = valY;
	ledRed = valR;
}

// Função para ligar leds
int Leds::turnOnLeds(int val){
	 if(val <= 0){
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, LOW);
    delay(5000);
   
    return 0;
  }
  
  if(val >= 0 && val <= 39){
   digitalWrite(ledRed, HIGH);
   digitalWrite(ledYellow, LOW);
   digitalWrite(ledGreen, LOW);
   delay(5000);
   
   return val;
  }else if(val >= 40 && val <= 79){
    digitalWrite(ledRed, LOW);
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledGreen, LOW);
    delay(5000);
   
    return val;
  }else if(val >= 80 && val <= 100){
    digitalWrite(ledRed, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, HIGH);
    delay(5000);
   
    return val;
  }
 
}

// Função de porcentagem
int Leds::percents(int val, int weight=0.28) {
	var = val / weight;
	varFormated = floor(var);

	return turnOnLeds(varFormated);
}