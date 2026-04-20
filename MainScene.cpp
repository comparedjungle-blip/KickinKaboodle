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
#include "mechanics.hpp"
void MainScene(){
    //update
    animation_update(&girl_walking);
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
        }
    }
    if (inBattle)
    {                               // if condition is true, enter battle screen, and not showing walking animation
        ClearBackground(BLACK);
        battleScene();
    }
    else
    {
        //DRAW
        ClearBackground(BLUE);
        
        BeginMode2D(camera);
        
        drawMap(grassMap);
        player.Animate();
        player.HitBox();
        if (Shark.IsActive() && !inBattle) Shark.Draw();
        
        EndMode2D();
        // ui
        
            
    }
    
}
