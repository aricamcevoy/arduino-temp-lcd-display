#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

unsigned long lastSampleTime = 0;
unsigned long lastDisplayTime = 0;

float tempSum = 0;
int sampleCount = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  Wire.begin();
}

void loop() {
  unsigned long now = millis();

  // Take a sample every 1 second
  if (now - lastSampleTime >= 1000) {
    lastSampleTime = now;

    float t = readTemp();
    tempSum += t;
    sampleCount++;
  }

  // Update display every 10 seconds
  if (now - lastDisplayTime >= 10000) {
    lastDisplayTime = now;

    if (sampleCount > 0) {
      float avgTemp = tempSum / sampleCount;

      float f = (avgTemp * 1.8) + 32;
      float calibrationOffsetF = 0.0; // adjust if neeeded
      f += calibrationOffsetF;

      lcd.setCursor(0, 0);
      lcd.print("Temp: ");

      lcd.setCursor(0, 1);
      lcd.print("              ");
      lcd.setCursor(0, 1);
      lcd.print(f, 2); // 2 decimal place
      lcd.print((char)223);
      lcd.print("F");
    }

    // Reset for next window
    tempSum = 0;
    sampleCount = 0;
  }
}

float readTemp() {
  Wire.beginTransmission(0x48);
  Wire.write(0x00); // temperature register
  Wire.endTransmission(false);


  Wire.requestFrom(0x48, 2);

  if (Wire.available() == 2) {
    uint8_t msb = Wire.read();
    uint8_t lsb = Wire.read();

    int16_t raw = (int16_t)((lsb << 8) | msb);
    Serial.print("lsb: ");
    Serial.print(lsb);
    Serial.print(" | msb: ");
    Serial.print(msb);
    Serial.print(" | raw: ");
    Serial.println(raw);

    return raw / 1024.0;
  }

  return -1000;
}