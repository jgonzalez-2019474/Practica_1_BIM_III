#include <Ticker.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>

#define button 4

//Variables
volatile static bool estado_led;
float temperatura;

//Configuracion de ISR
void ISR_temp();
void ISR_detectar_btn();

//Constructor
Ticker ISR_obtener_temp(ISR_temp, 3000); //tira la temperatura cada 3 segundos
Ticker ISR_obtener_btn(ISR_detectar_btn, 6000); //tira la temperatura cada 3 segundos
OneWire ourWire(6);  //pin 5
DallasTemperature sensor(&ourWire);

void setup() {
Serial.begin(9600);
ISR_obtener_temp.start(); 
ISR_obtener_btn.start(); 
sensor.begin();
}
void loop() {
  ISR_obtener_temp.update();
  ISR_obtener_btn.update();
}
void medicion(){
  //Se envia la lectra de la temperatura
  sensor.requestTemperatures(); 
  //Da la temperatura
  float temp = sensor.getTempCByIndex(0); 
  Serial.print("Temperatura= ");
  Serial.print(temp);
  Serial.println(" C");
  }
void ISR_temp(){
   medicion();
}
void ISR_detectar_btn(){
  bool estado_btn = digitalRead(button);
  if(estado_btn == 1){
  Serial.println("boton ON");
}
if(estado_btn == 0){
  Serial.println("boton OFF");
}
}
