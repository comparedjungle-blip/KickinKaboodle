//
//  MainScene.cpp
//  TheGame
//
//  Created by Isaiah Heinze on 2/7/26.
//

#include "MainScene.hpp"
#include "raylib.h"
#include "BattleScene.hpp"
#include "Globals.h"
#include "Player.hpp"
#include "Enemy.hpp"

#include "room.h"
#include <string>
#include "ShopScene.h"

void MainScene(){
    //update
    animation_update(&girl_walking);
    animation_update(&PlantyAnimation);

    player.Move();
    player.HitBox();
    UpdateMyCamera(camera, player.PositionVector(), MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE, screenWidth, screenHeight);
    if (Shark.IsActive() && !inBattle)
    {
        Shark.HitBox();
        Shark.Move();
        if (CheckCollisionRecs(Shark.HitBox(), player.HitBox()))
        {
            CurrentEnemy = &Shark;
            inBattle = true;
            battleState = BattleState::Menu;
            playerChoice = PlayerChoice::none;
        }
    }
    if (Planty.IsActive() && !inBattle)
    {
        Planty.HitBox();
        Planty.Move();
        if (CheckCollisionRecs(Planty.HitBox(), player.HitBox()))
        {
            CurrentEnemy = &Planty;
            inBattle = true;
            battleState = BattleState::Menu;
            playerChoice = PlayerChoice::none;
        }
    }
   
    if (inBattle)
    {                               // if condition is true, enter battle screen, and not showing walking animation
        ClearBackground(BLACK);
        battleScene();
    }
    else if (CheckCollisionRecs(Shop.HitBox(), player.HitBox()) && IsKeyPressed(KEY_E)) {
        inShop = true;
    }
    else if (inShop)
    {
        shopScene();
    }
    else
    {
        //DRAW
        ClearBackground(BLUE);
        
        BeginMode2D(camera);
        
        drawMap(grassMap);
        Shop.Draw(shop_texture_overworld);
        player.Animate();
        player.HitBox();
        if (Shark.IsActive() && !inBattle) Shark.Draw();
        if (Planty.IsActive() && !inBattle) Planty.Animate();
        
        
        EndMode2D();
        // ui
        if (CheckCollisionRecs(Shop.HitBox(), player.HitBox())) {
            DrawTextBox(tileTexture, 0, 0, 5, 2, "Press E to Enter");
        }
        else {
            std::string statsTemp = "Health: " + std::to_string(player.m_health) + " XP: " + std::to_string(player.m_xp);
            const char* stats = statsTemp.c_str();
            DrawTextBox(tileTexture, 0, 0, 5, 2, stats);
        }
            
    }
    
}
