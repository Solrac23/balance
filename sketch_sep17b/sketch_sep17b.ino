//inclusao das bibliotecas necessarias
#include <Wire.h>
#include <stdio.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Leds/Leds.h>
Adafruit_SSD1306 display = Adafruit_SSD1306(); //objeto tipo Adafruit_SSD1306
Leds led(2,3,4)
struct variables {
  int numVermelho;
  int numAmarelo;
  int numVerde;
};

void setup(){
Wire.begin(); //inicia com a biblioteca
display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //inicia o display com endereço I2C 0x3C
display.setTextColor(WHITE); //define cor 
display.setTextSize(2); //define o tamanho da fonte
display.clearDisplay(); //limpa as informações do display
}


void loop() {  
  struct variables s1;
  s1.numVerde = 24;
  s1.numAmarelo = 22;
  s1.numVermelho = 8;

   display.setCursor(55,10); //posição do texto no display
   display.print(led.percents(s1.numVermelho)); //escreve o texto no display
   display.print("%"); //acrescentando o simbolo de % ao nuermo
   display.display(); //permite a mudança de texto no display
   delay(1000); //intervalo de 1 segundo
   display.clearDisplay(); //limpa o texto do display

}
