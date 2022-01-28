#include <Arduino.h>
#include <HX711.h>

HX711 scale;

#define LOADCELL_DOUT_PIN 5
#define LOADCELL_SCK_PIN 4

float units;
float calibration_factor = 2570124;

void setup() {
  Serial.begin(115200);
  scale.begin(LOADCELL_DOUT_PIN,LOADCELL_SCK_PIN);
  scale.set_scale();
  scale.tare();
}

void calibrate(){
  Serial.print("Reading");
  units = scale.get_units(10);
  Serial.print(" Units: ");
  calibration_factor = units / 0.250;
  Serial.print(units,3);
  Serial.print(" calibration factor: ");
  Serial.print(calibration_factor);
  Serial.println();
}

void loop() {
  calibrate();
}

