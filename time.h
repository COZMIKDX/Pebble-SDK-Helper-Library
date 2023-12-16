#pragma once
#include <pebble.h>

unsigned short get_display_hour(unsigned short hour);
unsigned short get_tens_digit(unsigned short time_unit);
unsigned short get_ones_digit(unsigned short time);
void set_time_text_buffer(char buffer[], struct tm * tick_time);
struct tm * peek_time();