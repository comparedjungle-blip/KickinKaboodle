// Globals.h
#pragma once
#include "raylib.h"
#include "AnimationSystem.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "MenuObjects.hpp"
class Room;
extern Room Shop;

extern Enemy Shark;
extern Enemy Planty;

extern bool walkableArea;
extern bool inBattle;
extern bool inShop;
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
extern Texture2D shop_texture_overworld;
extern Texture2D shop_texture_inside;
extern Texture2D exit_button_texture;
extern Texture2D Planty_Texture;
extern Texture2D Planty_BattleTexture;
extern Animation girl_walking;
extern Animation FleeButtonAnimation;
extern Animation FightButtonAnimation;
extern Animation ScissorAnimation;
extern Animation RockAnimation;
extern Animation PaperAnimation;
extern Animation CursorAnimation;
extern Animation ShopAnimation;
extern Animation exitButtonAnimation;
extern Animation PlantyAnimation;

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

bool isButtonHover(Button button);

bool isButtonClicked(Button button);