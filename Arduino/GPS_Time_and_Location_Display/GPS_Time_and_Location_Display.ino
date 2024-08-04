#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
const int rs = 12, en = 13, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
static const int RXPin = 2, TXPin = 3;
static const uint32_t GPSBaud = 9600;
SoftwareSerial ss(RXPin, TXPin);
byte previous, current, store, counter, hour, minute, second, buffer[37];
float latitude, latcm, latrad, loncm, latkm, lonkm;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600); //serial1
  ss.begin(GPSBaud);
  if(ss.available())
    previous = ss.read();
}

void loop() {
  if(ss.available()) { //serial1
    current = ss.read();
    if (store == 0) {
      if(previous == 71 && current == 65) {
        counter = 37;
        store = 1;
      } else {
        previous = current;
      }
    } else {
      buffer[37-counter] = current;
      counter--;
      if(counter == 0) {
        store = 0;
        hour = 10*(buffer[1]-48) + buffer[2] - 48 + 3;
        minute = 10*(buffer[3]-48) + buffer[4] - 48;
        second = 10*(buffer[5]-48) + buffer[6] - 48;
        if(hour < 10)
          Serial.print("0");
        Serial.print(hour);
        Serial.print(":");
        if(minute < 10)
          Serial.print("0");
        Serial.print(minute);
        Serial.print(":");
        if(second < 10)
          Serial.print("0");
        Serial.print(second);

        latitude = float((10*(buffer[11]-48) + buffer[12] - 48) * 6000000 + (buffer[13]-48) * 1000000 + (buffer[14]-48) * 100000 + (buffer[16]-48) * 10000 + (buffer[17]-48) * 1000 + (buffer[18]-48) * 100 + (buffer[19]-48) * 10 + buffer[20] - 48);
        latrad = latitude * 3.1415 / 1080000000.0;
        latcm = latitude * 1.852;
        loncm = float((100*(buffer[24]-48) + 10*(buffer[25]-48) + buffer[26] - 48) * 6000000 + (buffer[27]-48) * 1000000 + (buffer[28]-48) * 100000 + (buffer[30]-48) * 10000 + (buffer[31]-48) * 1000 + (buffer[32]-48) * 100 + (buffer[33]-48) * 10 + buffer[34] - 48) * 1.852 * cos(latrad);
        latkm = latcm / 100000;
        lonkm = loncm / 100000;

        Serial.print("  Distance from equator (cm) : ");
        Serial.print(latcm);
        Serial.print(" , Distance from Greenwich (cm) : ");
        Serial.println(loncm);

        lcd.setCursor(0, 0);
        lcd.print(hour);
        lcd.setCursor(1, 0);
        lcd.print(":");
        lcd.setCursor(2, 0);
        lcd.print(minute);
        lcd.setCursor(4, 0);
        lcd.print(":");
        if(second > 9) {
          lcd.setCursor(5, 0);
          lcd.print(second);
        } else {
          lcd.setCursor(5, 0);
          lcd.print("0");
          lcd.setCursor(6, 0);
          lcd.print(second);
        }

        lcd.setCursor(0, 1);
        lcd.print(latkm);
        lcd.setCursor(7, 1);
        lcd.print(";;");
        lcd.setCursor(9, 1);
        lcd.print(lonkm);
      }
    }
  }
}
