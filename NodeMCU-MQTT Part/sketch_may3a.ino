#include <ESP8266WiFi.h>
#include <PubSubClient.h>

/******** I2C  ********/
#include <Wire.h>

#define SLAVE_ADDRESS 0x08

char data_received;
/**********************/

// WiFi
//const char *ssid = "GUMBOL"; // Enter your WiFi name
//const char *password = "00001111";  // Enter WiFi password
const char *ssid = "dabnux"; // Enter your WiFi name
const char *password = "#010#Tardab$";  // Enter WiFi password
//const char *ssid = "Realme 6"; // Enter your WiFi name
//const char *password = "55555555";  // Enter WiFi password

// MQTT Broker
const char *mqtt_broker = "mqtt-dashboard.com";
const char *topic = "blackbill/LED";
const char *mqtt_username = "emqx";
const char *mqtt_password = "public";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

/******************** ULtrasonic Sensor ************************/
#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

const int trigPin = 12;
const int echoPin = 14; 
char buf_d[10] = {0};

int distanceCm;
long duration;

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);  

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input 
    
  // Set software serial baud to 115200;
  Serial.begin(115200);
  // connecting to a WiFi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    //Serial.println("Connecting to WiFi..");
  }
  //connecting to a mqtt broker
  client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(callback);
  
  while (!client.connected()) 
  {
    String client_id = "esp8266-client-";
    client_id += String(WiFi.macAddress());
    if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) 
    {
        
    } 
    else
    {
      //Serial.print("failed with state ");
      //Serial.print(client.state());
      delay(2000);
    }
  }
  // publish and subscribe  
  client.publish(topic, "hello emqx");  
  client.subscribe(topic);

  
}

void callback(char *topic, byte *payload, unsigned int length) 
{
  for (int i = 0; i < length; i++)
  {
    Serial.print((char) payload[i]);
  }
  
  if(payload[0] == 'Y')
  {
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (HIGH is the voltage level)
  }
  else if(payload[0] == 'N')
  {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  else
  {
    
  }
}

void loop() 
{
  for(int i = 0; i<2; i++)
  {
    client.loop();
  }
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_VELOCITY/2;
  
  // Convert to inches  
  // Prints the distance on the Serial Monitor
  //Serial.print("Distance (cm): ");
  buf_d[0] = 'D';
  buf_d[1] = 'U';
  buf_d[2] = (distanceCm / 100) + 48;
  buf_d[3] = ((distanceCm % 100) / 10) + 48;
  buf_d[4] = (distanceCm % 10) + 48;
  buf_d[5] = 'L';
  buf_d[6] = 'L';
  buf_d[7] = 'L';
  buf_d[8] = 'L';
  buf_d[9] = 'L';
    
  //Serial.println(distanceCm);
  Serial.print(buf_d);
  //delay(1000);
}
