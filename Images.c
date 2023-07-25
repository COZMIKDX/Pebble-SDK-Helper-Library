#include <pebble.h>
#include "Image.h"

struct Images {
    struct image ** image_array;  // array of pointers
    uint32_t length = 0;
    uint32_t top = 0;
}

static void init_images_struct(struct Images * image_list, uint32_t number_of_images) {
    // Access the pointer for the array of pointers and have it point to the memory just allocated.
    image_list->image_array = (struct Image *) malloc(sizeof(struct Image) * number_of_images);
    image_list->length = number_of_images;
}

static void add_image(struct Images *image_list, GRect bounds, uint32_t resource_id, Layer *window_layer)
{
    struct Image *image_struct = init_image(bounds, resource_id, Layer * window_layer);
    push_image(image_list, image_struct);
}

static void push_image(struct Images * image_list, struct Image * input_image) {
    // Access the pointer for the array on pointers and then write the new image pointer value to the next unused slot. 
    if (top != (length - 1)) {
        (image_list->image_array)[image_list->top] = input_image;
        top = top + 1;
    } else {
        return; // Too many images for the current array. I'll make an array allocate and copy function later.
    }
}

// Free what the image struct pointers are pointing at and then free the array holding the pointers.
static void de_init_images_struct(struct Images * image_list) {
    for (int i = 0; i < image_list->length; i++) {
        // Destroy the image, the image_struct, and then the pointer to the image struct.
        destroy_image_struct((image_list->image_array)[i]);
        free((image_list->image_array)[i]);
    }
    free(image_list->image_array);
}