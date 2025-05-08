#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
 
Adafruit_HMC5883_Unified compass = Adafruit_HMC5883_Unified(12345);
 
// Offsetid sinu mõõtmistest
const float x_offset = -12.955;
const float y_offset = 26.545;
 
void setup() {
  Serial.begin(115200);
  if (!compass.begin()) {
    Serial.println("HMC5883L ei leitud! Kontrolli ühendusi.");
    while (1);
  }
  Serial.println("Korrigeeritud kompass töötab.");
  delay(1000);
}
 
void loop() {
  sensors_event_t event;
  compass.getEvent(&event);
 
  // Rakenda kompensatsioon
  float x = event.magnetic.x - x_offset;
  float y = event.magnetic.y - y_offset;
 
  // Arvuta suuna nurk
  float heading = atan2(y, x);
  float headingDegrees = heading * 180.0 / PI;
  if (headingDegrees < 0) {
    headingDegrees += 360.0;
  }
 
  Serial.print("Suund: ");
  Serial.print(headingDegrees, 2);
  Serial.println("°");
 
  delay(200);
}
