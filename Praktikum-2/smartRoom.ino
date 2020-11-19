#include <MQ2.h>
#include <DHT.h>

#define ledMerah 2
#define ledKuning 3
#define ledHijau 4
#define buzzer 5

#define mq2Pin A0
int gasCek;

#define flamePin A1
int flameCek = 0;

#define dhtPin 8
DHT dht(dhtPin, DHT11);

void setup() {
  
  Serial.begin(9600);
  
  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(flamePin, INPUT);
  dht.begin();

}

void loop() {

  gasCek = analogRead(mq2Pin);
  if(gasCek > 500) {
    digitalWrite(ledHijau, HIGH);
  } else {
    digitalWrite(ledHijau, LOW);
  }

  flameCek = analogRead(flamePin);
  
  Serial.println(flameCek);
  if( flameCek < 40) {
    digitalWrite(ledMerah, HIGH);
  } else {
    digitalWrite(ledMerah, LOW);
  }

  float kelembaban = dht.readHumidity();
  float suhu = dht.readTemperature();

  if(gasCek > 500 && flameCek < 40) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledKuning, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
    digitalWrite(ledKuning, LOW);
  }

  
  delay(1000);

}
