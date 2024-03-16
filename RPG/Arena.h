#pragma once
#include "Player.h"
#include "Team.h"
#include "ArenaSkillCheck.h"


class Arena
{
public:
    

    Arena();
    void ArenaUpdate(std::vector<Monsters::Monster>& monsterList,bool& figthStarted,bool& arenaStarted,Player &player);
    void GetMonster(Monsters::Monster& monster);
    void GetTeam(std::vector<Characters::Character>& team);
    void ArenaDraw();
    void TeamDraw();
    void MonsterDraw();
    void SelectCharacter();
    void CharacterSkillsDraw();
    void EndRound();
    void MonsterSkill();
    void CharacterSkill(int skillIndex);
    void RestartArena();
    void SelectMonster();
    void SelectSkill();
private:
    Texture2D tree;
    Texture2D grass;
    Texture2D dirt;
    Player player;
    Team team;
    Characters character;
    Monsters monster;
    ArenaSkillCheck ArenaSkillCheck;
    int arena1[7][19];

    //info of the team and monster
    std::vector<std::pair<Characters::Character,Vector2>> teamInfo;
    std::vector<std::pair<Monsters::Monster,Vector2>> monsterInfo;
    //position in which the team and monsters are going to be placed in the arena
    std::vector<Vector2> teamPos;
    std::vector<Vector2> monsterPos;

    Monsters::Monster monsterId;

    Rectangle roundBtn;


    std::vector<Rectangle> skillRec;
    std::vector<Rectangle> characterRec;

    bool characterSelected;
    int characterIndex;

    int round;
    int frame;
    bool usedAttack;
    int numMonsAttack;

    int selectedMonsterIndex;


    
};