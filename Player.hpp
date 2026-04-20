//
//  Player.hpp
//  TheGame
//
//  Created by Isaiah Heinze on 2/3/26.
//

#pragma once

#include "AnimationSystem.hpp"
#include "raylib.h"
#include "Globals.h"
#include "mechanics.hpp"
#include "TileMapping.hpp"
#include <iostream>

class Enemy;

class Player {
private:
    int m_x;
    int m_y;
    int speed{2};
    int m_health{30};
    int m_attack{10};
    int m_defense{10};
    int m_magic{10};
    int scale{1};

public:
    Player(int x, int y);

    void Draw();
    void Move();
    void Animate();
    void Lose();

    Rectangle position() const;
    Vector2 vector() const;
    Rectangle HitBox();
    Vector2 PositionVector();
    void Attack(Enemy& enemy);
    void TakeDamage(int attack);
};


