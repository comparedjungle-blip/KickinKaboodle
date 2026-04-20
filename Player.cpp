//
//  Player.cpp
//  TheGame
//
//  Created by Isaiah Heinze on 2/3/26.
//

#include "Player.hpp"

Player::Player(int x, int y)
    : m_x{x}, m_y{y}
{}

void Player::Draw() {
    DrawTexturePro(
        girl,
        { 0, 0, (float)girl.width / 4, (float)girl.height },
        { (float)m_x, (float)m_y,
          (float)girl.width / 4 * scale,
          (float)girl.height * scale },
        { (float)girl.width / 4 * scale / 2,
          (float)girl.height * scale / 2 },
        0.0f,
        WHITE
    );
}

void Player::Move() {
    float oldY = m_y;
    if (IsKeyDown(KEY_W) && walkableArea ) m_y -= speed;
    if (IsKeyDown(KEY_S) && walkableArea ) m_y += speed;
    if (CheckTileCollision(Player::HitBox()))
        m_y = oldY;
    
    float oldX = m_x;
    if (IsKeyDown(KEY_A) && walkableArea) m_x -= speed;
    if (IsKeyDown(KEY_D) && walkableArea) m_x += speed;
    if (CheckTileCollision(Player::HitBox()))
        m_x = oldX;
}

void Player::Animate(){
    if (walkableArea){         
        if (IsKeyDown(KEY_S)){
            DrawTexturePro(girl, animation_frame(&girl_walking, 4), position(), vector(), 0.0f, WHITE);
        }
        else if (IsKeyDown(KEY_D)){
            DrawTexturePro(girl_walking_sideways, animation_frame(&girl_walking, 4), position(), vector(), 0.0f, WHITE);}
        else if (IsKeyDown(KEY_A)){
            DrawTexturePro(girl_walking_sideways_right, animation_frame(&girl_walking, 4), position(), vector(), 0.0f, WHITE);}
        else if (IsKeyDown(KEY_W)){
            DrawTexturePro(girl_walking_up, animation_frame(&girl_walking, 4), position(), vector(), 0.0f, WHITE);
        }
        else Draw();
    }
}
Rectangle Player::position() const {
    return Rectangle{
        (float)m_x,
        (float)m_y,
        (float)girl.width / 4 * scale,
        (float)girl.height * scale
    };
}

Vector2 Player::vector() const {
    return Vector2{
        (float)girl.width / 4 * scale / 2,
        (float)girl.height * scale / 2
    };
}
Vector2 Player::PositionVector(){
    return{float(m_x),float(m_y)};
}
Rectangle Player::HitBox(){
    float width  = (float)((girl.width /4 ) * 2/3); //4 frames in girl texture
    float height = (float)(girl.height);
    float left = (float)m_x - width / 2;
    float top  = (float)m_y - height / 2;
    DrawRectangleLines(left, top, width, height, RED); //debug box
    return { left, top, width, height };
}

void Player::Lose(){
    m_health -=1;
}

void Player::Attack(Enemy& enemy){
    enemy.TakeDamage(m_attack);
    std::cout << "player dealt " << m_attack << " damage\n";
}

void Player::TakeDamage(int attack){
    m_health -= attack;
}
