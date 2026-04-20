//
//  mechanics.cpp
//  TheGame
//
//  Created by Isaiah Heinze on 2/9/26.
//
#include <random>
#include "mechanics.hpp"
#include "Globals.h"

int randomNumberGenerator(int start, int end){ //generates 0 - (range-1) eg. range = 5 ,0-4. works best for arrays
    std::random_device rd;
    std::uniform_int_distribution<int> dist(start, end);
    int num {dist(rd)};
    return num;
    
}
void UpdateMyCamera(Camera2D& camera, Vector2 playerPos,
                  float worldWidth, float worldHeight,
                  int screenWidth, int screenHeight)
{
    camera.target = player.PositionVector();
    float halfWidth = screenWidth/2.0f / camera.zoom;
    float halfHeight = screenHeight/2.0f / camera.zoom;
    if (camera.target.x < halfWidth)
            camera.target.x = halfWidth;

        if (camera.target.y < halfHeight)
            camera.target.y = halfHeight;

        if (camera.target.x > worldWidth - halfWidth)
            camera.target.x = worldWidth - halfWidth;

        if (camera.target.y > worldHeight - halfHeight)
            camera.target.y = worldHeight - halfHeight;
    }
    
