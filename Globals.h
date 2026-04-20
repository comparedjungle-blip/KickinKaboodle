// Globals.h
#pragma once
#include "raylib.h"
#include "AnimationSystem.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "MenuObjects.hpp"

extern Enemy Shark;
extern bool walkableArea;
extern bool inBattle;
extern const int screenWidth;
extern const int screenHeight;
extern Texture2D heart; //defualt texture
extern Texture2D girl;
extern Texture2D girl_walking_sideways;
extern Texture2D girl_walking_sideways_right;
extern Texture2D girl_walking_up;
extern Texture2D battleScreen;
extern Texture2D pointer;
extern Texture2D FleeButton_Texture;
extern Texture2D FightButton_Texture;
extern Texture2D Scissor_Texture;
extern Texture2D Rock_Texture;
extern Texture2D Paper_Texture;
extern Texture2D Sharky_Texture;
extern Texture2D Sharky_BattleTexture;
extern Texture2D tileTexture;
extern Texture2D grassTexture;
extern Texture2D grassMap;

extern Animation girl_walking;
extern Animation FleeButtonAnimation;
extern Animation FightButtonAnimation;
extern Animation ScissorAnimation;
extern Animation RockAnimation;
extern Animation PaperAnimation;
extern Animation CursorAnimation;


extern Player player;
extern Cursor Player_cursor;
extern Camera2D camera;
extern bool player_cursor_hovering;
enum class BattleState{
    Fighting,
    Flee,
    Menu,
    ShowTime,
};

extern BattleState battleState;



extern Enemy* CurrentEnemy;
