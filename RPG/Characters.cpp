#include "Characters.h"

Characters::Characters()
{
    
}

Characters::Character Characters::CreateCharacter(std::string characterName,std::string characterClass)
{
    roleList = {"Knigth","Mage","Archer","Warrior"};
    Character character;
    character.name = characterName;
    character.role = GetRole(characterClass);
    character.level = 1;
    character.icon = GetIcon(character.role);
    character.attribute = GetAttributes(character.role);
    character.basePower = GetBasePower(character.level,character.attribute,character.role);
    character.skills = GetSkill(character.attribute,character.role);
    character.anim = GetAnim(character.role);
    character.animIndex = 0;
    return character;
}

std::string Characters::GetRole(std::string role)
{
    std::string roleName = "Knigth";
    for(auto roles : roleList)
    {
        if(roles == role)
        {
            roleName = roles;
        }
    }
    return roleName;
}

Characters::Icon Characters::GetIcon(std::string& role)
{
    Icon icon;
    if(role == "Knigth")
    {
        icon.image = LoadTexture("sprites/character/Human-Soldier-Red.png");
        icon.originalSource = {0,0,32.0f,32.0f};
        icon.frame = 0;
        icon.source = icon.originalSource;
        icon.endSource = {0,0,32.0f,32.0f};
    }
    else if(role == "Mage")
    {
        icon.image = LoadTexture("sprites/character/Mage-Red.png");
        icon.originalSource = {0,0,32.0f,32.0f};
        icon.frame = 0;
        icon.source = icon.originalSource;
        icon.endSource = {0,0,32.0f,32.0f};
    }
    else if(role == "Archer")
    {
        icon.image = LoadTexture("sprites/character/Archer-Green.png");
        icon.originalSource = {0,0,32.0f,32.0f};
        icon.frame = 0;
        icon.source = icon.originalSource;
        icon.endSource = {0,0,32.0f,32.0f};
    }
    else if(role == "Warrior")
    {
        icon.image = LoadTexture("sprites/character/Warrior-Blue.png");
        icon.originalSource = {0,0,32.0f,32.0f};
        icon.frame = 0;
        icon.source = icon.originalSource;
        icon.endSource = {0,0,32.0f,32.0f};
    }
    return icon;
}

Characters::Attributes Characters::GetAttributes(std::string& role)
{
    Attributes attributes;
    if(role == "Knigth")
    {
        Attributes attribute;
        attribute.vitality = 14;
        attribute.strength = 11;
        attribute.dexterity = 8;
        attribute.endurance = 10;
        attribute.resistance = 10;
        attribute.intelligence = 8;
        attributes = attribute;
    }
    else if(role == "Mage")
    {
        Attributes attribute;
        attribute.vitality = 8;
        attribute.strength = 9;
        attribute.dexterity = 11;
        attribute.endurance = 8;
        attribute.resistance = 8;
        attribute.intelligence = 15;
        attributes = attribute;
    }
    else if(role == "Archer")
    {
        Attributes attribute;
        attribute.vitality = 10;
        attribute.strength = 8;
        attribute.dexterity = 14;
        attribute.endurance = 9;
        attribute.resistance = 8;
        attribute.intelligence = 10;
        attributes = attribute;
    }
    else if(role == "Warrior")
    {
        Attributes attribute;
        attribute.vitality = 13;
        attribute.strength = 15;
        attribute.dexterity = 11;
        attribute.endurance = 10;
        attribute.resistance = 10;
        attribute.intelligence = 7;
        attributes = attribute;
    }
    return attributes;
}

Characters::Defense Characters::GetDefense(Attributes& attribute, std::string& role)
{
    Defense defense;
    defense.defense = (attribute.resistance * 0.5 + attribute.endurance * 0.25 );
    defense.physical = (attribute.resistance * 0.5 + attribute.endurance * 0.25 );
    defense.magical = (attribute.resistance * 0.25 + attribute.endurance * 0.25 + attribute.intelligence * 0.25);
    return defense;
}

Characters::BasePower Characters::GetBasePower(int level,Attributes& attribute, std::string& role)
{
    BasePower basePower;
    basePower.HP = GetHP(level,basePower.HP, attribute);
    basePower.HPLeft = basePower.HP;
    basePower.stamina = GetStamina(level,basePower.stamina, attribute);
    basePower.staminaLeft = basePower.stamina;
    basePower.mana = GetMana(level,basePower.mana, attribute);
    basePower.manaLeft = basePower.mana;

    return basePower;
}

