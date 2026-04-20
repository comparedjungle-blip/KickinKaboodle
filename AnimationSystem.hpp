#pragma once
#include "raylib.h"

struct Animation{
public:
    int first;
    int last;
    int cur;
    
    float speed;
    float duration_left;
    
};

void animation_update(Animation *self);
    
Rectangle animation_frame(Animation *self, int number_of_frames_per_row, int pixelx = 32, int pixely = 32, int scale = 1);

