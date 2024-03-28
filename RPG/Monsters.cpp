#include "Monsters.h"

Monsters::Monsters()
{
    nameList = {"Slime", "Simple Goblin"};
    for(int i = 0; i < 20; i++)
    {
        int random = (rand() % 1);
        monsterList.push_back(CreateMonster(nameList[random]));
    }

    MonsterPosition();
}

void Monsters::Update()
{
    MovementInMap();
}

void Monsters::Draw()
{
    for(auto& monster : monsterList)
    {
        DrawTextureRec(monster.movement.monsterImg,monster.movement.monsterSource, monster.movement.monsterPos, WHITE);
    }
}

void Monsters::MonsterPosition()
{
    int i = 300;
    for(auto& monster : monsterList)
    {
        int random = rand() % map.cellWithoutTrees.size() - 1;
        
        monster.movement.monsterPos = map.cellWithoutTrees[random];
        monster.movement.monsterCenter = {monster.movement.monsterPos.x + 10, monster.movement.monsterPos.y + 10};
    } 
}

void Monsters::MovementInMap()
{
    for(auto& monster : monsterList)
    {
        monster.movement.frame++;

        if(monster.name == "Slime")
        {
            if(monster.movement.frame > 6)
            {
                monster.movement.frame = 0;
                if(monster.movement.monsterSource.x <= 192 && monster.movement.reverseImg == false)
                {
                    monster.movement.monsterSource.x += 32;
                }
                if(monster.movement.monsterSource.x >= 192)
                {
                    monster.movement.reverseImg = true;
                }
                if(monster.movement.reverseImg == true)
                {
                    monster.movement.monsterSource.x -= 32;
                    if(monster.movement.monsterSource.x == 0)
                    {
                        monster.movement.reverseImg = false;
                    }
                }
            }
        }
        if(monster.name == "Goblin")
        {
            if(monster.movement.frame > 12)
            {   
                monster.movement.frame = 0;
                monster.movement.monsterSource.x += 32;
                if(monster.movement.monsterSource.x >= 64)
                {
                    monster.movement.monsterSource.x = 0;
                }
            }
        }
    }
}

Monsters::Monster Monsters::CreateMonster(string monsterName)
{
    Monster monster;
    monster.name = monsterName;
    monster.basePower = GetBasePower(monsterName);
    monster.defense = GetDefense(monsterName);
    monster.movement = GetMovement(monsterName);
    monster.anim = GetAnims(monsterName);
    monster.skills = GetSkills(monsterName);
    monster.animIndex = 0;
    monster.isDead = false;

    return monster;
}

Monsters::Defense Monsters::GetDefense(string monsterName)
{
    Defense defense;
    int physicalDefense;
    int magicalDefense;
    if(monsterName == "Simple Goblin")
    {
        physicalDefense = (rand() % 10) + 20;
        magicalDefense = (rand() % 1) + 10;
    }
    if(monsterName == "Slime")
    {
        physicalDefense = (rand() % 10) + 15;
        magicalDefense = (rand() % 1) + 5;
    }
    defense.physicalDefense = physicalDefense;
    defense.magicalDefense = magicalDefense;
    return defense;
}

Monsters::BasePower Monsters::GetBasePower(string monsterName)
{
    BasePower basePower;
    int monsterHP;
    if(monsterName == "Slime")
    {
        monsterHP = (rand() % 100) + 80;
    }
    if(monsterName == "Simple Goblin")
    {
        monsterHP = (rand() % 77) + 100;
    }
    basePower.HP = monsterHP;
    basePower.HPLeft = basePower.HP;
    return basePower;
}

Monsters::Movement Monsters::GetMovement(string monsterName)
{
    Movement movement;
    if(monsterName == "Slime")
    {
        movement.monsterImg = LoadTexture("sprites/monster/Slime.png");
        movement.frame = 0;
        movement.monsterSource = {0,32,32.0f,32.0f};
        movement.monsterPos = {0,0};
        movement.monsterRadius = 5;
        movement.monsterCenter = {movement.monsterPos.x + 10, movement.monsterPos.y + 10};
        movement.reverseImg = false;
    }
    if(monsterName == "Simple Goblin")
    {
        movement.monsterImg = LoadTexture("sprites/monster/Orc-Peon-Cyan.png");
        movement.frame = 0;
        movement.monsterSource = {0,0,32.0f,32.0f};
        movement.monsterPos = {0,0};
        movement.monsterRadius = 5;
        movement.monsterCenter = {movement.monsterPos.x + 10, movement.monsterPos.y + 10};
    }
    return movement;
}

vector<Monsters::Skill> Monsters::GetSkills(string monsterName)
{
    vector<Skill> skillList;
    Skill skill1;
    Skill skill2;
    Skill skill3;
    Skill skill4;
    if(monsterName == "Slime")
    {
        skill1.name = "Attack";
        skill1.type = "Magical";
        skill1.magicalDamage = (rand() % 10) + 13;
    }
    if(monsterName == "Simple Goblin")
    {
        skill1.name = "Attack";
        skill1.type = "Physical";
        skill1.physicalDamage = (rand() % 10) + 20;
        skillList.push_back(skill1);
    }
    skillList.push_back(skill1);
    return skillList;
}

vector<Monsters::Anim> Monsters::GetAnims(string monsterName)
{
    vector<Anim> animList;
    Anim idle;
    Anim attack;
    Anim die;
    if(monsterName == "Slime")
    {
        idle.frame = 0;
        idle.image = LoadTexture("sprites/monster/Slime.png");
        idle.source = {0,0,32.0f,32.0f};
        idle.endSource = {192,0,32.0f,32.0f};
        idle.originalSource = idle.source;
        animList.push_back(idle);

        die.frame = 0;
        die.image = LoadTexture("sprites/monster/Slime.png");
        die.source = {192,0,32.0f,32.0f};
        die.endSource = {(float)die.image.width, 0, 32.0f, 32.0f};
        die.originalSource = die.source;
        animList.push_back(die);
    }
    if(monsterName == "Simple Goblin")
    {
        idle.frame = 0;
        idle.image = LoadTexture("sprites/monster/Orc-Peon-Cyan.png");
        idle.source = {0,(float)idle.image.height - 32,32.0f,32.0f};
        idle.endSource = {64,(float)idle.image.height - 32,32.0f,32.0f};
        idle.originalSource = idle.source;
        animList.push_back(idle);

        attack.frame = 0;
        attack.image = LoadTexture("sprites/monster/Orc-Peon-Cyan.png");
        attack.source = {192,(float)idle.image.height - 32,32.0f,32.0f};
        attack.endSource = {288,(float)idle.image.height - 32,32.0f,32.0f};
        attack.originalSource = attack.source;
        animList.push_back(attack);

        die.frame = 0;
        die.image = LoadTexture("sprites/monster/Orc-Peon-Cyan.png");
        die.source = {640,(float)idle.image.height - 32,32.0f,32.0f};
        die.endSource = {(float)die.image.width, (float)idle.image.height - 32, 32.0f, 32.0f};
        die.originalSource = die.source;
        animList.push_back(die);
    }
    return animList;
}
