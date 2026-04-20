#pragma once
#include "raylib.h"
#include "AnimationSystem.hpp"
#include "Structs.hpp"
#include "Globals.h"
#include "mechanics.hpp"
#include <iostream>

class Player;

class Enemy{
private:
    int m_x;
    int m_y;
    int m_scale;
    Texture2D m_texture;
    Texture2D m_battleTexture;
    int m_frames;
    Rectangle m_animation;
    int m_pixelx;
    int m_pixely;
    bool m_active = true;
    
    
    int m_attack {};
    int m_health{};
    int m_defense {5};
    int m_magic {5};
    int m_speed{1};
    
public:
    std::string_view m_name;
    Enemy();
    Enemy(int x, int y, Texture2D texture, int scale, int frames,int pixelx, int pixely,
          int health,int attack, Animation animation, Texture2D battleTexture);
    void Draw();
    void Move();
    void DrawBattle();
    Rectangle HitBox();
    void Animate();
    Vector2 Vector();
    Rectangle DrawRect();
    PlayerChoice GetChoice();
    void Lose();
    bool Dead();
    void PrintHealth();
    bool IsActive();
    void Deactivate();
    void Attack(Player player);
    void TakeDamage(int attack);
};
