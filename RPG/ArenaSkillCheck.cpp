#include "ArenaSkillCheck.h"

ArenaSkillCheck::ArenaSkillCheck()
{
}

void ArenaSkillCheck::ArenaSkillCheckUpdate()
{
}

bool ArenaSkillCheck::CheckManaLeft(Characters::Skill manaExpSkill, int manaLeft)
{
    if(manaExpSkill.manaExp <= manaLeft)
    {
        return true;
    }
    return false;
}

bool ArenaSkillCheck::CheckStaminaLeft(Characters::Skill staminaExpSkill, int staminaLeft)
{    
    if(staminaExpSkill.staminaExp <= staminaLeft)
    {
        return true;
    }
    return false;
}

void ArenaSkillCheck::AttackSkill(Characters::Character &character,int skillIndex, Monsters::Monster &monster, std::vector<std::pair<Monsters::Monster,Vector2>>& monsterInfo)
{
    if(character.skills[skillIndex].type == "Single Attack" )
    {
        int damage = character.skills[skillIndex].damage;
        monster.shieldLeft -= damage;

        if(damage > monster.shield)
        {
            damage -= monster.shield;
            monster.healthLeft -= damage;
        }
    }
    if(character.skills[skillIndex].type == "Multi Attack")
    {
        for(auto& monsters : monsterInfo)
        {
            int damage = character.skills[skillIndex].damage;
            monsters.first.shieldLeft -= damage;

            if(damage > monsters.first.shield)
            {
                damage -= monsters.first.shield;
                monsters.first.healthLeft -= damage;
            }
        }
    }

    
    character.staminaLeft -= character.skills[skillIndex].staminaExp;
    character.manaLeft -= character.skills[skillIndex].manaExp;

    character.animIndex = 1;
    character.anims[character.animIndex].source.x = character.anims[character.animIndex].originalSource.x;
}

void ArenaSkillCheck::BuffSkill(std::vector<std::pair<Characters::Character,Vector2>> &team, int skillIndex, int characterIndex)
{
    if(team[characterIndex].first.skills[skillIndex].name == "Shield")
    {
        team[characterIndex].first.shieldLeft += team[characterIndex].first.skills[skillIndex].defense;
    }
    if(team[characterIndex].first.skills[skillIndex].name == "Roar")
    {
        for(auto& character : team)
        {
            character.first.shieldLeft += team[characterIndex].first.skills[skillIndex].defense;
        }
    }
    if(team[characterIndex].first.skills[skillIndex].name == "Heal")
    {
        team[characterIndex].first.HPLeft += team[characterIndex].first.skills[skillIndex].healAmount;
        if(team[characterIndex].first.HPLeft > team[characterIndex].first.HP)
        {
            team[characterIndex].first.HPLeft = team[characterIndex].first.HP;
        }
    }
    if(team[characterIndex].first.skills[skillIndex].name == "Holy Heal")
    {
        for(auto& character : team)
        {
            character.first.HPLeft += team[characterIndex].first.skills[skillIndex].healAmount;
            if(character.first.HPLeft > character.first.HP)
            {
                character.first.HPLeft = character.first.HP;
            }
        }
    }
    team[characterIndex].first.manaLeft -= team[characterIndex].first.skills[skillIndex].manaExp;
    team[characterIndex].first.staminaLeft -= team[characterIndex].first.skills[skillIndex].staminaExp;

}

void ArenaSkillCheck::RestStaminaMana(std::vector<std::pair<Characters::Character, Vector2>> &team)
{
    for(auto& character : team)
    {
        character.first.manaLeft = character.first.mana;
        character.first.staminaLeft = character.first.stamina;
    }
}

bool ArenaSkillCheck::IsMonsterDead(std::vector<std::pair<Monsters::Monster,Vector2>>& monsterInfo)
{
    int i = 0;
    for(auto& monster : monsterInfo)
    {
        if(monster.first.healthLeft <= 0)
        {
            monster.first.animIndex = 2;
            if(monster.first.Isdead)
            {
                monsterInfo.erase(monsterInfo.begin() + i);
                return true;
            }
            
        }
        i++;
    }
    return false;
}


bool ArenaSkillCheck::IsAllMonsterDead(std::vector<std::pair<Monsters::Monster, Vector2>> monsterInfo)
{
    if(monsterInfo.empty())
    {
        return true;
    }
    return false;
}

bool ArenaSkillCheck::IsAllTeamDead(std::vector<std::pair<Characters::Character, Vector2>> teamInfo)
{
    if(teamInfo.empty())
    {
        return true;
    }
    return false;
}

bool ArenaSkillCheck::IsTeammatesDead(std::vector<std::pair<Characters::Character, Vector2>> &team)
{
    if(!team.empty())
    {
        for(int i = 0; i <= team.size() - 1; i++)
        {
            if(team[i].first.HPLeft <= 0)
            {
                team.erase(team.begin() + i);
                return true;
            }
        }
    }

    return false;
}

