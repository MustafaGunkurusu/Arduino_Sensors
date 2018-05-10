

#include <MoistureSensor.h>

int numReadings = 10;
MoistureSensor ms(A0, numReadings);



void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {

  digitalWrite(13, HIGH);

  // let the sensor warm up, the initial readings are not
  // very accurate
  delay(200);
  
  for (int i = 0; i < numReadings; i++) {
    ms.reset();
    ms.read();
    delay(1);
  }
 
  Serial.println(ms.getSmoothedReading());
  
  digitalWrite(13, LOW);
  delay(500);
}
