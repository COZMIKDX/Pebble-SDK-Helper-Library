#include <pebble.h>
#include "Image.h"

struct Image * init_image(GRect spatialInfo, uint32_t resource_id, Layer *window_layer) {
    struct Image * image_struct = (struct Image *) malloc(sizeof(struct Image));
    
    image_struct->image_dimension_position = spatialInfo;
    image_struct->image_resource_id = resource_id;

    image_struct->image = gbitmap_create_with_resource(image_struct->image_resource_id);
    image_struct->image_layer = bitmap_layer_create(image_struct->image_dimension_position);
    bitmap_layer_set_compositing_mode(image_struct->image_layer, GCompOpSet);
    bitmap_layer_set_bitmap(image_struct->image_layer, image_struct->image);
    layer_add_child(window_layer, bitmap_layer_get_layer(image_struct->image_layer));

    return image_struct;
}

void destroy_image_struct(struct Image * image_struct) {
    gbitmap_destroy(image_struct->image);
    bitmap_layer_destroy(image_struct->image_layer);
}