#include <pebble.h>

struct Image {
    uint32_t image_resource_id; // I probably won't even need this.
    GRect image_dimension_position;
    Gbitmap * image;
    BitmapLayer * image_layer;
}

static struct Image * init_image(GRect spatialInfo, uint32_t resource_id) {
    struct Image * image_struct = (struct Image *) malloc(sizeof(struct Image));
    
    image_struct->image_dimension_position = spatialInfo;
    image_struct->image_resource_id = resource_id;

    image_struct->image = gbitmap_create_with_resource(image_resource_id);
    image_struct->image_layer = bitmap_layer_create(image_dimension_position);
    bitmap_layer_set_compositing_mode(image_struct->image_layer, GCompOpSet);
    bitmap_layer_set_bitmap(image_struct->image_layer, image_struct->image);
    // Add the bitmap layer to the window layer in the Images.c file.

    return image_struct;
}

static void destroy_image_struct(struct Image * image_struct) {
    gbitmap_destroy(image_struct->image);
    bitmap_layer_destroy(image_struct->image_layer);
}