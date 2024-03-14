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
    player = PlayerCharacter();
}

Characters::Character Characters::PlayerCharacter()
{    
    player.name = "Player";
    player.type = "Knight";
    player.icon = LoadTexture("sprites/character/Human-Soldier-Red.png");
    player.source = {0,32,32.0f,32.0f};
    player.level = 1;
        //Player stats
    player.stats.vitality = 10;
    player.stats.strength = 5;
    player.stats.dexterity = 2;
    player.stats.endurance = 4;
    player.stats.intelligence = 1;
    player.stats.resistance = 6;
        //HP/Mana/Stamina
    player.mana = 5;
    player.manaLeft = player.mana;
    player.stamina = 20;
    player.staminaLeft = player.stamina;
    player.HP = 100 + (100 * (player.stats.vitality * 0.1));
    player.HPLeft = player.HP;
    player.shield = 5;
    player.shieldLeft= player.shield;

    //Skills
    //Skill 1
    Skill skill1;
    skill1.name = "Stab";
    skill1.type = "Attack";
    skill1.damage = 10;
    skill1.staminaExp = 6;
    skill1.manaExp = 0;
    skill1.singleMonsterAttack = true;
    //Skill 2
    Skill skill2;
    skill2.name = "Swing";
    skill2.type = "Attack";
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

    player.skills.push_back(skill1);
    player.skills.push_back(skill2);
    player.skills.push_back(skill3);
    player.skills.push_back(skill4);

    Animation idle;
    idle.frame = 0;
    idle.image = LoadTexture("sprites/character/Human-Soldier-Red.png");
    idle.source = {0,32,32.0f,32.0f};
    idle.originalSource = idle.source;
    player.anims.push_back(idle);
        Animation attack;
    attack.frame = 0;
    attack.image = LoadTexture("sprites/character/Human-Soldier-Red.png");
    attack.source = {192,32,32.0f,32.0f};
    attack.originalSource = attack.source;
    player.anims.push_back(attack);
    player.animIndex = 0;


    return player;
}
