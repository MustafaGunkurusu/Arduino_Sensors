
#include <LightDependentResistor.h>

#define OTHER_RESISTOR 3300 //ohms
#define USED_PIN A0
#define USED_PHOTOCELL LightDependentResistor::GL5528

// Create a GL5528 photocell instance (on A0 pin)
LightDependentResistor photocell(USED_PIN, OTHER_RESISTOR, USED_PHOTOCELL);

void setup(void)
{
  Serial.begin(9600);

  // Uncomment if your photocell is connected to 5V/3.3V instead of the other resistor
  //photocell.setPhotocellPositionOnGround(false);

  Serial.print("Light intensity will be given every second...\n");
}

void loop()
{
  // Check light intensity every second

  float intensity_in_lux = photocell.getCurrentLux();
  Serial.print("Light intensity: ");
  Serial.print(intensity_in_lux);
  Serial.print("lx (");
  Serial.print(LightDependentResistor::luxToFootCandles(intensity_in_lux));
  Serial.print("fc)\n");

  delay(1000);
}
