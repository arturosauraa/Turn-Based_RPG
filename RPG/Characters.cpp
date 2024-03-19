#include "Characters.h"

Characters::Characters()
{
    CharacterCreation();
}

void Characters::CharactersUpdate()
{
}

void Characters::CharactersDraw()
{
}

void Characters::CharacterCreation()
{
    knigth = KnigthCharacter();
}

Characters::Character Characters::MageCreation()
{
    Character mage;
    mage.name = "Mage";
    mage.type = "Mage";
    mage.icon = LoadTexture("sprites/character/Mage-Red.png");
    mage.source = {0,0,32.0f,32.0f};
    mage.level = 1;
    mage.frame = 0;
        //mage stats
    mage.stats.vitality = 7;
    mage.stats.strength = 8;
    mage.stats.dexterity = 2;
    mage.stats.endurance = 2;
    mage.stats.intelligence = 7;
    mage.stats.resistance = 4;
        //HP/Mana/Stamina
    mage.mana = 40;
    mage.manaLeft = mage.mana;
    mage.stamina = 10;
    mage.staminaLeft = mage.stamina;
    mage.HP = 100 + (100 * (mage.stats.vitality * 0.1));
    mage.HPLeft = mage.HP;
    mage.shield = 2;
    mage.shieldLeft= mage.shield;

    //Skills
    //Skill 1
    Skill skill1;
    skill1.name = "Magic Arrow";
    skill1.type = "Single Attack";
    skill1.damage = 8;
    skill1.staminaExp = 2;
    skill1.manaExp = 8;
    skill1.singleMonsterAttack = true;
    //Skill 2
    Skill skill2;
    skill2.name = "Meteor";
    skill2.type = "Multi Attack";
    skill2.damage = 7;
    skill2.staminaExp = 4;
    skill2.manaExp = 10;
    skill2.singleMonsterAttack = false;
    //Skill 3
    Skill skill3;
    skill3.name = "Heal";
    skill3.type = "Buff";
    skill3.healAmount = 30;
    skill3.staminaExp = 5;
    skill3.manaExp = 15;
    skill3.singlePlayerAttack = true;
    //Skill 4
    Skill skill4;
    skill4.name = "Holy Heal";
    skill4.type = "Buff";
    skill4.healAmount = 20;
    skill4.staminaExp = 10;
    skill4.manaExp = 20;
    skill4.singlePlayerAttack = false;

    mage.skills.push_back(skill1);
    mage.skills.push_back(skill2);
    mage.skills.push_back(skill3);
    mage.skills.push_back(skill4);

    Animation idle;
    idle.frame = 0;
    idle.image = LoadTexture("sprites/character/Mage-Red.png");
    idle.source = {0,32,32.0f,32.0f};
    idle.endSource = {64,32,32.0f,32.0f};
    idle.originalSource = idle.source;
    mage.anims.push_back(idle);
        Animation attack;
    attack.frame = 0;
    attack.image = LoadTexture("sprites/character/Mage-Red.png");
    attack.source = {384,32,32.0f,32.0f};
    attack.endSource = {480,32,32.0f,32.0f};
    attack.originalSource = attack.source;
    mage.anims.push_back(attack);
    mage.animIndex = 0;

    return mage;
}

