#pragma once
#include <pebble.h>

struct Image
{
    uint32_t image_resource_id; // I probably won't even need this.
    GRect image_dimension_position;
    GBitmap *image;
    BitmapLayer *image_layer;
};
struct Image * init_image_struct(GRect spatial_info, uint32_t resource_id, Layer *window_layer);
void update_image(struct Image * image_struct, uint32_t resource_id);
void update_image_position(struct Image * image_struct, GPoint origin);
void destroy_image_struct(struct Image *image_struct);