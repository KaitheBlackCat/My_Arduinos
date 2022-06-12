#include <Wire.h>
#include "VEML6070.h"
 
void setup() {
  Serial.begin(115200);
  Wire.begin();
  VEML6070.init();
  Serial.println("14CORE | VEML6070 TEST CODE");
  Serial.println("");
  VEML6070.VEML6070_forceMode();
  VEML6070.VEML6070_trigger();
  delay(1000);
}
 
void loop() {
  measureLight();
  Serial.println();
  delay(1000);
  VEML6070.VEML6070_trigger();
}
void measureLight() {
  uns16 uv, red, blue, green, white;
  uv = VEML6070.getUV();
  red = VEML6070.getRed();
  Serial.println("VEML6070 DATA");
  Serial.println();
  Serial.print("VEML6070 UV:\t");
  Serial.println(uv);
  Serial.println();
}
