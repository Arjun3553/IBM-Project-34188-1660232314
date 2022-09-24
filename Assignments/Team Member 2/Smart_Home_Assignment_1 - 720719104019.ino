// C++ code
//

#define trigger_pin 10 
#define echo_pin 9


void setup()
{
  Serial.begin(9600);
  pinMode(trigger_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
  pinMode(3,OUTPUT); // green led		
  pinMode(4,OUTPUT); // red led
  pinMode(5,OUTPUT); //buzzer
}


void loop()
{
  digitalWrite(trigger_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin,LOW);
  float duration = pulseIn(echo_pin,HIGH);
  float distance = ((duration / 2) * 0.0343);
  int reading = analogRead(A0);
  float voltage = reading * (5.0 / 1024.0);
  float temperatureCelcius = (voltage - 0.5) * 100;
  if(temperatureCelcius > 10 && temperatureCelcius <40)
  {
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  }
  
  else 
  {
    digitalWrite(4,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(5,HIGH);
  }
  
  Serial.print("Distance in cm : ");
  Serial.print(distance);
  Serial.print(" | ");
  Serial.print("Temperature: ");
  Serial.print(temperatureCelcius);
  Serial.print("\xb2\xb0");
  Serial.print(" C");
  Serial.println();
}