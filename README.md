# Pebble-SDK-Helper-Library
A library to help make Pebble Watchface/App dev a little less annoying.

# The Reason
The pebble SDK requires you to do a bit a of setup for all sorts of elements like images, text, the layers they are placed onto, etc.
In a basic project following the example project on the pebble developer website, you are placing several function calls throughout the main project file.
For example, setting the layers for images in one place, composition and animated values in another, and deletion handlers set up elsewhere.

Basically, I didn't want to have to do all that every time. On top of that, this project will deal with freeing the memory for you instead of having to manually free each pointer.
Overall, creating basic elements for your apps should be simpler.

# What it does
This handles several function calls and layer creation done when creating an element so you don't have to do it. 
Each element gets a struct that will contain info like layers, positional info, resource ids, etc when created.
In another struct, Pointers to those element structs are kept in an array along side other info such as the font, font size, or background color that will apply to all elements pointed to in that array by default.
This struct is one that you create and initialize using the corresponding initialization function.

# How to use
1. Copy the source files pairs you would like to use.
For example, to work with images copy Images.c, Images.h, Image.c, and Image.h to your project.
Then include the primary header files for that resource type.
```c
#include <pebble.h>
#include "Images.h"
#include "Texts.h"
```

2. Create a struct pointer for the type of element you are working with. Create a new struct and assign it's reference to the pointer.
```c
struct Images *Image_holder;
uint32_t number_of_images = (uint32_t) 5;
Image_holder = init_images_struct(number_of_images);

// Check if the struct was created
if (Image_holder == NULL)
{
  APP_LOG(APP_LOG_LEVEL_ERROR, "image holder pointer is NULL");
  return;
}
```

3. Add an image resource. Pass in the struct you created, a GRect containing the start x and y values and the width and height of the image, the resource id of the image, and the window layer.
```c
add_image(Image_holder, GRect(10, 106, 32, 48), RESOURCE_ID_YOUR_RESOURCE, window_layer);

// You can receive a reference to the image struct for that image. Useful for images you need to manipulate often.
struct Image * my_image = add_image(Image_holder, GRect(10, 106, 32, 48), RESOURCE_ID_SNAKE_PROFILE, window_layer);
```

4. Destroy the struct. You should destroy the struct when you are done with it, such as when you unload the window.
   This will destroy all the images in there for you as well
```c
static void window_unload(Window *window) {
  destroy_images_struct(Image_holder);
}
```
