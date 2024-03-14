#pragma once
#include "raylib.h"
#include <iostream>
#include "Monsters.h"
class Player
{
public:
    Vector2 playerPos;
    Texture2D playerImg;
    Rectangle source;
    Vector2 playerCenter;
    int playerRadius;
    int frame;
    std::string direction;
    float speedX;
    float speedY;

    Monsters::Monster monsterEncounter;

    Player();
    void UpdatePlayer();
    void PlayerMovement();
    void DrawPlayer();
    void PlayerImg();
    void IsPlayerCollidingWall();
    bool IsPlayerCollidingMonster(std::vector<Monsters::Monster> monsterList);
    Rectangle RectangleScale(Rectangle rec, float xscale);

private:
Map map;
Monsters monster;

};