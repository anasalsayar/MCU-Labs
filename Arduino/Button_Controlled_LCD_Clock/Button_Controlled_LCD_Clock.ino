#include <LiquidCrystal.h>
const int rs = 12, en = 13, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int hour = 10, minute = 57, second = 50, a = 0, b = 0, c = 0, modeFlag = 0, secToMin = 0, minToHour = 0, sn = 0;
unsigned long previousMillis;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  previousMillis = millis();
  unsigned long previousMillis();
}

void loop() {
  if (digitalRead(2) == 1) {
    Serial.println("Button 2 pressed");
  }
  if (digitalRead(3) == 1) {
    Serial.println("Button 3 pressed");
  }

  while (millis() < previousMillis + 1000) {
    if(digitalRead(2) == 1 && modeFlag == 1 && secToMin != 1 && minToHour != 1)
      second = -1;
  }
  previousMillis = millis();
  Serial.println(previousMillis);
  second++;
  if (second == 60) {
    second = 0;
    minute++;
  }
  if (minute == 60) {
    minute = 0;
    hour++;
  }
  if (hour == 24) {
    hour = 0;
  }

  lcd.setCursor(0, 0);
  if (hour < 10) {
    Serial.print("0");
    lcd.print("0");
  }
  Serial.print(hour);
  Serial.print(":");
  lcd.print(hour);
  lcd.print(":");
  if (minute < 10) {
    Serial.print("0");
    lcd.print("0");
  }
  Serial.print(minute);
  Serial.print(":");
  lcd.print(minute);
  lcd.print(":");
  if (second < 10) {
    Serial.print("0");
    lcd.print("0");
  }
  Serial.println(second);
  lcd.print(second);

  if (digitalRead(2) == 1 && modeFlag == 0) {
    a++;
    lcd.setCursor(0, 1);
    lcd.print(a);
  }
  if (digitalRead(2) == 0 && modeFlag == 0) {
    a = 0;
    lcd.setCursor(0, 1);
    lcd.print("  ");
  }
  if (a == 3) {
    modeFlag = 1;
    a = 0;
  }

  if(modeFlag == 1) {
    lcd.setCursor(0, 1);
    lcd.print("modeFlag");
    if(secToMin != 1 && digitalRead(3) == 0 && minToHour != 1 || sn == 1) {
      lcd.setCursor(6, 0);
      lcd.print("  ");
      delay(200);
      lcd.setCursor(6, 0);
      lcd.print(second);
      delay(200);
    }
    if (digitalRead(3) == 1) {
      secToMin = 1;
      sn = 0;
      b++;
      lcd.setCursor(11, 1);
      lcd.print(b);
    }
    if (digitalRead(3) == 0 && b != 0) {
      b = 0;
      lcd.setCursor(11, 1);
      lcd.print("  ");
    }
    if (b == 3) {
      secToMin = 0;
      b = 0;
      lcd.setCursor(0, 1);
      lcd.print("Exited mode");
      delay(1000);
      lcd.setCursor(0, 1);
      lcd.print("              ");
      modeFlag = 0;
    }

    if(secToMin == 1) {
      if(digitalRead(2))
        minute++;
      lcd.setCursor(3, 0);
      lcd.print("  ");
      delay(100);
      lcd.setCursor(3, 0);
      if(minute < 10)
        lcd.print("0");
      lcd.print(minute);
      delay(100);
      if(minute == 59) {
        minute = 0;
        hour++;
      }
    }
    if (digitalRead(3) == 1 && secToMin == 1) {
      minToHour = 1;
      c++;
      lcd.setCursor(11, 1);
      lcd.print(c);
      lcd.setCursor(13, 1);
      lcd.print("h");
    }
    if (digitalRead(3) == 0 && c != 0) {
      c = 0;
      lcd.setCursor(11, 1);
      lcd.print("   ");
    }

    if(minToHour == 1) {
      secToMin = 0;
      if(digitalRead(2))
        hour++;
      lcd.setCursor(0, 0);
      lcd.print("  ");
      delay(100);
      lcd.setCursor(0, 0);
      if(hour < 10)
        lcd.print("0");
      lcd.print(hour);
      delay(100);
      if(hour == 24)
        hour = 0;

      if(digitalRead(3) == 1) {
        minToHour = 0;
        sn = 1;
      }
    }
  }
  Serial.println(modeFlag);
}