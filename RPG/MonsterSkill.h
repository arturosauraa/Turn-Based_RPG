#pragma once
#include "Characters.h"
#include "math.h"

using namespace std;
class MonsterSkill
{
public:

    MonsterSkill();
    bool IsMonsterDead(std::vector<std::pair<Monsters::Monster,Vector2>>& monsterInfo);
    bool IsAllMonsterDead(std::vector<std::pair<Monsters::Monster,Vector2>> monsterInfo);
    int CalculateDamage(Monsters::Skill skill,Characters::Character& character);
    void MonsterAttack(Monsters::Monster& monster,std::vector<std::pair<Characters::Character,Vector2>>& team);
    void MonsterBuff(Monsters::Monster& monster);
    void WinArena(std::vector<Monsters::Monster>& monsterList, Monsters::Monster monsterDead);

    void MonsterAnim(int& numMonsAttack,Monsters::Monster& monster, std::vector<std::pair<Characters::Character,Vector2>>& team);

private:


};