#pragma once

#include "raylib.h"
#include "AnimationSystem.hpp"

class Cursor{
private:
    int m_x;
    int m_y;
    int scale {2};
    
public:
    void Draw();
    Rectangle HitBox();
    Rectangle DrawRect();
    void Animate();
    Vector2 GetVec();
    void Update();
    //void debugXY();
};

class Button{
private:
    int m_x;
    int m_y;
    int m_scale;
    Texture2D m_texture;
    int m_frames;
    Rectangle m_animation;
    int m_pixelx;
    int m_pixely;
public:
    Button(int x, int y, Texture2D texture, int scale, int frames, Animation animation, int pixelx, int pixely);
    void Draw();
    Rectangle HitBox();
    void Animate();
    Vector2 Vector();
    Rectangle DrawRect(); 
};
