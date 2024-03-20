#include "Team.h"

Team::Team()
{
    player = characters.KnigthCharacter();
    mage = characters.MageCreation();
    archer = characters.ArcherCharacter();
    warrior = characters.WarriorCharacter();
    typeSelected = 0;
}

void Team::TeamUpdate()
{

}

void Team::TeamDraw()
{

}


void Team::CreateTeam()
{
    team.push_back(archer);
    team.push_back(mage);
    team.push_back(warrior);
}