Characters::Character Characters::KnigthCharacter()
{    
    knigth.name = "Player";
    knigth.type = "Knight";
    knigth.icon = LoadTexture("sprites/character/Human-Soldier-Red.png");
    knigth.source = {0,0,32.0f,32.0f};
    knigth.level = 1;
    knigth.frame = 0;
        //Player stats
    knigth.stats.vitality = 10;
    knigth.stats.strength = 5;
    knigth.stats.dexterity = 2;
    knigth.stats.endurance = 4;
    knigth.stats.intelligence = 1;
    knigth.stats.resistance = 6;
        //HP/Mana/Stamina
    knigth.mana = 5;
    knigth.manaLeft = knigth.mana;
    knigth.stamina = 20;
    knigth.staminaLeft = knigth.stamina;
    knigth.HP = 100 + (100 * (knigth.stats.vitality * 0.1));
    knigth.HPLeft = knigth.HP;
    knigth.shield = 5;
    knigth.shieldLeft= knigth.shield;

    //Skills
    //Skill 1
    Skill skill1;
    skill1.name = "Stab";
    skill1.type = "Single Attack";
    skill1.damage = 10;
    skill1.staminaExp = 6;
    skill1.manaExp = 0;
    skill1.singleMonsterAttack = true;
    //Skill 2
    Skill skill2;
    skill2.name = "Swing";
    skill2.type = "Multi Attack";
    skill2.damage = 7;
    skill2.staminaExp = 8;
    skill2.manaExp = 0;
    skill2.singleMonsterAttack = false;
    //Skill 3
    Skill skill3;
    skill3.name = "Shield";
    skill3.type = "Buff";
    skill3.defense = 12;
    skill3.staminaExp = 7;
    skill3.manaExp = 0;
    skill3.singlePlayerAttack = true;
    //Skill 4
    Skill skill4;
    skill4.name = "Roar";
    skill4.type = "Buff";
    skill4.defense = 8;
    skill4.staminaExp = 5;
    skill4.manaExp = 4;
    skill4.singlePlayerAttack = false;

    knigth.skills.push_back(skill1);
    knigth.skills.push_back(skill2);
    knigth.skills.push_back(skill3);
    knigth.skills.push_back(skill4);

    Animation idle;
    idle.frame = 0;
    idle.image = LoadTexture("sprites/character/Human-Soldier-Red.png");
    idle.source = {0,32,32.0f,32.0f};
    idle.endSource = {64,32,32.0f,32.0f};
    idle.originalSource = idle.source;
    knigth.anims.push_back(idle);
        Animation attack;
    attack.frame = 0;
    attack.image = LoadTexture("sprites/character/Human-Soldier-Red.png");
    attack.source = {192,32,32.0f,32.0f};
    attack.endSource = {288,32,32.0f,32.0f};
    attack.originalSource = attack.source;
    knigth.anims.push_back(attack);
    knigth.animIndex = 0;


    return knigth;
}

Characters::Character Characters::ArcherCharacter()
{
    Character archer;
    archer.name = "Archer";
    archer.type = "Archer";
    archer.icon = LoadTexture("sprites/character/Archer-Green.png");
    archer.source = {0,0,32.0f,32.0f};
    archer.level = 1;
    archer.frame = 0;
        //archer stats
    archer.stats.vitality = 13;
    archer.stats.strength = 6;
    archer.stats.dexterity = 10;
    archer.stats.endurance = 2;
    archer.stats.intelligence = 5;
    archer.stats.resistance = 3;
        //HP/Mana/Stamina
    archer.mana = 25;
    archer.manaLeft = archer.mana;
    archer.stamina = 75;
    archer.staminaLeft = archer.stamina;
    archer.HP = 150 + (100 * (archer.stats.vitality * 0.1));
    archer.HPLeft = archer.HP;
    archer.shield = 3;
    archer.shieldLeft= archer.shield;

    //Skills
    //Skill 1
    Skill skill1;
    skill1.name = "Hawck Eye";
    skill1.type = "Single Attack";
    skill1.damage = 4;
    skill1.staminaExp = 2;
    skill1.manaExp = 0;
    skill1.singleMonsterAttack = true;
    //Skill 2
    Skill skill2;
    skill2.name = "Arrow Rain";
    skill2.type = "Multi Attack";
    skill2.damage = 6;
    skill2.staminaExp = 8;
    skill2.manaExp = 0;
    skill2.singleMonsterAttack = false;
    //Skill 3
    Skill skill3;
    skill3.name = "KillersEye";
    skill3.type = "Multi Attack";
    skill3.damage = 20;
    skill3.staminaExp = archer.stamina;
    skill3.manaExp = 10;
    skill3.singlePlayerAttack = false;
    //Skill 4
    Skill skill4;
    skill4.name = "Holy Rest";
    skill4.type = "Buff";
    skill4.healAmount = 200;
    skill4.staminaExp = archer.stamina;
    skill4.manaExp = 15;
    skill4.singlePlayerAttack = false;

    archer.skills.push_back(skill1);
    archer.skills.push_back(skill2);
    archer.skills.push_back(skill3);
    archer.skills.push_back(skill4);

    Animation idle;
    idle.frame = 0;
    idle.image = LoadTexture("sprites/character/Archer-Green.png");
    idle.source = {0,32,32.0f,32.0f};
    idle.endSource = {64,32,32.0f,32.0f};
    idle.originalSource = idle.source;
    archer.anims.push_back(idle);
        Animation attack;
    attack.frame = 0;
    attack.image = LoadTexture("sprites/character/Archer-Green.png");
    attack.source = {256,32,32.0f,32.0f};
    attack.endSource = {384,32,32.0f,32.0f};
    attack.originalSource = attack.source;
    archer.anims.push_back(attack);
    archer.animIndex = 0;

    return archer;
}