int Characters::GetHP(int level,int HP,Attributes &attribute)
{
    
    int Health;
    int HPAmount = 1;
    int HPBonus = 1;
    std::vector<int> maxVit = {30,60,80,100};
    std::vector<int> HPAmountList = {10,10,5,5};
    std::vector<int> HPBonusList = {20,15,10,5};
    for(int i = 0; i < maxVit.size(); i++)
    {
        if(attribute.vitality < maxVit[i])
        {
            HPAmount = HPAmountList[i];
            HPBonus = HPBonusList[i];
        }
        else
        {
            HPAmount = 1;
            HPBonus = 5;
        }
    }
    if(level == 1) Health = 200;
    int randomHP = (rand() % HPAmount) + HPBonus;
    Health += (attribute.vitality * randomHP);
    return Health;
}

int Characters::GetStamina(int level,int CharacterStamina, Attributes &attribute)
{
    int stamina;
    int staminaAmount = 1;
    int staminaBonus = 1;
    std::vector<int> maxStamina = {30,60,80,100};
    std::vector<int> staminaAmountList = {10,10,5,5};
    std::vector<int> staminaBonusList = {20,15,10,5};
    for(int i = 0; i < maxStamina.size(); i++)
    {
        if(attribute.vitality < maxStamina[i])
        {
            staminaAmount = staminaAmountList[i];
            staminaBonus = staminaBonusList[i];
        }
        else
        {
            staminaAmount = 1;
            staminaBonus = 5;
        }
    }
    if(level == 1) stamina = 100;
    int randomMana = (rand() % staminaAmount) + staminaBonus;
    stamina += (attribute.vitality * randomMana);
    return stamina;
}

int Characters::GetMana(int level,int CharacterMana, Attributes &attribute)
{
    int mana;
    int manaAmount = 1;
    int manaBonus = 1;
    std::vector<int> maxMana = {30,60,80,100};
    std::vector<int> manaAmountList = {10,10,5,5};
    std::vector<int> manaBonusList = {20,15,10,5};
    for(int i = 0; i < maxMana.size(); i++)
    {
        if(attribute.vitality < maxMana[i])
        {
            manaAmount = manaAmountList[i];
            manaBonus = manaBonusList[i];
        }
        else
        {
            manaAmount = 1;
            manaBonus = 5;
        }
    }
    if(level == 1) mana = 100;
    int randomMana = (rand() % manaAmount) + manaBonus;
    mana += (attribute.vitality * randomMana);
    return mana;
}

std::vector<Characters::Animation> Characters::GetAnim(std::string& role)
{
    std::vector<Animation> anims;
    std::vector<Texture2D> imageList = {LoadTexture("sprites/character/Human-Soldier-Red.png"),LoadTexture("sprites/character/Mage-Red.png"),
    LoadTexture("sprites/character/Archer-Green.png"),LoadTexture("sprites/character/Warrior-Blue.png")};
    std::vector<Rectangle> attackSourceList = {{192,32,32.0f,32.0f},{384,32,32.0f,32.0f},{256,32,32.0f,32.0f},{128,32,32.0f,32.0f}};
    std::vector<Rectangle> attackEndSourceList = {{288,32,32.0f,32.0f},{480,32,32.0f,32.0f},{384,32,32.0f,32.0f},{256,32,32.0f,32.0f}};

    for(int i = 0; i <=3;i++)
    {
        if(roleList[i] == role)
        {
            Animation idle;
            idle.frame = 0;
            idle.image = imageList[i];
            idle.source = {0,32,32.0f,32.0f};
            idle.endSource = {64,32,32.0f,32.0f};
            idle.originalSource = idle.source;
            anims.push_back(idle);
            
            Animation attack;
            attack.frame = 0;
            attack.image = imageList[i];
            attack.source = attackSourceList[i];
            attack.endSource = attackEndSourceList[i];
            attack.originalSource = attack.source;
            anims.push_back(attack);
        }
    } 
    return anims;
}

