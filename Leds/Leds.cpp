#include "Leds.h"
#include "Arduino.h"
#include <math.h>

// Inicializando a classe.
Leds::Leds(){
}

Leds::~Leds(){
}

// Função para ligar leds
void Leds::begin(int valR, int valG, int valY){
  pinMode(valG, OUTPUT);
	pinMode(valY, OUTPUT);
	pinMode(valR, OUTPUT);
	ledGreen = valG;
	ledYellow = valY;
	ledRed = valR;
}

// Função para ligar leds
float Leds::turnOnLeds(float val){
	 if(val <= 0){
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, LOW);
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
float Leds::percents(float val, float weight=0.28) {
	var = val / weight;
	varFormated = floor(var);

	return turnOnLeds(varFormated);
}

/**
 * @param val irá receber o valor float 
*/