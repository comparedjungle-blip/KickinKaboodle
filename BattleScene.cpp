//
//  BattleScene.cpp
//  TheGame
//
//  Created by Isaiah Heinze on 2/4/26.
//

#include "BattleScene.hpp"
#include "Globals.h"
#include "MenuObjects.hpp"
#include "AnimationSystem.hpp"
#include "Structs.hpp"
#include "TileMapping.hpp"
#include <iostream>

std::string resultText;

bool isButtonHover(Button button){
    return (CheckCollisionRecs(Player_cursor.HitBox(), button.HitBox()));
}

bool isButtonClicked(Button button){
    return(isButtonHover(button) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
}

void battleResult(PlayerChoice playerChoice, PlayerChoice enemyChoice){
    if (playerChoice == PlayerChoice::scissor && enemyChoice == PlayerChoice::scissor)
    {
        resultText = "tie";
        player.Attack(*CurrentEnemy);
        CurrentEnemy->Attack(player);
        
        CurrentEnemy->PrintHealth();
        
    }
    else if (playerChoice == PlayerChoice::rock && enemyChoice == PlayerChoice::scissor)
    {
        resultText = "you win! they chose scissor";
        player.Attack(*CurrentEnemy);
        CurrentEnemy->PrintHealth();
        
    }
    else if (playerChoice == PlayerChoice::paper && enemyChoice == PlayerChoice::scissor)
    {
        resultText = "you lose... they chose scissor";
        CurrentEnemy->Attack(player);
        CurrentEnemy->PrintHealth();
        
    }
    else if (playerChoice == PlayerChoice::scissor && enemyChoice == PlayerChoice::rock)
    {
        resultText = "you lose... they chose rock";
        CurrentEnemy->Attack(player);
        CurrentEnemy->PrintHealth();
        
    }
    else if (playerChoice == PlayerChoice::rock && enemyChoice == PlayerChoice::rock)
    {
        resultText = "tie";
        CurrentEnemy->PrintHealth();
    }
    else if (playerChoice == PlayerChoice::paper && enemyChoice == PlayerChoice::rock)
    {
        resultText = "you win... they chose rock";
        player.Attack(*CurrentEnemy);
        CurrentEnemy->PrintHealth();
    }
    else if (playerChoice == PlayerChoice::scissor && enemyChoice == PlayerChoice::paper)
    {
        resultText = "you win... they chose paper";
        player.Attack(*CurrentEnemy);
        CurrentEnemy->PrintHealth();
    }
    else if (playerChoice == PlayerChoice::rock && enemyChoice == PlayerChoice::paper)
    {
        resultText = "you lose... they chose paper";
        CurrentEnemy->Attack(player);
        CurrentEnemy->PrintHealth();
    }
    else if (playerChoice == PlayerChoice::paper && enemyChoice == PlayerChoice::paper)
    {
        resultText = "tie";
        CurrentEnemy->PrintHealth();
    }
}
void battleScene(){
    walkableArea = false;

    float scale = 2.0f;
    float scaledWidth  = battleScreen.width * scale;
    float scaledHeight = battleScreen.height * scale;
    float centerX = GetScreenWidth() / 2.0f;
    float rightThirdX = GetScreenWidth() * 1/5;
    float leftThirdX = GetScreenWidth() * 4/5;
    float lowerThirdY = GetScreenHeight() * 7/8;
    PlayerChoice enemyChoice;
    
    Button FightButton(rightThirdX,
                       lowerThirdY,
                       FightButton_Texture,
                       scale,
                       2, FightButtonAnimation, 79 , 48);
    Button FleeButton(centerX,
                      lowerThirdY,
                      FleeButton_Texture,
                      scale,
                      4, FleeButtonAnimation, 79, 48);
    Button Scissor(rightThirdX,
                   lowerThirdY,
                   Scissor_Texture,
                   scale, 1, ScissorAnimation, 32, 32);
    Button Rock(GetScreenWidth()/2,
                lowerThirdY,
                Rock_Texture,
                scale, 1, RockAnimation, 32, 32);
    Button Paper(leftThirdX,
                 lowerThirdY,
                 Paper_Texture,
                 scale, 1, PaperAnimation, 32, 32);
   
    animation_update(&FleeButtonAnimation);
    animation_update(&FightButtonAnimation);
    animation_update(&CursorAnimation);
    
    DrawTexturePro(battleScreen, {0,0, (float)battleScreen.width, (float)battleScreen.height},
                   {(GetScreenWidth()  - scaledWidth)  / 2.0f,(GetScreenHeight()  - scaledHeight)  / 2.0f, scaledWidth, scaledHeight},
                   {0,0},
                   0.0f,
                   WHITE);
    CurrentEnemy->DrawBattle();
    Player_cursor.Update();
    Player_cursor.HitBox();
    
    switch (battleState){
        case (BattleState::Menu):
        {
            FleeButton.HitBox();
            FightButton.HitBox();
            
            if (isButtonHover(FightButton))
            {
                FightButton.Animate();
                if(isButtonClicked(FightButton))
                    battleState = BattleState::Fighting;
            }
            else
            {
                FightButton.Draw();
            }
            
            if (isButtonHover(FleeButton))
            {
                FleeButton.Animate();
                if(isButtonClicked(FleeButton))
                {
                    battleState = BattleState::Flee;
                }
            }
            else{
                FleeButton.Draw();
            }
            break;
        }
        
        case (BattleState::Fighting):
        {
            if (!(CurrentEnemy->Dead()))
            {
                
                Scissor.Draw();
                Scissor.HitBox();
                Rock.Draw();
                Rock.HitBox();
                Paper.Draw();
                Paper.HitBox();
                
                if (isButtonClicked(Scissor)){
                    playerChoice = PlayerChoice::scissor;
                    enemyChoice = CurrentEnemy->GetChoice();
                    battleResult(playerChoice, enemyChoice);
                    battleState = BattleState::ShowTime;
                    
                }
                if (isButtonClicked(Rock)){
                    playerChoice = PlayerChoice::rock;
                    enemyChoice = CurrentEnemy->GetChoice();
                    battleResult(playerChoice, enemyChoice);
                    battleState = BattleState::ShowTime;
                }
                if (isButtonClicked(Paper)){
                    playerChoice = PlayerChoice::paper;
                    enemyChoice = CurrentEnemy->GetChoice();
                    battleResult(playerChoice, enemyChoice);
                    battleState = BattleState::ShowTime;
                }
            }
            else {
                battleState = BattleState::Flee;
            }
            break;
        }
        case (BattleState::ShowTime):
        {
            DrawTextBox(tileTexture, GetScreenWidth() * 1/15,
                        GetScreenHeight() * 1/5, 8, 2,
                        "animation goes here", 2.5);
            DrawTextBox(tileTexture, GetScreenWidth()/3, GetScreenHeight()/2, 8, 2, resultText.c_str(), 2.5);
            if (IsMouseButtonPressed(0))
            {
                battleState = BattleState::Fighting;
            }
            break;
        }
        case (BattleState::Flee):
        {
            inBattle = false;
            walkableArea = true;
            CurrentEnemy->Deactivate();
            
            break;
        }
    }
    if (isButtonHover(FightButton) || isButtonHover(FleeButton) || isButtonHover(Scissor) || isButtonHover(Rock) || isButtonHover(Paper))
    {
            Player_cursor.Animate();
        } else
        {
            Player_cursor.Draw();
        }

}
