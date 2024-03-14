#pragma once
#include "Player.h"
#include "Monsters.h"
#include "Characters.h"

class ArenaSkillCheck
{
public:

    ArenaSkillCheck();
    void ArenaSkillCheckUpdate();
    
    bool CheckManaLeft(Characters::Skill manaExpSkill ,int manaLeft);
    bool CheckStaminaLeft(Characters::Skill staminaExpSkill ,int staminaLeft);
    void AttackSkill(Characters::Character& character,int skillIndex, Monsters::Monster& monster,std::vector<std::pair<Monsters::Monster,Vector2>>& monsterInfo);
    void BuffSkill(std::vector<std::pair<Characters::Character,Vector2>>& team, int skillIndex, int characterIndex);
    void RestStaminaMana(std::vector<std::pair<Characters::Character,Vector2>>& team);
    bool IsMonsterDead(std::vector<std::pair<Monsters::Monster,Vector2>>& monsterInfo);
    bool IsAllMonsterDead(std::vector<std::pair<Monsters::Monster,Vector2>> monsterInfo);
    bool IsAllTeamDead(std::vector<std::pair<Characters::Character,Vector2>> teamInfo);
    bool IsTeammatesDead(std::vector<std::pair<Characters::Character,Vector2>>& team);
    void MonsterAttack(std::vector<std::pair<Monsters::Monster,Vector2>>& monsterInfo,std::vector<std::pair<Characters::Character,Vector2>>& team);
    void MonsterBuff(Monsters::Monster& monster);
    void WinArena(std::vector<Monsters::Monster>& monsterList, Monsters::Monster monsterDead);
    void LoseArena(Player &player);

    void MonsterAnim(Monsters::Monster& monster);
    void CharacterAnim(Characters::Character& character);
private:
    Monsters monsters;
    Characters characters;
};