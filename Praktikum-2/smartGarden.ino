const int shMin = 0;
const int shMax = 1024;
int shCek, range;
bool rainCek = false;
#define shPin A0
#define buzzer 3

#define hygroPin A1
int hygroCek;

void setup() {

  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  
}

void loop() {

  shCek = analogRead(shPin);
  range = map(shCek, shMin, shMax, 0, 3);

  switch (range) {
    case 0:
      Serial.println("Flood");
      break;
    case 1:
      rainCek = true;
      break;
    case 2:
      rainCek = false;
      break;
  }

  if(rainCek == true) {

    digitalWrite(buzzer, HIGH);
    
  } else {

    digitalWrite(buzzer, LOW);
    
  }

  hygroCek = analogRead(hygroPin);
  hygroCek = constrain(hygroCek, 400, 1023);
  hygroCek = map(hygroCek, 400, 1023, 100, 0);
  Serial.print("Soil humidity: ");
  Serial.print(hygroCek);
  Serial.println("%");
  delay(500);
  
  delay(500);
  
}
