#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include "Adafruit_Si7021.h"

#define BMP_280_I2C_ADDRESS 0x76

Adafruit_BMP280 bmp; // I2C
Adafruit_Si7021 sensor = Adafruit_Si7021();

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(5, OUTPUT); // set the LED pin mode

  if (!sensor.begin())
  {
    Serial.println("Did not find Si7021 sensor!");
    while (true)
      ;
  }
  delay(10);
  if (!bmp.begin(BMP_280_I2C_ADDRESS))
  {
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1)
      ;
  }

  Serial.println();
  Serial.println("Initialized");
}

void loop()
{
  // put your main code here, to run repeatedly:
  delay(1000);

  //bmp280 part
  Serial.println("BMP280 readings");
  Serial.print("Pressure (Pa): ");
  Serial.println((float)bmp.readPressure(), 1);
  Serial.print("Temperature (C): ");
  Serial.println((float)bmp.readTemperature(), 1);
  Serial.print("Altitude (m): ");
  Serial.println((float)bmp.readAltitude(1024), 1); // this should be adjusted to your local forcase
  Serial.println();
  //SI7021 part
  Serial.println("SI7021 readings");
  Serial.print("Humidity (%): ");
  Serial.println((float)sensor.readHumidity(), 1);
  Serial.print("Temperature (C): ");
  Serial.println((float)sensor.readTemperature(), 1);
  Serial.println();
}

