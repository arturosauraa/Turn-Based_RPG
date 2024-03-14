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
    if(character.skills[skillIndex].name == "Stab")
    {
        int damage = character.skills[skillIndex].damage;
        monster.shieldLeft -= damage;

        if(damage > monster.shield)
        {
            damage -= monster.shield;
            monster.healthLeft -= damage;
        }
    }
    if(character.skills[skillIndex].name == "Swing")
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
        team[characterIndex].first.shield += team[characterIndex].first.skills[skillIndex].defense;
    }
    if(team[characterIndex].first.skills[skillIndex].name == "Roar")
    {
        for(auto& character : team)
        {
            character.first.shield += team[characterIndex].first.skills[skillIndex].defense;
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
            monsterInfo.erase(monsterInfo.begin() + i);
            return true;
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

void ArenaSkillCheck::MonsterAttack(std::vector<std::pair<Monsters::Monster,Vector2>>& monsterInfo,std::vector<std::pair<Characters::Character,Vector2>>& team)
{
    for(auto& monster : monsterInfo)
    {
        monster.first.animIndex = 1;
        int random = rand() % monster.first.monsterSkill.size();

        if(monster.first.monsterSkill[random].name == "attack")
        {
            int damage = monster.first.monsterSkill[random].damage;
            damage -= team[0].first.shieldLeft;
            if(damage >= 0)
            {
                team[0].first.shieldLeft = 0;
                team[0].first.HPLeft -= damage;
            }
        }
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

void ArenaSkillCheck::MonsterAnim(Monsters::Monster &monster)
{
    if(monster.name == "Slime")
    {
        if(monster.animIndex == 1)
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
                }
            }
        }
        else if(monster.animIndex == 0)
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
    }
    if(monster.name == "Goblin")
    {
        if(monster.animIndex == 1)
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
                }
            }
        }
        else if(monster.animIndex == 0)
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
            if(character.anims[character.animIndex].source.x >=288)
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
