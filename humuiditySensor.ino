#include <Time.h>

#include <Adafruit_Sensor.h>

#include <Time.h>//Incluimos la libreria Time

#include <DHT_U.h>
#include <DHT.h>


#include "DHT.h"

#define DHTPIN 2     // what digital pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11  


DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  
  //Formato: hora, minutos, segundos,dias, mes, año
  setTime(9,35,00,8,07,2018);
  
  Serial.println("Humedad (%) y Temperatura (*C)");

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);
  
  time_t p = now();  //variable time_t p
  
  //Imprimimos fecha y hora
  
  Serial.print(day(p));
  Serial.print(+ "/");
  Serial.print(month(p));
  Serial.print(+ "/");
  Serial.print(year(p));
  Serial.print(" ");
  Serial.print(hour(p));
  Serial.print(+ ":");
  Serial.print(minute(p));
  Serial.print(+":");
  Serial.print(second(p));
  Serial.print(" ");
  
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" ");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
}
