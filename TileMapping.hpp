#pragma once
#include "raylib.h"

void DrawTextBox(Texture2D texture, int posX, int posY, int tilesWide, int tilesHigh, const char* text, float scale = 1);
extern const int MAP_HEIGHT ;
extern const int MAP_WIDTH ;
extern const int TILE_SIZE;

Rectangle getTileSourceRect(int id, int tilesPerRow);

void drawMap(Texture2D tileTexture);
bool CheckTileCollision(Rectangle rect);
