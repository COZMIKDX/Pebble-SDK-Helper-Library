#include <pebble.h>

// Function borrowed from https://github.com/pebble-examples/ninety-one-dub/blob/master/src/ninety_one_dub.c#L66
unsigned short get_display_hour(unsigned short hour) {
  if (clock_is_24h_style()) {
    return hour;
  }

  unsigned short display_hour = hour % 12;
  return display_hour ? display_hour : 12;
}

unsigned short get_tens_digit(unsigned short time_unit) {
    return time_unit / 10; 
}

unsigned short get_ones_digit(unsigned short time) {
    return time_unit % 10;
}

void set_time_text_buffer(char buffer[], struct tm * tick_time) {
    // The buffer array is decayed to a pointer when passed to the function. So, changes to buffer will persist outside of this function.
    buffer[8];
    strftime(buffer, sizeof(buffer), clock_is_24h_style() ? "%H:%M" : "%I:%M", tick_time);
}

struct tm * peek_time() {
    time_t temp = time(NULL);
    return struct tm * tick_time = localtime(&temp);
}