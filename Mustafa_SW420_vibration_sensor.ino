//int ledPin = D13;
//int EP =D2;

void setup(){
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A0, INPUT); //set EP input for measurment
  Serial.begin(9600); //init serial 9600
  Serial.println("\nWelcome, Vibration Detectore V2.5, 2017/3/5");
  Serial.println("Begin at " + String(millis()/1000));
}
void loop(){
  long measurement =TP_init();
  delay(50);
 // Serial.print("measurment = ");
  if (true || measurement > 0) {
    Serial.print(String(millis()/1000) + ": ");
    for (int i=0; i< measurement/40; i++)
     
    Serial.println(measurement);
    delay(500);
  }
  if (measurement > 1000){
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else{
    digitalWrite(LED_BUILTIN, LOW); 
  }
}

long TP_init(){
  delay(10);
  long measurement=pulseIn (A0, HIGH);  //wait for the pin to get HIGH and returns measurement
  return measurement;
}
