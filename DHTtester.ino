
#include <Adafruit_Sensor.h>
#include "DHT.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define DHTPIN 6

#define DHTTYPE DHT11  
LiquidCrystal_I2C lcd(0x27, 16, 2);

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  lcd.begin();
  lcd.setCursor(2,0);
  lcd.print("WH Predicter");

  dht.begin();
  
}

void loop() {
  
  
  delay(2000);
  lcd.backlight();
	

  
  float h = dht.readHumidity();
 
  float t = dht.readTemperature();
  
  float f = dht.readTemperature(true);

  
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

 
  float hif = dht.computeHeatIndex(f, h);
  
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
 
  
  Serial.print(F("  Temperature: "));
  Serial.print(t);
  Serial.print(F("C "));
  Serial.print(f);
  Serial.print(F("F  Heat index: "));
  Serial.println(hic);
  

if  (h<40 and t>40){
  Serial.println("You might wanna expect rain");
  lcd.setCursor(2,1);
  lcd.print("Rain incoming!");
  

}

else  {

  Serial.println("Sky looking pretty clear today!");
  lcd.setCursor(2,1);
  
  
  lcd.setCursor(2,1);
  lcd.print("Sky's clear!");
  

}

  

  

}
