#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ESP8266WebServer.h>
#include <ArduinoJson.h>
#include <PubSubClient.h>
const char* ssid = "QMNet.2G";//nome da minha rede
const char* password = "&rGGfk0510";//senha da minha rede

// MQTT Broker
const char *mqtt_broker = "test.mosquitto.org";  //Host do broket
const char *topic = "test_topic";            //Topico a ser subscrito e publicado
const char *mqtt_username = "";         //Usuario - Vazio pois estamos utilizando a porta 1883
const char *mqtt_password = "";         //Senha - Vazio pois estamos utilizando a porta 1883
const int mqtt_port = 1883;             //Porta

//Variáveis
bool mqttStatus = 0;
//Objetos
WiFiClient espClient;
PubSubClient client(espClient);

bool connectMQTT();
void callback(char *topic, byte * payload, unsigned int length);

ESP8266WebServer server(80);
String page = "";
int data1, data2, data3;


void setup()
{
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      Serial.print(".");
    }
  Serial.println(WiFi.localIP());
  Serial.println("WiFi connected");
  mqttStatus =  connectMQTT();
  
  server.begin();
}


void loop()
{  
  
  // -------------------------------------------------------------
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(Serial);
  if (root == JsonObject::invalid())
  {
    return;
    Serial.println("invalid");
  }
  data1 = root["a1"];
  data2 = root["a2"];
  data3 = root["a3"];
  Serial.println(data1);
  Serial.println(data2);
  Serial.println(data3);
  
  static long long pooling  = 0;
  if ( mqttStatus){
    
    client.loop();    

    if (millis() > pooling +1000){
      pooling = millis();
      client.publish(topic, "{0,7.31,48}");
    }
       
  }
}


bool connectMQTT() {
  byte tentativa = 0;
  client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(callback);

  do {
    String client_id = "GabrielMaia-";
    client_id += String(WiFi.macAddress());

    if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
      Serial.println("Exito na conexão:");
      Serial.printf("Cliente %s conectado ao broker\n", client_id.c_str());
    } else {
      Serial.print("Falha ao conectar: ");
      Serial.print(client.state());
      Serial.println();
      Serial.print("Tentativa: ");
      Serial.println(tentativa);
      delay(2000);
    }
    tentativa++;
  } while (!client.connected() && tentativa < 5);

  if (tentativa < 5) {
    // publish and subscribe   
    client.publish(topic, "{0,7.31,48}"); 
    client.subscribe(topic);
    return 1;
  } else {
    Serial.println("Não conectado");    
    return 0;
  }
}
void callback(char *topic, byte * payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    Serial.print((char) payload[i]);
  }
  Serial.println();  
  Serial.println("-----------------------");
}
