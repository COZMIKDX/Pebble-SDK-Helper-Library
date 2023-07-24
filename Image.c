#include <pebble.h>

struct Image {
    uint32_t image_resource_id;
    GRect image_dimension_position;
    Gbitmap * image;
    BitmapLayer * image_layer;
}

static Image * create_image(GRect spatialInfo, uint32_t resource_id) {
    
    image_dimension_position = spatialInfo;
    image_resource_id = resource_id;

    image = gbitmap_create_with_resource(image_resource_id);
    image_layer = bitmap_layer_create(image_dimension_position);
    bitmap_layer_set_compositing_mode(image_layer, GCompOpSet);
    bitmap_layer_set_bitmap(image_layer, image);
    // Add the bitmap layer to the window layer in the Images.c file.

}