
#include <TimerOne.h>
#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int val;
const int tempPin = A0;       
const int pulsePin = A1;      

int pulseValue = 0;
int bpm = 0;
int tempValue = 0;
float temperatureC = 0.0;
float temperatureF = 0.0;

int spo2 = 97;  

void setup() {
  lcd.begin(16, 2); 
  lcd.print("Health Monitoring");

  pinMode(pulsePin, INPUT);
  pinMode(tempPin, INPUT);

 
  delay(2000);
}

void loop() {
  
  tempValue = analogRead(tempPin);
  temperatureC = (tempValue * 5.0 * 100.0) / 1024; 
  temperatureF = (temperatureC * 9.0 / 5.0) + 32.0; 

  
  pulseValue = analogRead(pulsePin);

 
  bpm = map(pulseValue, 0, 1023, 60, 100);

  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("HB per min: ");
  lcd.print(bpm);

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temperatureC);
  lcd.print(" C");

  delay(1000);

  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SpO2: ");
  lcd.print(spo2);
  lcd.print(" %");

  delay(1000);
}
