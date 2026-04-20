
//
//  main.cpp
//  hellolib
//
//  Created by Isaiah Heinze on 1/17/26.
//
#include "raylib.h"
#include "Globals.h"
#include "Player.hpp"
#include "MenuObjects.hpp"
#include "AnimationSystem.hpp"
#include "MainScene.hpp"
#include "TileMapping.hpp"
#include "vector"
#include <iostream>

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

std::vector<Texture2D> loadedTextures {};

void unloadTextures(){
    for (const auto& texture : loadedTextures)
    {
        UnloadTexture(texture);
    }
}

void UpdateDrawFrame(){
    
    BeginDrawing();
    
    //Player_cursor.debugXY();
    
    MainScene();
    
    EndDrawing();
}

int main(void)
{
    walkableArea = true;
    InitWindow(screenWidth, screenHeight, "Kickin' Kaboodle");
    HideCursor();
    
    loadedTextures.push_back(girl_walking_up = LoadTexture("assets/girl_walking_up.png"));
    loadedTextures.push_back(battleScreen = LoadTexture("assets/battlescreen.png"));
    loadedTextures.push_back(pointer = LoadTexture("assets/pointer-Sheet.png"));
    loadedTextures.push_back(FleeButton_Texture = LoadTexture("assets/flee_button.png"));
    loadedTextures.push_back(FightButton_Texture = LoadTexture("assets/fight_button-Sheet.png"));
    loadedTextures.push_back(Scissor_Texture = LoadTexture("assets/Sprite-0001.png"));
    loadedTextures.push_back(Rock_Texture = LoadTexture("assets/Sprite-0002.png"));
    loadedTextures.push_back(Paper_Texture = LoadTexture("assets/paper.png"));
    loadedTextures.push_back(Sharky_Texture = LoadTexture("assets/sharky.png"));
    loadedTextures.push_back(Sharky_BattleTexture = LoadTexture("assets/sharkybattle.png"));
    loadedTextures.push_back(heart = LoadTexture("assets/heart.png"));
    loadedTextures.push_back(tileTexture = LoadTexture("assets/TextBoxSpriteSheet.png"));
    loadedTextures.push_back(girl = LoadTexture("assets/girl_walking.png"));
    loadedTextures.push_back(girl_walking_sideways = LoadTexture("assets/girl_walking_sideways-Sheet.png"));
    loadedTextures.push_back(girl_walking_sideways_right = LoadTexture("assets/girl_walking_sideways-Sheet-right.png"));
    loadedTextures.push_back(grassMap = LoadTexture("assets/grass_sheet.png"));
    
    camera = {0};
    camera.target = player.vector();
    camera.offset = { screenWidth / 2.0f, screenHeight / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 2.0f;
    
    
    Shark = Enemy{
        screenWidth *2/3,
        screenHeight * 2/3,
        Sharky_Texture,
        1, 1, 32, 32, 15, 3,  //scale, frames, x, y, health, attack
        CursorAnimation,
        Sharky_BattleTexture
    };
   
    SetTargetFPS(60);
    
    // Main game loop
#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        
        UpdateDrawFrame();
        
    }
#endif

    // De-Initialization
  
    unloadTextures();
    
    CloseWindow();        // Close window and OpenGL context
    
    return 0;
}
