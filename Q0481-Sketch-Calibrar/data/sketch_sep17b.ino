//inclusao das bibliotecas necessarias
#include <Wire.h>
#include <stdio.h>
#include <math.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display = Adafruit_SSD1306(); //objeto tipo Adafruit_SSD1306


#define ledVerde 2
#define ledAmarelo 3
#define ledVermelho 4

struct variables {
  int numVermelho;
  int numAmarelo;
  int numVerde;
};

void setup(){
pinMode(ledVerde, OUTPUT);
pinMode(ledAmarelo, OUTPUT);
pinMode(ledVermelho, OUTPUT);
Wire.begin(); //inicia com a biblioteca
display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //inicia o display com endereço I2C 0x3C
display.setTextColor(WHITE); // define cor do LCD
display.setTextSize(2); //define o tamanho da fonte LCD
display.clearDisplay(); //limpa as informações do display
}


void loop() {  
  struct variables s1;
  s1.numVerde = 24;
  s1.numAmarelo = 22;
  s1.numVermelho = 8;

   display.setCursor(55,10); //posição do texto no display
   display.print(percents(s1.numVermelho)); //escreve o texto no display
   display.print("%"); //acrescentando o simbolo de % ao nuermo
   display.display(); //permite a mudança de texto no display
   delay(1000); //intervalo de 1 segundo
   display.clearDisplay(); //limpa o texto do display

}


// Função para ligar leds
int turnOnLeds(int val){
  
  if(val <= 0){
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
    delay(5000);
   
    return 0;
  }
  
  if(val >= 0 && val <= 39){
   digitalWrite(ledVermelho, HIGH);
   digitalWrite(ledAmarelo, LOW);
   digitalWrite(ledVerde, LOW);
   delay(5000);
   
   return val;
  }else if(val >= 40 && val <= 79){
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, LOW);
    delay(5000);
   
    return val;
  }else if(val >= 80 && val <= 100){
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, HIGH);
    delay(5000);
   
    return val;
  }
 

}

// Função de porcentagem
int percents(int val){
  int var; 
  int varFormated;
  
  var = val / 0.28;
  varFormated = floor(var);

  return turnOnLeds(varFormated);   
}
