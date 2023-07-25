#pragma once
#include <pebble.h>
#include "Image.h"

static void init_images_struct(struct Images *image_list, uint32_t number_of_images);
static void add_image(struct Images *image_list, GRect bounds, uint32_t resource_id, Layer *window_layer);
static void push_image(struct Images *image_list, struct Image *input_image);
static void de_init_images_struct(struct Images *image_list);