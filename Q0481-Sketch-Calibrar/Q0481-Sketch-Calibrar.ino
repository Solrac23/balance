



/*
     Q0481-Sketch-Calibrar
     AUTOR:   BrincandoComIdeias
     LINK:    https://www.youtube.com/brincandocomideias ; https://cursodearduino.net/
     COMPRE:  https://www.arducore.com.br/
     SKETCH:  Calibrar Balanca com módulo HX711
     DATA:    04/07/2019
*/

// INCLUSÃO DE BIBLIOTECAS
#include <HX711.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <Leds.h>

   
// DEFINIÇÕES DE PINOS
#define pinDT  3
#define pinSCK  2
// #define pinBotao 4
#define escala 1.0f

// INSTANCIANDO OBJETOS

HX711 scale;     // define instancia balança HX711
Leds led;
Adafruit_SSD1306 display;


float medida = 0;
float calibration_factor = 42310;     // fator de calibração para teste inicial
void setup()
{
  Serial.begin(57600);            // monitor serial 9600 Bps
  scale.begin(pinDT, pinSCK);      // inicializa a balança
  led.begin(4,5,6);
  Wire.begin(); //inicia com a biblioteca
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //inicia o display com endereço I2C 0x3C
  display.setTextColor(WHITE); //define cor 
  display.setTextSize(2); //define o tamanho da fonte
  display.clearDisplay(); //limpa as informações do display   
  Serial.println();              // salta uma linha
  Serial.println("HX711 - Calibracao da Balança");                 // imprime no monitor serial
  Serial.println("Remova o peso da balanca");
  Serial.println("Depois que as leituras começarem, coloque um peso conhecido sobre a Balança");
  // Serial.println("Pressione a,s,d,f para aumentar Fator de Calibração por 10,100,1000,10000 respectivamente");
  // Serial.println("Pressione z,x,c,v para diminuir Fator de Calibração por 10,100,1000,10000 respectivamente");
  // Serial.println("Após leitura correta do peso, pressione t para TARA(zerar) ");
  scale.set_scale();                                             // configura a escala da Balança
  zeraBalanca ();                                                  // zera a Balança
}

void zeraBalanca ()
{
  Serial.println();                                               // salta uma linha
  scale.tare();                                                 // zera a Balança
  Serial.println("Balança Zerada ");
}

void loop()
{
  scale.power_up();
  scale.set_scale(calibration_factor);                     // ajusta fator de calibração
  Serial.print("Peso: ");      
  medida = scale.get_units(5);                          // imprime no monitor serial
  Serial.print(medida, 3);                      // imprime peso da balança com 3 casas decimais
  Serial.print(" kg");
  display.setCursor(50,10); //posição do texto no display
  display.print(led.percents(medida, 0.12)); //escreve o texto no display
  display.print("%"); //acrescentando o simbolo de % ao nuermo
  display.display(); //permite a mudança de texto no display
  delay(1000); //intervalo de 1 segundo
  display.clearDisplay(); //limpa o texto do display
  scale.power_down();
  //Serial.print("      Fator de Calibração: ");               // imprime no monitor serial
  //Serial.println(calibration_factor);                        // imprime fator de calibração
  //delay(1000) ;                                               // atraso de 0,5 segundo
 
}