#include <ph4502c_sensor.h>
#include <Arduino.h>
#include <ArduinoJson.h>


int umidade = A2;
int pHSense = A0;
int temp = A1;

float adc_resolution = 1024.0;
float valor_calibracao = 21.34;

#define PH4502C_PH_LEVEL_PIN A0
#define PH4502C_TEMP_PIN A1
#define sensorPin A2

PH4502C_Sensor ph4502c(PH4502C_PH_LEVEL_PIN, PH4502C_TEMP_PIN);

void setup() {
    Serial.begin(9600);
    delay(100);
    Serial.println("Trabalho Objetos Inteligentes Conectados");
    pinMode(13, OUTPUT);
    ph4502c.init();
 }

 
StaticJsonBuffer<1000> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();
void loop () {
  //adicionando as medidas de umidade 
   
   umidade = analogRead(A2);
   int Porcento = map(umidade, 1023, 0, 0, 100);
      Serial.println(Porcento);
    
     float PHtestado = analogRead(pHSense);
     float valorPH = PHtestado/100 ; 

     
     float temperatura = (((ph4502c.read_temp()/10)-32)/1.8);         
     Serial.println(valorPH); 
     Serial.println(temperatura); 
    //adicionando calculo para temperatura da água

    
    delay(3000);
   
  
    root["a1"] = valorPH;
    root["a2"] = temperatura;
    root["a3"] = Porcento;
    root.printTo(Serial);
    Serial.println("");
}

