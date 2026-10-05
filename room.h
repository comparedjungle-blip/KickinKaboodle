#pragma once
#include "raylib.h"
#include "AnimationSystem.hpp"
#include "Structs.hpp"
#include "mechanics.hpp"
#include <iostream>



class Room {
private:
    int m_x;
    int m_y;
    int m_scale;
    Texture2D m_texture_overworld;
    Texture2D m_texture_inside;
    int m_frames;
    Rectangle m_animation;
    int m_pixelx;
    int m_pixely;
    bool m_active;

public:
    std::string_view m_name;
    Room();
    Room(int x, int y, Texture2D overworldTexture, int scale, int frames, int pixelx, int pixely,
         Animation animation, Texture2D insideTexture, std::string_view name);
    void Draw(Texture2D texture);
    void DrawInside();
    Rectangle HitBox();
    void Animate();
    Vector2 Vector();
    Rectangle DrawRect();
    PlayerChoice GetChoice();
    bool IsActive();
    void Deactivate();

};
