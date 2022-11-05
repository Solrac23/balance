//inclusao das bibliotecas necessarias
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Leds/Leds.h>
Adafruit_SSD1306 display = Adafruit_SSD1306(); //objeto tipo Adafruit_SSD1306
Leds led(2,3,4);


void setup(){
Wire.begin(); //inicia com a biblioteca
display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //inicia o display com endereço I2C 0x3C
display.setTextColor(WHITE); //define cor 
display.setTextSize(2); //define o tamanho da fonte
display.clearDisplay(); //limpa as informações do display
}


void loop() {  
  display.setCursor(55,10); //posição do texto no display
  display.print(led.percents(medida)); //escreve o texto no display
  display.print("%"); //acrescentando o simbolo de % ao nuermo
  display.display(); //permite a mudança de texto no display
  delay(1000); //intervalo de 1 segundo
  display.clearDisplay(); //limpa o texto do display

}
