#include "Globals.h"
#include "raylib.h"
bool walkableArea = true;
bool inBattle = false;
const int screenWidth = 512;
const int screenHeight = 448;
Texture2D heart;  //default texture
Texture2D girl;
Texture2D girl_walking_sideways;
Texture2D girl_walking_sideways_right;
Texture2D girl_walking_up;
Texture2D battleScreen;
Texture2D pointer;
Texture2D FleeButton_Texture;
Texture2D FightButton_Texture;
Texture2D Scissor_Texture;
Texture2D Paper_Texture;
Texture2D Rock_Texture;
Texture2D Sharky_Texture;
Texture2D Sharky_BattleTexture;
Texture2D tileTexture;
Texture2D grassTexture;
Texture2D grassMap;
Camera2D camera;

Animation girl_walking  = {
    .first = 0,
    .last = 3,
    .cur = 0,
    .speed = 0.1,
    .duration_left = 0,
};
Player player(screenWidth/2 - 20, screenHeight/2 + 40);

Animation FleeButtonAnimation  = {
    .first = 0,
    .last = 3,
    .cur = 0,
    .speed = 0.1,
    .duration_left = 0,
};

Animation FightButtonAnimation  = {
    .first = 0,
    .last = 1,
    .cur = 0,
    .speed = 0.1,
    .duration_left = 0,
};

Animation ScissorAnimation  = {
    .first = 0,
    .last = 0,
    .cur = 0,
    .speed = 0.1,
    .duration_left = 0,
};

Animation RockAnimation  = {
    .first = 0,
    .last = 0,
    .cur = 0,
    .speed = 0.1,
    .duration_left = 0,
};

Animation PaperAnimation  = {
    .first = 0,
    .last = 0,
    .cur = 0,
    .speed = 0.1,
    .duration_left = 0,
};
Animation CursorAnimation = {
    .first = 0,
    .last = 2,
    .cur = 0,
    .speed = 0.1,
    .duration_left = 0,
};
enum BattleState battleState = BattleState::Menu;

bool player_cursor_hovering;



Enemy* CurrentEnemy = nullptr;

Enemy Shark;

Cursor Player_cursor;
