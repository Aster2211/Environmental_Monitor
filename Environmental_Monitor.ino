#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Pin & Sensor Setup
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  dht.begin();

  // Boot sequence message
  lcd.setCursor(0, 0);
  lcd.print("Env Monitor");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read sensor values (takes ~250ms)
  float humidity = dht.readHumidity();
  float tempC = dht.readTemperature();
  float tempF = dht.readTemperature(true);

  // Check if reading failed
  if (isnan(humidity) || isnan(tempC) || isnan(tempF)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!   ");
    return;
  }

  // Line 1: Temperature in Celsius & Fahrenheit
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempC, 1);
  lcd.print((char)223); // Degree symbol (°)
  lcd.print("C / ");
  lcd.print(tempF, 0);
  lcd.print((char)223);
  lcd.print("F ");

  // Line 2: Humidity percentage
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity, 1);
  lcd.print("%   ");

  // DHT11 minimum sampling interval (1-2 seconds)
  delay(2000);
}