Characters::Character Characters::WarriorCharacter()
{
    Character warrior;
    warrior.name = "Warrior";
    warrior.type = "Warrior";
    warrior.icon = LoadTexture("sprites/character/Warrior-Blue.png");
    warrior.source = {0,0,32.0f,32.0f};
    warrior.level = 1;
    warrior.frame = 0;
        //mage stats
    warrior.stats.vitality = 8;
    warrior.stats.strength = 13;
    warrior.stats.dexterity = 3;
    warrior.stats.endurance = 7;
    warrior.stats.intelligence = 0;
    warrior.stats.resistance = 8;
        //HP/Mana/Stamina
    warrior.mana = 5;
    warrior.manaLeft = warrior.mana;
    warrior.stamina = 50;
    warrior.staminaLeft = warrior.stamina;
    warrior.HP = 125 + (100 * (warrior.stats.vitality * 0.1));
    warrior.HPLeft = warrior.HP;
    warrior.shield = 6;
    warrior.shieldLeft= warrior.shield;

    //Skills
    //Skill 1
    Skill skill1;
    skill1.name = "Strike";
    skill1.type = "Single Attack";
    skill1.damage = 9;
    skill1.staminaExp = 8;
    skill1.manaExp = 0;
    skill1.singleMonsterAttack = true;
    //Skill 2
    Skill skill2;
    skill2.name = "Thrust";
    skill2.type = "Multi Attack";
    skill2.damage = 8;
    skill2.staminaExp = 15;
    skill2.manaExp = 2;
    skill2.singleMonsterAttack = false;
    //Skill 3
    Skill skill3;
    skill3.name = "Maniac";
    skill3.type = "Buff";
    skill3.defense = 10;
    skill3.staminaExp = 8;
    skill3.manaExp = 0;
    skill3.singlePlayerAttack = true;
    //Skill 4
    Skill skill4;
    skill4.name = "Roar";
    skill4.type = "Buff";
    skill4.defense = 8;
    skill4.staminaExp = 5;
    skill4.manaExp = 4;
    skill4.singlePlayerAttack = false;

    warrior.skills.push_back(skill1);
    warrior.skills.push_back(skill2);
    warrior.skills.push_back(skill3);
    warrior.skills.push_back(skill4);

    Animation idle;
    idle.frame = 0;
    idle.image = LoadTexture("sprites/character/Warrior-Blue.png");
    idle.source = {0,32,32.0f,32.0f};
    idle.endSource = {64,32,32.0f,32.0f};
    idle.originalSource = idle.source;
    warrior.anims.push_back(idle);
        Animation attack;
    attack.frame = 0;
    attack.image = LoadTexture("sprites/character/Warrior-Blue.png");
    attack.source = {128,32,32.0f,32.0f};
    attack.endSource = {256,32,32.0f,32.0f};
    attack.originalSource = attack.source;
    warrior.anims.push_back(attack);
    warrior.animIndex = 0;

    return warrior;
}
