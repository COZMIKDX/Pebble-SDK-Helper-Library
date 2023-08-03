#pragma once
#include <pebble.h>

struct Text {
    GRect dimension_position;
    char * text;
    TextLayer * text_layer;
}

struct * init_text(GRect spatial_info, char * text, GColor text_color, GColor bg_color, GFont font, layer * window_layer);
void destroy_text_struct(struct Text * text_struct);