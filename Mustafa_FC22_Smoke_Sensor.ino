

#define  LED_OFF  0
#define  LED_ON  1

int Alc_Sensor = A0;
int sensorValue = 0;
int hScore = 0;
int cOffset = 0;


void setup() {
 Serial.begin(9600);


  delay(200);


 Serial.print("Current reading:");

 Serial.print("High:");
 Serial.print(hScore);
  cOffset = analogRead(Alc_Sensor);
}

void loop() {
  Serial.println("\n");

  sensorValue = read_alc_sensor();
  Serial.print(sensorValue);
  if (sensorValue > hScore) {
    hScore = sensorValue;
 
    Serial.print(hScore);
  }
   
  delay(150);
  
}

int read_alc_sensor() {
  int tV = 0;
  tV = analogRead(Alc_Sensor);
  if (tV < cOffset) {
    cOffset = tV;
  }
  return tV-cOffset;
}