void ArenaSkillCheck::MonsterAttack(Monsters::Monster& monster,std::vector<std::pair<Characters::Character,Vector2>>& team)
{

    int random = (rand() % team.size());
    
    int damage = monster.monsterSkill[0].damage;
    damage -= team[random].first.shieldLeft;
    if(damage >= 0)
    {
        team[random].first.shieldLeft = 0;
        team[random].first.HPLeft -= damage;
    }
    else
    {
        damage = monster.monsterSkill[0].damage;
        team[random].first.shieldLeft -= damage;
    }
}

void ArenaSkillCheck::WinArena(std::vector<Monsters::Monster> &monsterList, Monsters::Monster monsterDead)
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

void ArenaSkillCheck::LoseArena(Player &player)
{
    player.playerPos = {100,100};
}

void ArenaSkillCheck::MonsterAnim(int& numMonsAttack,Monsters::Monster &monster,std::vector<std::pair<Characters::Character,Vector2>>& team)
{
    if(monster.name == "Slime")
    {
        if(monster.animIndex == 0)
        {
            monster.anims[monster.animIndex].frame++;
            if(monster.anims[monster.animIndex].frame > 12)
            {
                monster.anims[monster.animIndex].frame = 0;
                monster.anims[monster.animIndex].source.x += 32;
                if(monster.anims[monster.animIndex].source.x >=192)
                {
                    monster.anims[monster.animIndex].source = monster.anims[monster.animIndex].originalSource;
                }
            }
        }
        else if(monster.animIndex == 1)
        {
            monster.anims[monster.animIndex].frame++;
            if(monster.anims[monster.animIndex].frame > 6)
            {
                monster.anims[monster.animIndex].frame = 0;
                monster.anims[monster.animIndex].source.x += 32;
                if(monster.anims[monster.animIndex].source.x >= monster.anims[monster.animIndex].image.width)
                {
                    monster.anims[monster.animIndex].source = monster.anims[monster.animIndex].originalSource;
                    monster.animIndex = 0;
                    MonsterAttack(monster,team);
                    numMonsAttack++;
                }
            }
        }
        else if(monster.animIndex == 2)
        {
            monster.anims[monster.animIndex].frame++;
            if(monster.anims[monster.animIndex].frame > 6)
            {
                monster.anims[monster.animIndex].frame = 0;
                monster.anims[monster.animIndex].source.x += 32;
                if(monster.anims[monster.animIndex].source.x >= monster.anims[monster.animIndex].image.width)
                {
                    monster.anims[monster.animIndex].source.x -= 32;
                    monster.Isdead = true;
                }
            }
        }
    }
    if(monster.name == "Goblin")
    {
        if(monster.animIndex == 0)
        {
            monster.anims[monster.animIndex].frame++;
            if(monster.anims[monster.animIndex].frame > 12)
            {
                monster.anims[monster.animIndex].frame = 0;
                monster.anims[monster.animIndex].source.x += 32;
                if(monster.anims[monster.animIndex].source.x >=64)
                {
                monster.anims[monster.animIndex].source = monster.anims[monster.animIndex].originalSource;
                }
            }
        }
        else if(monster.animIndex == 1)
        {
            monster.anims[monster.animIndex].frame++;
            if(monster.anims[monster.animIndex].frame > 6)
            {
                monster.anims[monster.animIndex].frame = 0;
                monster.anims[monster.animIndex].source.x += 32;
                if(monster.anims[monster.animIndex].source.x >= 288)
                {
                    monster.anims[monster.animIndex].source = monster.anims[monster.animIndex].originalSource;
                    monster.animIndex = 0;
                    MonsterAttack(monster,team);
                    numMonsAttack++;
                }
            }
        }
        else if(monster.animIndex == 2)
        {
            monster.anims[monster.animIndex].frame++;
            if(monster.anims[monster.animIndex].frame > 6)
            {
                monster.anims[monster.animIndex].frame = 0;
                monster.anims[monster.animIndex].source.x += 32;
                if(monster.anims[monster.animIndex].source.x >= monster.anims[monster.animIndex].image.width)
                {
                    monster.anims[monster.animIndex].source.x -= 32;
                    monster.Isdead = true;
                }
            }
        }
        
    }

}

void ArenaSkillCheck::CharacterAnim(Characters::Character &character)
{
    if(character.animIndex == 1)
    {
        character.anims[character.animIndex].frame++;
        if(character.anims[character.animIndex].frame > 6)
        {
            character.anims[character.animIndex].frame = 0;
            character.anims[character.animIndex].source.x += 32;
            if(character.anims[character.animIndex].source.x >= character.anims[character.animIndex].endSource.x)
            {
            character.anims[character.animIndex].source = character.anims[character.animIndex].originalSource;
            character.animIndex = 0;
            }
        }
    }
    else if(character.animIndex == 0)
    {
        character.anims[character.animIndex].frame++;
        if(character.anims[character.animIndex].frame > 12)
        {
            character.anims[character.animIndex].frame = 0;
            character.anims[character.animIndex].source.x += 32;
            if(character.anims[character.animIndex].source.x >=64)
            {
            character.anims[character.animIndex].source = character.anims[character.animIndex].originalSource;
            }
        }
    }

}
