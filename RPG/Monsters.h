#pragma once
#include "Map.h"

using namespace std;

class Monsters
{
private:



    Map map;

public:

    struct Movement
    {
        Texture2D monsterImg;
        Rectangle monsterSource;
        Vector2 monsterPos;
        Vector2 monsterCenter;
        int monsterRadius;
        int frame;
        bool reverseImg;
    };
    struct Anim
    {
        string name;
        Texture2D image;
        Rectangle originalSource;
        Rectangle endSource;
        Rectangle source;
        int frame;
    };
    struct Defense
    {
        float physicalDefense;
        float magicalDefense;
    };
    struct BasePower
    {
        int HP;
        int HPLeft;
    };
    struct Skill
    {
        string name;
        string type;
        float physicalDamage;
        float magicalDamage;
    };

    struct Monster
    {
        string name;
        vector<Skill> skills;
        vector<Anim> anim;
        Defense defense;
        BasePower basePower;
        Movement movement;
        int animIndex;
        bool isDead;
    };
    vector<Monster> monsterList;
    vector<string> nameList;

    Monsters();
    void Update();
    void Draw();
    void MonsterPosition();
    void MovementInMap();
    Monster CreateMonster(string monsterName);
    Defense GetDefense(string monsterName);
    BasePower GetBasePower(string monsterName);
    Movement GetMovement(string monsterName);
    vector<Skill> GetSkills(string monsterName);
    vector<Anim> GetAnims(string monsterName);
};