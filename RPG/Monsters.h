#pragma once
#include "Map.h"

class Monsters
{
public:

    struct MonsterSkill
    {
        std::string name;
        float damage;
        float defense;
        bool singleAttack;
        int repeatAttack;
    };
    struct Animation
    {
        Texture2D image;
        Rectangle originalSource;
        Rectangle source;
        int frame;
    };
    struct MonsterMovement
    {
        
        Texture2D monsterImg;
        Rectangle monsterSource;
        Vector2 monsterPos;
        Vector2 monsterCenter;
        int monsterRadius;
        int frame;
        std::string direction;
        float speedX;
        float speedY;
        bool reverseImg;
    };
    struct Monster
    {
        std::string name;
        int health;
        int healthLeft;
        int shield;
        int shieldLeft;
        bool Isdead;
        MonsterMovement movement;
        std::vector<MonsterSkill> monsterSkill;
        int animIndex;
        std::vector<Animation> anims;
    };


    Monster goblin;
    Monster slime;
    std::vector<Monster> monsterList;

    Monsters();
    void MonstersUpdate();
    void MonstersDraw();
    void MonsterMovement();
    void Slime();
    void Goblin();
    void MonsterPosition();
private:
    Map map;
    int posCompleted;

};