//
//  AnimationSystem.cpp
//  TheGame
//
//  Created by Isaiah Heinze on 2/4/26.
//

#include "AnimationSystem.hpp"
#include "raylib.h"

void animation_update(Animation *self){
        float dt = GetFrameTime();
        self->duration_left -= dt;
        
        if (self->duration_left <= 0){
            self->duration_left = self->speed;
            self->cur++;
        }
        
        if (self->cur > self->last){
            self->cur = self->first;
        }
    };
    
Rectangle animation_frame(Animation *self, int number_of_frames_per_row, int pixelx,int pixely, int scale){
        float x = (self->cur % number_of_frames_per_row) * pixelx;
        float y = (self->cur / number_of_frames_per_row) * pixely;
        return Rectangle{
            .x = x,
            .y = y,
            .width = (float)pixelx ,
            .height = (float)pixely,
        };
    };
