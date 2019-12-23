#ifndef lcd_buttons_h
#define lcd_buttons_h

typedef enum
{
    NONE,
    RIGHT,
    UP,
    DOWN,
    LEFT,
    SELECT
} t_lcd_buttons;

t_lcd_buttons get_pressed_key();

#endif