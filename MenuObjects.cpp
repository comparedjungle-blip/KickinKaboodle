//
//  MenuObjects.cpp
//  TheGame
//
//  Created by Isaiah Heinze on 2/4/26.
//

#include "MenuObjects.hpp"
#include "Globals.h"
#include "raylib.h"
#include "AnimationSystem.hpp"
#include <iostream>

void Cursor::Draw(){
    DrawTexturePro(pointer, { 0, 0, (float)pointer.width/3, (float)pointer.height},
                   { (float)m_x, (float)m_y,
        (float)pointer.width/3 * scale,
        (float)pointer.height * scale },
                   { ((float)pointer.width/3 * scale / 2) + 25,
        (float)pointer.height * scale / 2 },
                   0.0f,
                   WHITE);
}
Rectangle Cursor::HitBox(){
    return { (float)GetMouseX(), (float)GetMouseY(), 2, 2 };
}
void Cursor::Animate(){
    Rectangle animationFrame = {animation_frame(&CursorAnimation, 3, 32, 32)};
    Rectangle dst = DrawRect();
    Vector2 vec = GetVec();
    DrawTexturePro(pointer, animationFrame,
                   dst, vec, 0.0f, WHITE);
}

Rectangle Cursor::DrawRect()
{
    return { (float)m_x, (float)m_y,
             (float)pointer.width/3 * scale,
             (float)pointer.height * scale };
    }

Vector2 Cursor::GetVec(){
    return{ ((float)pointer.width/3 * scale / 2) + 25,
             (float)pointer.height * scale / 2 };
}
void Cursor::Update() {
    m_x = GetMouseX();
    m_y = GetMouseY();
}
// BUTTON FUNCS

Button::Button(int x, int y, Texture2D texture, int scale, int frames, Animation animation, int pixelx, int pixely)
: m_x{x}, m_y{y}, m_texture{texture}, m_scale {scale}, m_frames{frames}, m_animation{animation_frame(&animation, frames, pixelx, pixely)}, m_pixelx{pixelx}, m_pixely{pixely}
{}
void Button::Draw(){
        DrawTexturePro(m_texture, { 0, 0, (float)m_texture.width/m_frames, (float)m_texture.height},
                       { (float)m_x, (float)m_y,
                        (float)m_texture.width/m_frames * m_scale,
                        (float)m_texture.height * m_scale },
                       { (float)m_texture.width/m_frames * m_scale / 2,
                        (float)m_texture.height * m_scale / 2 },
                       0.0f,
                       WHITE);
        }

Rectangle Button::HitBox(){
    float width  = (float)m_texture.width / m_frames * (m_scale * 2/3);
    float height = (float)m_texture.height * (m_scale * 2/3);
    
    float left = (float)m_x - width / 2;
    float top  = (float)m_y - height / 2;
    //DrawRectangleLines(left, top, width, height, RED);
    
    return { left, top, width, height };
}
Rectangle Button::DrawRect() 
{
    float width  = (float)m_texture.width / m_frames * m_scale;
    float height = (float)m_texture.height * m_scale;

    return {
        (float)m_x,
        (float)m_y,
        width,
        height
    };
}

Vector2 Button::Vector(){
    return Vector2{
        (float)m_texture.width / m_frames * m_scale / 2,
        (float)m_texture.height * m_scale / 2
    };
}

void Button::Animate(){
    Rectangle dst = DrawRect();
    Vector2 vec = {dst.width/2 , dst.height/2};
    DrawTexturePro(m_texture, m_animation,
                   dst, vec, 0.0f, WHITE);
}
//void Cursor::debugXY(){
//    std::string strx = std::to_string(m_x);
//    std::string stry = std::to_string(m_y);
//    const char* x = strx.c_str();
//    const char* y = stry.c_str();
//    DrawText(x, 0, 0, 10, WHITE);
//    DrawText(y, 0, 10, 10, WHITE);
