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

static void push_image(struct Images * image_list, struct Image * input_image) {
    // Access the pointer for the array on pointers and then write the new image pointer value to the next unused slot. 
    (image_list->image_array)[image_list->top] = input_image;
}

// Free what the image struct pointers are pointing at and then free the array holding the pointers.
// I think I should call a function for the image structs that will free all of their own member pointers.
static void de_init_images_struct(struct Images * image_list) {
    for (int i = 0; i < image_list->length; i++) {
        free((image_list->image_array)[i])
    }
    free(image_list->image_array);
}