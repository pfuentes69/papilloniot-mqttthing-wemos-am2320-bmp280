#include <Arduino.h>
#include "BMP280.h"
#include "Wire.h"

#include "Adafruit_Sensor.h"
#include "Adafruit_AM2320.h"

Adafruit_AM2320 am2320 = Adafruit_AM2320();
#define P0 1013.25
BMP280 bmp;

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    delay(10); // hang out until serial port opens
  }

  am2320.begin();
  bmp.begin();  
  bmp.setOversampling(4);
}

void loop() {

  double T,P;
  char result = bmp.startMeasurment();
 
  if(result!=0){
    delay(result);
    result = bmp.getTemperatureAndPressure(T,P);
    
      if(result!=0)
      {
        Serial.print("Pressure = \t");
        Serial.print(P,2);
        Serial.println(" mBar");
//        Serial.print("A = \t");Serial.print(A,2); Serial.println(" m");
        Serial.print("Temperature = \t");
        Serial.print(am2320.readTemperature());
         Serial.println(" C");
        Serial.print("Humidity = \t");
        Serial.print(am2320.readHumidity());
         Serial.println("%");
      }
      else {
        Serial.println("Error.");
      }
  }
  else {
    Serial.println("Error.");
  }

  delay(2000);
}
