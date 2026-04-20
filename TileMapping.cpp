//
//  TileMapping.cpp
//  TheGame
//
//  Created by Isaiah Heinze on 2/12/26.
//

#include "TileMapping.hpp"
#include "raylib.h"
#include "Globals.h"
#include <vector>
const int TILE_SIZE = 32;
const int MAP_WIDTH = 16;
const int MAP_HEIGHT = 14;

int map[MAP_HEIGHT][MAP_WIDTH] = {
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2}, //1
    {6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8}, //2
    {6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8}, //3
    {6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8}, //4
    {6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8}, //5
    {6,7,7,7,7,7,3,5,4,7,7,7,7,7,7,8}, //6
    {6,7,7,7,7,7,3,17,16,7,7,7,7,7,7,8}, //7
    {6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8}, //8
    {6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8}, //9
    {6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8}, //10
    {6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8}, //11
    {6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8}, //12
    {6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8}, //13
    {12,13,13,13,13,13,13,13,13,13,13,13,13,13,13,14} //14
};

int collisionMap[MAP_HEIGHT][MAP_WIDTH] ={
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //1
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //2
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //3
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //4
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //5
    {1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1}, //6
    {1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1}, //7
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //8
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //9
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //10
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //11
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //12
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //13
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //14
    
};

void DrawTextBox(Texture2D texture, int posX, int posY, int tilesWide, int tilesHigh, const char* text, float scale)
{
    const int tileSize = 32;
    

    for (int y = 0; y < tilesHigh; y++)
    {
        for (int x = 0; x < tilesWide; x++)
        {
            Rectangle source = {0, 0, tileSize, tileSize};

            // Determine which part of the 3x3 sheet to use
            if (y == 0) // Top row
            {
                if (x == 0) source = {0, 0, tileSize, tileSize};               // TL
                else if (x == tilesWide - 1) source = {64, 0, tileSize, tileSize}; // TR
                else source = {32, 0, tileSize, tileSize};                     // T
            }
            else if (y == tilesHigh - 1) // Bottom row
            {
                if (x == 0) source = {0, 64, tileSize, tileSize};              // BL
                else if (x == tilesWide - 1) source = {64, 64, tileSize, tileSize}; // BR
                else source = {32, 64, tileSize, tileSize};                    // B
            }
            else // Middle rows
            {
                if (x == 0) source = {0, 32, tileSize, tileSize};              // L
                else if (x == tilesWide - 1) source = {64, 32, tileSize, tileSize}; // R
                else source = {32, 32, tileSize, tileSize};                    // C
            }

            Rectangle dest = {
                float(posX + x * tileSize),
                float(posY + y * tileSize),
                tileSize * scale,
                tileSize * scale
            };

            DrawTexturePro(texture, source, dest, {0,0}, 0.0f, WHITE);
            
        }
    }
    DrawText(text, posX +20, posY +20, 15, WHITE);
}

Rectangle getTileSourceRect(int id, int tilesPerRow){
    if (tilesPerRow <= 0) {
        return{
        0.0f * 0.0f,
        0.0f * 0.0f,
        (float)TILE_SIZE,
        (float)TILE_SIZE
        };
    }

    int tileX = id % tilesPerRow;
    int tileY = id / tilesPerRow;
    float tileSize = (float)TILE_SIZE;
    
    return {
        (float)tileX * tileSize,
        (float)tileY * tileSize,
        tileSize,
        tileSize
    };
}

void drawMap(Texture2D tileTexture){
    if (tileTexture.id == 0 || tileTexture.height == 0) {
        return; // Avoid division by zero
	}
    int tilesPerRow = tileTexture.width / TILE_SIZE;
    for (int y = 0; y < MAP_HEIGHT; y++){
        
        for (int x = 0; x < MAP_WIDTH; x++){
            int tileID = map[y][x];
            Rectangle source = getTileSourceRect(tileID, tilesPerRow);
            Rectangle dest = {
                float(x * TILE_SIZE),
                float(y * TILE_SIZE),
                float(TILE_SIZE),
                float(TILE_SIZE)
            };
            DrawTexturePro(tileTexture, source, dest, {0.0}, 0.0f, WHITE);
            }
        }
    }

bool CheckTileCollision(Rectangle rect)
{
    int leftTile   = rect.x / TILE_SIZE;
    int rightTile  = (rect.x + rect.width) / TILE_SIZE;
    int topTile    = rect.y / TILE_SIZE;
    int bottomTile = (rect.y + rect.height) / TILE_SIZE;

	if (leftTile < 0) leftTile = 0;
	if (rightTile >= MAP_WIDTH) rightTile = MAP_WIDTH - 1;
	if (topTile < 0) topTile = 0;
	if (bottomTile >= MAP_HEIGHT) bottomTile = MAP_HEIGHT - 1;

    for (int y = topTile; y <= bottomTile; y++)
    {
        for (int x = leftTile; x <= rightTile; x++)
        {
            if (collisionMap[y][x] == 1)
            {
                return true; // collided with solid tile
            }
        }
    }

    return false; // no collision
}
