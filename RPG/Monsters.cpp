#include "Monsters.h"

Monsters::Monsters()
{
    posCompleted = false;
    for(int i = 0; i< 10; i++)
    {
        Slime();
        Goblin();
    }    
    
    MonsterPosition();
}

void Monsters::MonstersUpdate()
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

void Monsters::MonstersDraw()
{
    for(auto& monster : monsterList)
    {
        DrawTextureRec(monster.movement.monsterImg,monster.movement.monsterSource, monster.movement.monsterPos, WHITE);
    }
}

void Monsters::MonsterMovement()
{

}

void Monsters::Slime()
{
    slime.name = "Slime";
    slime.movement.speedX = 2;
    slime.movement.speedY = 2;
    slime.movement.monsterImg = LoadTexture("sprites/monster/Slime.png");
    slime.movement.frame = 0;
    slime.movement.monsterSource = {0,32,32.0f,32.0f};
    slime.movement.monsterPos = {0,0};
    slime.movement.monsterRadius = 5;
    slime.movement.monsterCenter = {slime.movement.monsterPos.x + 10, slime.movement.monsterPos.y + 10};

    slime.health = 100;
    slime.healthLeft = 100;
    slime.shield = 2;
    slime.shieldLeft = slime.shield;
    slime.Isdead = false;
    MonsterSkill skill1;
    skill1.name = "attack";
    skill1.damage = 5;
    skill1.defense = 1;
    skill1.repeatAttack = 0;
    skill1.singleAttack = true;
    slime.monsterSkill.push_back(skill1);

    Animation idle;
    idle.frame = 0;
    idle.image = LoadTexture("sprites/monster/Slime.png");
    idle.source = {0,0,32.0f,32.0f};
    idle.originalSource = idle.source;
    slime.anims.push_back(idle);
        Animation die;
    die.frame = 0;
    die.image = LoadTexture("sprites/monster/Slime.png");
    die.source = {192,0,32.0f,32.0f};
    die.originalSource = die.source;
    slime.anims.push_back(die);
    slime.animIndex = 0;

    monsterList.push_back(slime);
}

void Monsters::Goblin()
{
    goblin.name = "Goblin";
    goblin.movement.speedX = 2;
    goblin.movement.speedY = 2;
    goblin.movement.monsterImg = LoadTexture("sprites/monster/Orc-Peon-Cyan.png");
    goblin.movement.frame = 0;
    goblin.movement.monsterSource = {0,0,32.0f,32.0f};
    goblin.movement.monsterPos = {0,0};
    goblin.movement.monsterRadius = 5;
    goblin.movement.monsterCenter = {goblin.movement.monsterPos.x + 10, goblin.movement.monsterPos.y + 10};

    goblin.health = 200;
    goblin.healthLeft = goblin.health;
    goblin.shield = 5;
    goblin.shieldLeft = goblin.shield;
    goblin.Isdead = false;
    MonsterSkill skill1;
    skill1.name = "attack";
    skill1.damage = 7;
    skill1.defense = 3;
    skill1.repeatAttack = 0;
    skill1.singleAttack = true;
    goblin.monsterSkill.push_back(skill1);

        Animation idle;
    idle.frame = 0;
    idle.image = LoadTexture("sprites/monster/Orc-Peon-Cyan.png");
    idle.source = {0,(float)idle.image.height - 32,32.0f,32.0f};
    idle.originalSource = idle.source;
    goblin.anims.push_back(idle);
        Animation attack;
    attack.frame = 0;
    attack.image = LoadTexture("sprites/monster/Orc-Peon-Cyan.png");
    attack.source = {192,(float)idle.image.height - 32,32.0f,32.0f};
    attack.originalSource = attack.source;
    goblin.anims.push_back(attack);
    goblin.animIndex = 0;
        Animation die;
    die.frame = 0;
    die.image = LoadTexture("sprites/monster/Orc-Peon-Cyan.png");
    die.source = {640,(float)idle.image.height - 32,32.0f,32.0f};
    die.originalSource = die.source;
    goblin.anims.push_back(die);
    goblin.animIndex = 0;

    monsterList.push_back(goblin);
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
