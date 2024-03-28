#include "MonsterSkill.h"

MonsterSkill::MonsterSkill()
{
}

bool MonsterSkill::IsMonsterDead(std::vector<std::pair<Monsters::Monster, Vector2>> &monsterInfo)
{
    int i = 0;
    for(auto& monster : monsterInfo)
    {
        if(monster.first.basePower.HPLeft <= 0)
        {
            monster.first.animIndex = 2;
            if(monster.first.basePower.HPLeft <= 0)
            {
                monsterInfo.erase(monsterInfo.begin() + i);
                return true;
            }
            
        }
        i++;
    }
    return false;
}

bool MonsterSkill::IsAllMonsterDead(std::vector<std::pair<Monsters::Monster, Vector2>> monsterInfo)
{
    if(monsterInfo.empty())
    {
        return true;
    }
    return false;
}

int MonsterSkill::CalculateDamage(Monsters::Skill skill, Characters::Character &character)
{
    int ATK;
    int DEF;
    float damageDealt = 0;
    if(skill.type == "Physical")
    {
        ATK = skill.physicalDamage;
        DEF = character.defense.physical;
    }
    if(skill.type == "Magical")
    {
        ATK = skill.magicalDamage;
        DEF = character.defense.magical;
    }
    if(ATK >= DEF)
    {
        damageDealt = ATK - 0.79f * DEF * exp(-0.27f * (DEF/ATK));
    }
    else
    {
        damageDealt = 0.4f * ((ATK^3) / (DEF^2)) - 0.09f * ((ATK^2)/(DEF) + 0.1f * ATK);
    }
    
    return (int)damageDealt;
}

void MonsterSkill::MonsterAttack(Monsters::Monster &monster, std::vector<std::pair<Characters::Character, Vector2>> &team)
{
    int random = (rand() % team.size());
    int damageDealt = CalculateDamage(monster.skills[0], team[random].first);
    team[random].first.basePower.HPLeft -= damageDealt;
}

void MonsterSkill::MonsterBuff(Monsters::Monster &monster)
{
}

void MonsterSkill::WinArena(std::vector<Monsters::Monster> &monsterList, Monsters::Monster monsterDead)
{
    for(int i = 0; i < monsterList.size() ; i++)
    {
        if(monsterList[i].movement.monsterCenter.x == monsterDead.movement.monsterCenter.x)
        {
            monsterList.erase(monsterList.begin() + i);
            break;
        }
    }
}

void MonsterSkill::MonsterAnim(int &numMonsAttack, Monsters::Monster &monster, std::vector<std::pair<Characters::Character, Vector2>> &team)
{
    if(monster.name == "Slime")
    {
        if(monster.animIndex == 0)
        {
            monster.anim[monster.animIndex].frame++;
            if(monster.anim[monster.animIndex].frame > 12)
            {
                monster.anim[monster.animIndex].frame = 0;
                monster.anim[monster.animIndex].source.x += 32;
                if(monster.anim[monster.animIndex].source.x >=192)
                {
                    monster.anim[monster.animIndex].source = monster.anim[monster.animIndex].originalSource;
                }
            }
        }
        else if(monster.animIndex == 1)
        {
            monster.anim[monster.animIndex].frame++;
            if(monster.anim[monster.animIndex].frame > 6)
            {
                monster.anim[monster.animIndex].frame = 0;
                monster.anim[monster.animIndex].source.x += 32;
                if(monster.anim[monster.animIndex].source.x >= monster.anim[monster.animIndex].image.width)
                {
                    monster.anim[monster.animIndex].source = monster.anim[monster.animIndex].originalSource;
                    monster.animIndex = 0;
                    MonsterAttack(monster,team);
                    numMonsAttack++;
                }
            }
        }
        else if(monster.animIndex == 2)
        {
            monster.anim[monster.animIndex].frame++;
            if(monster.anim[monster.animIndex].frame > 6)
            {
                monster.anim[monster.animIndex].frame = 0;
                monster.anim[monster.animIndex].source.x += 32;
                if(monster.anim[monster.animIndex].source.x >= monster.anim[monster.animIndex].image.width)
                {
                    monster.anim[monster.animIndex].source.x -= 32;
                    monster.isDead = true;
                }
            }
        }
    }
    if(monster.name == "Goblin")
    {
        if(monster.animIndex == 0)
        {
            monster.anim[monster.animIndex].frame++;
            if(monster.anim[monster.animIndex].frame > 12)
            {
                monster.anim[monster.animIndex].frame = 0;
                monster.anim[monster.animIndex].source.x += 32;
                if(monster.anim[monster.animIndex].source.x >=64)
                {
                monster.anim[monster.animIndex].source = monster.anim[monster.animIndex].originalSource;
                }
            }
        }
        else if(monster.animIndex == 1)
        {
            monster.anim[monster.animIndex].frame++;
            if(monster.anim[monster.animIndex].frame > 6)
            {
                monster.anim[monster.animIndex].frame = 0;
                monster.anim[monster.animIndex].source.x += 32;
                if(monster.anim[monster.animIndex].source.x >= 288)
                {
                    monster.anim[monster.animIndex].source = monster.anim[monster.animIndex].originalSource;
                    monster.animIndex = 0;
                    MonsterAttack(monster,team);
                    numMonsAttack++;
                }
            }
        }
        else if(monster.animIndex == 2)
        {
            monster.anim[monster.animIndex].frame++;
            if(monster.anim[monster.animIndex].frame > 6)
            {
                monster.anim[monster.animIndex].frame = 0;
                monster.anim[monster.animIndex].source.x += 32;
                if(monster.anim[monster.animIndex].source.x >= monster.anim[monster.animIndex].image.width)
                {
                    monster.anim[monster.animIndex].source.x -= 32;
                    monster.isDead = true;
                }
            }
        }
        
    }
}
