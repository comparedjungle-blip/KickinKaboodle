//
//  Enemy.cpp
//  TheGame
//
//  Created by Isaiah Heinze on 2/6/26.
//

#include "Enemy.hpp"


Enemy::Enemy()
: m_x{1}, m_y{1}, m_texture{heart}, m_scale {3}, m_frames{1},
m_animation{animation_frame(&CursorAnimation, 1, 32, 32)},
m_pixelx{32}, m_pixely{32}, m_health{1}, m_battleTexture{heart}

{}
Enemy::Enemy(int x, int y, Texture2D texture, int scale, int frames,
             int pixelx, int pixely, int health, int attack, Animation animation, Texture2D battleTexture)

: m_x{x}, m_y{y}, m_texture{texture}, m_scale {scale}, m_frames{frames},
m_animation{animation_frame(&animation, frames, pixelx, pixely)},
m_pixelx{ pixelx }, m_pixely{ pixely }, m_health{ health }, m_attack{attack}, m_battleTexture {
    battleTexture
}

{}

void Enemy::Draw(){
        DrawTexturePro(m_texture, { 0, 0, (float)m_texture.width/m_frames, (float)m_texture.height},
                       { (float)m_x, (float)m_y,
                        (float)m_texture.width/m_frames * m_scale,
                        (float)m_texture.height * m_scale },
                       { (float)m_texture.width/m_frames * m_scale / 2,
                        (float)m_texture.height * m_scale / 2 },
                       0.0f,
                       WHITE);
        }
void Enemy::Move(){
    m_x += m_speed;
    if (m_x >= (GetScreenWidth() - m_texture.width/2)){
        m_speed *= -1;
    }
    if (m_x <= (0 + m_texture.width/2))
        m_speed *=-1;
        
}
void Enemy::DrawBattle(){
    int scale = 3;
    int x = screenWidth * 4/5;
    int y = (screenHeight * 2/5);
    DrawTexturePro(m_battleTexture, { 0, 0, (float)m_battleTexture.width, (float)m_battleTexture.height},
                   { (float)x, (float)y,
                    (float)m_battleTexture.width * scale,
                    (float)m_battleTexture.height * scale },
                   { (float)m_battleTexture.width* scale / 2,
                    (float)m_battleTexture.height * scale / 2 },
                   0.0f,
                   WHITE);
    }

Rectangle Enemy::HitBox(){
    float width  = (float)m_texture.width / m_frames * (m_scale * 2/3);
    float height = (float)m_texture.height * (m_scale * 2/3);
    float left = (float)m_x - width / 2;
    float top  = (float)m_y - height / 2;
    //DrawRectangleLines(left, top, width, height, RED);
    return { left, top, width, height };
}

Rectangle Enemy::DrawRect()
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

Vector2 Enemy::Vector(){
    
    return Vector2{
        (float)m_texture.width / m_frames * m_scale / 2,
        (float)m_texture.height * m_scale / 2
    };
}

void Enemy::Animate(){
    Rectangle dst = DrawRect();
    Vector2 vec = {dst.width/2 , dst.height/2};
    DrawTexturePro(m_texture, m_animation,
                   dst, vec, 0.0f, WHITE);
}
void Enemy::Lose(){
    m_health -=1;
}
bool Enemy::Dead(){
    return !(m_health>0);
}
PlayerChoice Enemy::GetChoice(){
    int choice = randomNumberGenerator(1, 3);
    switch (choice){
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

void Enemy::PrintHealth(){
    
    std::cout<< m_health<< std::endl;
}

bool Enemy::IsActive(){
    return m_active;
}
void Enemy::Deactivate(){m_active = false;}

void Enemy::Attack(Player player){
    player.TakeDamage(m_attack);
    std::cout <<  m_name << "dealt " << m_attack << " damage\n";
}

void Enemy::TakeDamage(int attack){
    m_health -= attack;
}
