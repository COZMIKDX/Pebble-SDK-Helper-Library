#pragma once
#include <pebble.h>

struct Image
{
    uint32_t image_resource_id; // I probably won't even need this.
    GRect image_dimension_position;
    Gbitmap *image;
    BitmapLayer *image_layer;
};
static void init_image(GRect spatialInfo, uint32_t resource_id);
static void destroy_image_struct(struct Image *image_struct);