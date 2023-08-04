#pragma once
#include <pebble.h>

struct Text {
    GRect dimension_position; // still deciding if I want to keep this.
    char * text;
    TextLayer * text_layer;
};

struct * init_text(GRect spatial_info, char * text, GColor text_color, GColor bg_color, GFont font, layer * window_layer);
void update_text(struct Text * text_struct, char * text);
void destroy_text_struct(struct Text * text_struct);