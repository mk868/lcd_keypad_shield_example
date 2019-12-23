#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>

#include "lcd_config.h"
#include "lcd_buttons.h"

LiquidCrystal lcd(LCD_RS_PIN, LCD_EN_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN, LCD_BACKLIGHT_PIN, POSITIVE);

uint8_t cursor_column = 0;
uint8_t cursor_row = 0;

void print_ui()
{
  lcd.clear();
  lcd.home();
  lcd.print("LCD LED  ON  OFF");
  lcd.setCursor(0, 1);
  lcd.print("PCB LED  ON  OFF");

  lcd.setCursor(8 + cursor_column * 4, cursor_row);
  lcd.print((char)0x7E);
}

void setup()
{
  Serial.begin(9600);

  lcd.backlight();
  lcd.begin(16, 2);

  pinMode(LED_BUILTIN, OUTPUT);

  print_ui();
}

void loop()
{
  t_lcd_buttons key = get_pressed_key();
  if (key == NONE)
  {
    return;
  }

  if (key == UP)
  {
    cursor_row = 0;
  }
  if (key == DOWN)
  {
    cursor_row = 1;
  }
  if (key == LEFT)
  {
    cursor_column = 0;
  }
  if (key == RIGHT)
  {
    cursor_column = 1;
  }
  if (key == SELECT)
  {
    if (cursor_row == 0)
    {
      lcd.setBacklight(!cursor_column);
    }
    if (cursor_row == 1)
    {
      digitalWrite(LED_BUILTIN, !cursor_column);
    }
  }

  print_ui();
  delay(300);
}
