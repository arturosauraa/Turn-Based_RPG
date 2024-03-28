#pragma once
#include "Player.h"

class Characters
{
public:
    struct Attributes
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
    struct Defense
    {
        int defense;
        int defenseLeft;
        int physical;
        int magical;
    };
    struct BasePower
    {
        //Character HP
        int HP;
        int HPLeft;
        //Character Stamina
        int stamina;
        int staminaLeft;
        //Character Mana
        int mana;
        int manaLeft;
    };
    struct Animation
    {
        Texture2D image;
        Rectangle originalSource;
        Rectangle endSource;
        Rectangle source;
        int frame;
    };
    struct Icon
    {
        Texture2D image;
        Rectangle originalSource;
        Rectangle endSource;
        Rectangle source;
        int frame;
    };
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
        float damagePhysical;
        //defense obtained by skill
        float increaseDefensePhysical;
        float increaseDefenseMagic;

        float increaseDamagePhysical;
        float increaseDamageMagic;
        //hp obtained by skill
        float healAmount;
        //Damage dealt to itself
        float selfDamage;
        //magic done by skill
        float damageMagic;
        //If this skill attacks one or more monsters
        bool singleTarget;
        //If this skill targets itself or more teamates
        bool targetMonster;
    };
    struct Character
    {
        std::string name;
        std::string role;
        int level;
        std::vector<Animation> anim;
        int animIndex;
        Icon icon;
        BasePower basePower;
        Defense defense;
        Attributes attribute;
        std::vector<Skill> skills;

    };
    
    std::vector<std::string> roleList;

    Characters();
    Character CreateCharacter(std::string characterName,std::string characterClass);
    std::string GetRole(std::string role);
    Icon GetIcon(std::string& role);
    Attributes GetAttributes(std::string& role);
    Defense GetDefense(Attributes& attribute, std::string& role);
    BasePower GetBasePower(int level, Attributes& attribute, std::string& role);
    int GetHP(int level,int HP,Attributes& attribute);
    int GetStamina(int level,int stamina,Attributes& attribute);
    int GetMana(int level,int mana,Attributes& attribute);
    std::vector<Animation> GetAnim(std::string& role);
    std::vector<Skill> GetSkill(Attributes& attribute, std::string& role);

    Character knigth;

    std::vector<Character> characterlist;


    

};