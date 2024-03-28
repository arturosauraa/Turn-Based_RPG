#pragma once
#include "Characters.h"
#include "math.h"

using namespace std;
class TeamSkills
{
public:
    TeamSkills();
    void TeamSkillsUpdate();
    bool CheckStaminaLeft(Characters::Skill skill, int staminaLeft);
    bool CheckManaLeft(Characters::Skill skill, int manaLeft);
    int CalculateDamage(Characters::Skill skill, Monsters::Monster monster);
    void AttackSkill(Characters::Character& character, Characters::Skill skill, Monsters::Monster& monster, vector<pair<Monsters::Monster,Vector2>>& monsterInfo);
    void Buff(Characters::Character& character, Characters::Skill skill, std::vector<std::pair<Characters::Character,Vector2>> &team, Monsters::Monster& monster, vector<pair<Monsters::Monster,Vector2>>& monsterInfo);
    bool IsAllTeamDead(std::vector<std::pair<Characters::Character,Vector2>> &team);
    bool IsTeammateDead(std::vector<std::pair<Characters::Character, Vector2>> &team);
    void LoseArena(Player& player);
    void Animations(Characters::Character& character);
    void RestStaminaMana(std::vector<std::pair<Characters::Character,Vector2>>& team);

private:

    Characters characters;
    Monsters monsters;

};