std::vector<Characters::Skill> Characters::GetSkill(Attributes& attribute, std::string& role)
{
    Skill skill1;
    Skill skill2;
    Skill skill3;
    Skill skill4;
    std::vector<Skill> skillList;
    if(role == "Knigth")
    {
        skill1.name = "Stab";
        skill1.type = "Physical";
        skill1.staminaExp = 7;
        skill1.manaExp = 0;
        skill1.damagePhysical = 10 + (attribute.strength * 2);
        skill1.singleTarget = true;
        skill1.targetMonster = true;

        skill2.name = "Thrust";
        skill2.type = "Physical";
        skill2.staminaExp = 12;
        skill2.manaExp = 0;
        skill2.damagePhysical = 20 + (attribute.strength * 2);
        skill2.singleTarget = false;
        skill2.targetMonster = true;

        skill3.name = "Enhanced Armour";
        skill3.type = "Buff";
        skill3.staminaExp = 19;
        skill3.manaExp = 6;
        skill3.increaseDefensePhysical = 5;
        skill3.singleTarget = true;
        skill3.targetMonster = false;

        skill4.name = "Enhanced Blades";
        skill4.type = "Buff";
        skill4.singleTarget = true;
        skill4.staminaExp = 13;
        skill4.manaExp = 7;
        skill4.increaseDamagePhysical = 5;
        skill4.targetMonster = false;

    }
    if(role == "Mage")
    {
        skill1.name = "Soul Spear";
        skill1.type = "Magical";
        skill1.staminaExp = 3;
        skill1.manaExp = 10;
        skill1.damageMagic = 9 + (attribute.strength + attribute.intelligence );
        skill1.singleTarget = true;
        skill1.targetMonster = true;

        skill2.name = "Dragon Breath";
        skill2.type = "Magical";
        skill2.staminaExp = 7;
        skill2.manaExp = 15;
        skill2.damageMagic = 20 + (attribute.strength + attribute.intelligence );
        skill2.singleTarget = true;
        skill2.targetMonster = true;

        skill3.name = "Dark Orb";
        skill3.type = "Magical";
        skill3.staminaExp = 8;
        skill3.manaExp = 13;
        skill3.damageMagic = 25 + (attribute.strength + attribute.intelligence);
        skill3.selfDamage = 5;
        skill3.singleTarget = true;
        skill3.targetMonster = true;

        skill4.name = "Holy Heal";
        skill4.type = "Buff";
        skill4.healAmount = 50 + (attribute.intelligence * 2);
        skill4.staminaExp = 13;
        skill4.manaExp = 20;
        skill4.singleTarget = false;
        skill4.targetMonster = false;
    }
    if(role == "Archer")
    {
        skill1.name = "Simple Shot";
        skill1.type = "Physical";
        skill1.staminaExp = 11;
        skill1.manaExp = 0;
        skill1.damagePhysical = 10 + (attribute.strength * 2);
        skill1.singleTarget = true;
        skill1.targetMonster = true;

        skill2.name = "Storm Rain";
        skill2.type = "Physical";
        skill2.staminaExp = 15;
        skill2.manaExp = 0;
        skill2.damagePhysical = 17 + (attribute.strength * 2);
        skill2.singleTarget = false;
        skill2.targetMonster = true;

        skill3.name = "Magical Shot";
        skill3.type = "Magical";
        skill3.staminaExp = 10;
        skill3.manaExp = 17;
        skill3.damageMagic = 15 + (attribute.strength * 2);
        skill3.singleTarget = true;
        skill3.targetMonster = true;

        skill4.name = "Piercing Arrow";
        skill4.type = "Physical";
        skill4.staminaExp = 20;
        skill4.manaExp = 0;
        skill4.damagePhysical = 7 + (attribute.strength * 2);
        skill4.singleTarget = true;
        skill4.targetMonster = true;
    }
    if(role == "Warrior")
    {
        skill1.name = "Slash";
        skill1.type = "Physical";
        skill1.staminaExp = 8;
        skill1.manaExp = 0;
        skill1.damagePhysical = 14 + (attribute.strength * 2);
        skill1.singleTarget = true;
        skill1.targetMonster = true;

        skill2.name = "Strike";
        skill2.type = "Physical";
        skill2.staminaExp = 15;
        skill2.manaExp = 0;
        skill2.damagePhysical = 25 + (attribute.strength * 2);
        skill2.singleTarget = false;
        skill2.targetMonster = true;

        skill3.name = "Berserk";
        skill3.type = "Buff";
        skill3.staminaExp = 16;
        skill3.manaExp = 7;
        skill3.increaseDamagePhysical = 5;
        skill3.singleTarget = false;
        skill3.targetMonster = false;

        skill4.name = "Shout";
        skill4.type = "Buff";
        skill4.singleTarget = true;
        skill4.staminaExp = 20;
        skill4.manaExp = 10;
        skill4.targetMonster = true;
    }
    skillList.push_back(skill1);
    skillList.push_back(skill2);
    skillList.push_back(skill3);
    skillList.push_back(skill4);

    return skillList;
}


