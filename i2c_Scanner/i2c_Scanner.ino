#include <Wire.h>
#include "DM_G_I2C.h"

void setup()
{
  Wire.begin();         // I2C 통신
  Serial.begin(9600);  // 시리얼 모니터를 통해 확인
  while (!Serial);     // 시리얼 모니터 동작 했을 때 까지 기다리기
   
  G_I2C_Scanner();      // I2C 주소 확인 하기 
}


void loop()
{
    
}
