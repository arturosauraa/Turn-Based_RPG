#pragma once
#include "Player.h"

class Characters
{
public:
    struct Skill
    {
        //Skill name
        std::string name;
        //Skill Type
        std::string type;
        //Mana needed for skill
        int manaExp;
        //stamina needed for skill
        int staminaExp;
        //Damage done by skill
        float damage;
        //defense obtained by skill
        float defense;
        //Hp healed by skill
        float health;
        //If this skill attacks one or more mosnters
        bool singleMonsterAttack;
        //If this skill is done to one or more players in the team;
        bool singlePlayerAttack;
    };
    struct Stats
    {
        //HP
        int vitality;
        //Damage/Defense/Stamina
        int strength;
        //Stamina/Defense
        int endurance;
        //Stamina
        int dexterity;
        //Defense
        int resistance;
        //Mana
        int intelligence;
    };
    struct Animation
    {
        Texture2D image;
        Rectangle originalSource;
        Rectangle source;
        int frame;
    };
    struct Character
    {
        //Character name
        std::string name;
        //Character type : Knigth/Archer/Mage/Assasin
        std::string type;
        //Character Icon
        Texture2D icon;
        Rectangle source;
        //Character Level
        int level;
        //Character HP
        int HP;
        int HPLeft;
        //Character Stamina
        int stamina;
        int staminaLeft;
        //Character Mana
        int mana;
        int manaLeft;
        //Character Shield
        int shield;
        int shieldLeft;
        //Character stats
        Stats stats;
        //Character skills
        std::vector<Skill> skills;
        int animIndex;
        std::vector<Animation> anims;
    };
    Character player;

    std::vector<Character> characterlist;


    Characters();
    void CharactersUpdate();
    void CharactersDraw();
    void CharacterCreation();
    Character PlayerCharacter();

private:


};