#include <pebble.h>

struct Image {
    uint32_t resource_id;
    GRect image_dimension_position;
    Gbitmap * image;
    BitmapLayer * image_layer;
}

static void Image(GRect spatialInfo, uint32_t resource_id) {
    
}