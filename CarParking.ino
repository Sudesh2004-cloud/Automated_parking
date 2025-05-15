#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;

int IR1 = 2; // Entry IR sensor
int IR2 = 3; // Exit IR sensor
int Slot = 4; // Total number of parking slots
int flag1 = 0; // Entry flag
int flag2 = 0; // Exit flag

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);

  myservo.attach(4);
  myservo.write(100); // Servo closed initially

  lcd.setCursor(0, 0);
  lcd.print("ARDUINO");
  lcd.setCursor(0, 1);
  lcd.print("PARKING SYSTEM");
  delay(2000);
  lcd.clear();
}

void loop() {
  if (digitalRead(IR1) == LOW && flag1 == 0) { // Car entry detected
    if (Slot > 0) {
      flag1 = 1;
      if (flag2 == 0) {
        myservo.write(0); // Open servo
        Slot = Slot - 1;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Car Entered!");
        delay(1000);
        lcd.clear();
      }
    } else { // Parking full
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  SORRY :(  ");
      lcd.setCursor(0, 1);
      lcd.print("Parking Full");
      delay(3000);
      lcd.clear();
    }
  }

  if (digitalRead(IR2) == LOW && flag2 == 0) { // Car exit detected
    flag2 = 1;
    if (flag1 == 0) {
      myservo.write(0); // Open servo
      Slot = Slot + 1;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Car Exited!");
      delay(1000);
      lcd.clear();
    }
  }

  if (flag1 == 1 && flag2 == 1) { // Both sensors triggered (car passed)
    delay(1000);
    myservo.write(100); // Close servo
    flag1 = 0;
    flag2 = 0;
  }

  lcd.setCursor(0, 0);
  lcd.print("  WELCOME!  ");
  lcd.setCursor(0, 1);
  lcd.print("Slots Left: ");
  lcd.print(Slot);
}
