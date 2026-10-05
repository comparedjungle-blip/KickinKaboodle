#include "Globals.h"
#include "raylib.h"
#include "room.h"
bool walkableArea = true;
bool inBattle = false;
bool inShop = false;
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
Texture2D shop_texture_overworld;
Texture2D shop_texture_inside;
Texture2D exit_button_texture;
Texture2D Planty_Texture;
Texture2D Planty_BattleTexture;

Camera2D camera;
bool isButtonHover(Button button) {
    return (CheckCollisionRecs(Player_cursor.HitBox(), button.HitBox()));
}

bool isButtonClicked(Button button) {
    return(isButtonHover(button) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
}

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
Animation exitButtonAnimation  = {
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
Animation ShopAnimation = {
    .first = 0,
    .last = 15,
    .cur = 0,
    .speed = 0.1,
    .duration_left = 0,
};
Animation PlantyAnimation = {
    .first = 0,
    .last = 6,
    .cur = 0,
    .speed = 0.1,
    .duration_left = 0,
};

enum BattleState battleState = BattleState::Menu;

bool player_cursor_hovering;



Enemy* CurrentEnemy = nullptr;

Enemy Shark;
Enemy Planty;

Room Shop;

Cursor Player_cursor;

