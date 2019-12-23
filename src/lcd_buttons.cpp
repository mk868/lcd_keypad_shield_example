#include <Arduino.h>
#include "lcd_config.h"
#include "lcd_buttons.h"

t_lcd_buttons get_pressed_key()
{
  int value = analogRead(LCD_BUTTONS_PIN);
  if (value > 870)
    return NONE;
  if (value > 600)
    return SELECT;
  if (value > 400)
    return LEFT;
  if (value > 220)
    return DOWN;
  if (value > 65)
    return UP;
  return RIGHT;
}