#pragma once
#include "raylib.h"

int randomNumberGenerator(int start, int end);
void UpdateMyCamera(Camera2D& camera, Vector2 playerPos,
                  float worldWidth, float worldHeight,
                    int screenWidth, int screenHeight);
