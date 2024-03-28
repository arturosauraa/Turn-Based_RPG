#include "TeamSkills.h"

TeamSkills::TeamSkills()
{
}

void TeamSkills::TeamSkillsUpdate()
{
}

bool TeamSkills::CheckStaminaLeft(Characters::Skill skill, int staminaLeft)
{
    if(skill.staminaExp <= staminaLeft)
    {
        return true;
    }
    return false;
}

bool TeamSkills::CheckManaLeft(Characters::Skill skill, int manaLeft)
{
    if(skill.manaExp <= manaLeft)
    {
        return true;
    }
    return false;
}

int TeamSkills::CalculateDamage(Characters::Skill skill, Monsters::Monster monster)
{
    int ATK;
    int DEF;
    float damageDealt = 0;
    if(skill.type == "Physical")
    {
        ATK = skill.damagePhysical;
        DEF = monster.defense.physicalDefense;
        if(skill.damagePhysical >= monster.defense.physicalDefense)
        {
            damageDealt = ATK - 0.79f * DEF * exp(-0.27f * (DEF/ATK));
        }
        else
        {
            damageDealt = 0.4f * ((ATK^3) / (DEF^2)) - 0.09f * ((ATK^2)/(DEF) + 0.1f * ATK);
        }
    }
    if(skill.type == "Magical")
    {
        ATK = skill.damageMagic;
        DEF = monster.defense.magicalDefense;
        if(skill.damagePhysical >= monster.defense.magicalDefense)
        {
            damageDealt = ATK - 0.79 * DEF * exp(-0.27f * (DEF/ATK));
        }
        else
        {
            damageDealt = 0.4f * ((ATK^3) / (DEF^2)) - 0.09f * ((ATK^2)/(DEF) + 0.1f * ATK);
        }
    }
    return (int)damageDealt;
}

void TeamSkills::AttackSkill(Characters::Character &character, Characters::Skill skill, Monsters::Monster &monster, vector<pair<Monsters::Monster, Vector2>> &monsterInfo)
{
    if(skill.singleTarget)
    {
        monster.basePower.HPLeft -= CalculateDamage(skill,monster);
    }
    else
    {
        for(auto& monsters : monsterInfo)
        {
            monsters.first.basePower.HPLeft -= CalculateDamage(skill, monsters.first);
        }
        if(skill.selfDamage >= 0 || skill.selfDamage <= 1000)
        {
            character.basePower.HPLeft -= skill.selfDamage;
        }
    }
    character.basePower.staminaLeft -= skill.staminaExp;
    character.basePower.manaLeft -= skill.manaExp;

    character.animIndex = 1;
    character.anim[character.animIndex].source.x = character.anim[character.animIndex].originalSource.x;
}

void TeamSkills::Buff(Characters::Character &character, Characters::Skill skill,std::vector<std::pair<Characters::Character,Vector2>> &team, Monsters::Monster& monster, vector<pair<Monsters::Monster,Vector2>>& monsterInfo)
{
    if(skill.targetMonster)
    {
        if(skill.singleTarget)
        {
            
        }
        if(!skill.singleTarget)
        {

        }
    }
    if(!skill.targetMonster)
    {
        if(skill.singleTarget)
        {
            character.basePower.HPLeft += skill.healAmount;
            if(character.basePower.HPLeft > character.basePower.HP) character.basePower.HPLeft = character.basePower.HP;
            character.defense.physical += skill.increaseDefensePhysical;
            character.defense.magical += skill.increaseDefenseMagic;
        }
        if(!skill.singleTarget)
        {
            for(auto characters : team)
            {
                characters.first.basePower.HPLeft += skill.healAmount;
                if(characters.first.basePower.HPLeft > characters.first.basePower.HP) characters.first.basePower.HPLeft = characters.first.basePower.HP;
                characters.first.defense.physical += skill.increaseDefensePhysical;
                characters.first.defense.magical += skill.increaseDefenseMagic;
            }
        }
    }

    character.basePower.staminaLeft -= skill.staminaExp;
    character.basePower.manaLeft -= skill.manaExp;
}
bool TeamSkills::IsTeammateDead(std::vector<std::pair<Characters::Character, Vector2>> &team)
{
    if(!team.empty())
    {
        for(int i = 0; i <= team.size() - 1; i++)
        {
            if(team[i].first.basePower.HPLeft <= 0)
            {
                team.erase(team.begin() + i);
                return true;
            }
        }
    }

    return false;
}

bool TeamSkills::IsAllTeamDead(std::vector<std::pair<Characters::Character, Vector2>> &team)
{
    if(team.empty())
    {
        return true;
    }
    return false;
}

void TeamSkills::LoseArena(Player &player)
{
    player.playerPos = {100,100};
}

void TeamSkills::RestStaminaMana(std::vector<std::pair<Characters::Character, Vector2>> &team)
{
    for(auto& characters : team)
    {
        characters.first.basePower.manaLeft = characters.first.basePower.mana;
        characters.first.basePower.staminaLeft = characters.first.basePower.stamina;
    }
}

void TeamSkills::Animations(Characters::Character &character)
{
    if(character.animIndex == 1)
    {
        character.anim[character.animIndex].frame++;
        if(character.anim[character.animIndex].frame > 6)
        {
            character.anim[character.animIndex].frame = 0;
            character.anim[character.animIndex].source.x += 32;
            if(character.anim[character.animIndex].source.x >= character.anim[character.animIndex].endSource.x)
            {
            character.anim[character.animIndex].source = character.anim[character.animIndex].originalSource;
            character.animIndex = 0;
            }
        }
    }
    else if(character.animIndex == 0)
    {
        character.anim[character.animIndex].frame++;
        if(character.anim[character.animIndex].frame > 12)
        {
            character.anim[character.animIndex].frame = 0;
            character.anim[character.animIndex].source.x += 32;
            if(character.anim[character.animIndex].source.x >=64)
            {
            character.anim[character.animIndex].source = character.anim[character.animIndex].originalSource;
            }
        }
    }
}


