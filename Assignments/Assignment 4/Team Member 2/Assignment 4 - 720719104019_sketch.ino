#include <WiFi.h>
#include<WiFiClient.h>
#include<PubSubClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

#define ORG "axinpr"
#define DEVICE_TYPE "esp32"
#define DEVICE_ID "191040193"
#define TOKEN "949742287"
#define alert "alert"

char server [] = ORG ".messaging.Internetofthings.ibmcloud.com";
char pubTopic1 [] = "iot-2/evt/msg/fmt/json";
char authMethod [] = "use-token-auth";
char token [] = TOKEN;
char clientId [] = "d:" ORG ":" DEVICE_TYPE ":" DEVICE_ID;
long now;

WiFiClient wifiClient;
PubSubClient client(server, 1883, NULL, wifiClient);

#define t 5
#define e 18

void setup() {
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);
  while(WiFi.status()!= WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("WiFi connected, Ip Address: ");
  Serial.println(WiFi.localIP());

  if(!client.connected())
  {
    Serial.print("Reconnecting client to ");
    Serial.println(server);
    while(!client.connect(clientId, authMethod, token)) {
      Serial.print(".");
      delay(500);
    }
    Serial.println("Bluemix connected");
  }
  delay(100);
  pinMode(t, OUTPUT);
  pinMode(e, INPUT);
}


long last_Msg = 0;
void loop() {
  delay(1000);
  client.loop();
  now = millis();
  digitalWrite(t, LOW);
  digitalWrite(t, HIGH);
  delayMicroseconds(10);
  digitalWrite(t, LOW);
  float dur = pulseIn(e, HIGH);
  float dis = ((dur/2) * 0.0343);
  if(dis < 100){
    if(now - last_Msg > 3000){
      last_Msg = now;
      String payload = "{\"data\":{\"DEVICE_ID\":\"" DEVICE_ID "\"";
             payload +=",\"msg\":\"" alert "\"";
             payload +="}}";
      
      Serial.print("Sending payload: ");
      Serial.println(payload);
      if(client.publish(pubTopic1,(char*) payload.c_str())){
        Serial.println("Published");
      }
      else{
        Serial.println("Publish failed");
      }
    }
    Serial.println("Distance is less than 100cm ");
    delay(3500);
  }
  else 
  {
     Serial.println("Distance is greater than 100cm ");
  }
}