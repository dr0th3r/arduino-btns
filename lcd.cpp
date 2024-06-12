#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define LINE_WIDTH 20
#define LINE_COUNT 4

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, LINE_WIDTH, LINE_COUNT);

typedef enum
{
  LEFT,
  CENTER,
  RIGHT,
} LINE_MODIFIER;

void lcdPrint(String text, LINE_MODIFIER modifier, byte lineNumber) {
  if (modifier == LEFT) {
    lcd.setCursor(0, lineNumber);
  } else if (modifier == CENTER) {
    byte startMiddle = (LINE_WIDTH - text.length()) / 2;
    lcd.setCursor(startMiddle, lineNumber);
  } else if (modifier == RIGHT) {
    lcd.setCursor(LINE_WIDTH - text.length(), lineNumber);  
  }
  lcd.print(text);
}

void setup()
{
  Serial.begin(9600);
	// initialize the LCD
	lcd.begin();

	// Turn on the blacklight and print a message.
	lcd.backlight();
  lcdPrint("hello world", LEFT, 0);
}

void loop()
{
	lcdPrint(String(millis() / 1000), RIGHT, 0);
}