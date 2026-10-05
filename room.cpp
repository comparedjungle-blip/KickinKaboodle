//
//  Enemy.cpp
//  TheGame
//
//  Created by Isaiah Heinze on 2/6/26.
//

#include "room.h"
#include "Globals.h"


Room::Room()
    : m_x{ 1 }, m_y{ 1 }, m_texture_inside{ heart }, m_scale{ 3 }, m_frames{ 1 },
    m_animation{ animation_frame(&CursorAnimation, 1, 32, 32) },
    m_pixelx{ 32 }, m_pixely{ 32 }, m_texture_overworld{ heart }

{
}
Room::Room(int x, int y, Texture2D texture, int scale, int frames,
    int pixelx, int pixely, Animation animation, Texture2D insideTexture, std::string_view name)

    : m_x{ x }, m_y{ y }, m_texture_inside{ texture }, m_scale{ scale }, m_frames{ frames },
    m_animation{ animation_frame(&animation, frames, pixelx, pixely) },
    m_pixelx{ pixelx }, m_pixely{ pixely },
    m_texture_overworld{ insideTexture }, m_name{ name }

{
}

void Room::Draw(Texture2D texture) {
    DrawTexturePro(texture, {0, 0, (float)texture.width / m_frames, (float)texture.height},
        { (float)m_x, (float)m_y,
         (float)texture.width / m_frames * m_scale,
         (float)texture.height * m_scale },
        { (float)texture.width / m_frames * m_scale / 2,
         (float)texture.height * m_scale / 2 },
        0.0f,
        WHITE);
}



Rectangle Room::HitBox() {
    float width = ((float)m_texture_inside.width / m_frames * (m_scale * 2 / 3))+5; // room hitbox +5 is to ensure that room's hitbox is bigger than collision box
    float height = ((float)m_texture_inside.height * (m_scale * 2 / 3))+5;
    float left = (float)m_x - width / 2;
    float top = (float)m_y - height / 2;
    //DrawRectangleLines(left, top, width, height, RED);
    return { left, top, width, height };
}

Rectangle Room::DrawRect()
{
    float width = (float)m_texture_inside.width / m_frames * m_scale;
    float height = (float)m_texture_inside.height * m_scale;

    return {
        (float)m_x,
        (float)m_y,
        width,
        height
    };
}

Vector2 Room::Vector() {

    return Vector2{
        (float)m_texture_inside.width / m_frames * m_scale / 2,
        (float)m_texture_inside.height * m_scale / 2
    };
}

void Room::Animate() {
    
    Rectangle src = animation_frame(&ShopAnimation, 16, 256, 224);
    Rectangle dest = { (float)screenWidth / 2.0f, (float)screenHeight / 2.0f, 512.0f, 448.0f};
    Vector2 origin = { 256.0f, 224.0f }; // Center point of the 256x224 frame

    DrawTexturePro(m_texture_inside, src, dest, origin, 0.0f, WHITE);
}

PlayerChoice Room::GetChoice() {
    int choice = randomNumberGenerator(1, 3);
    switch (choice) {
    case 1:
    {
        return PlayerChoice::scissor;
        break;
    }
    case 2:
    {
        return PlayerChoice::rock;
        break;
    }
    case 3:
    {
        return PlayerChoice::paper;
        break;
    }
    }
    return PlayerChoice::none;
}



bool Room::IsActive() {
    return m_active;
}
void Room::Deactivate() { m_active = false; }



