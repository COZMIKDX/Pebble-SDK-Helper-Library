#pragma once
#include <pebble.h>

static void init_image(GRect spatialInfo, uint32_t resource_id);
static void destroy_image_struct(struct Image *image_struct);