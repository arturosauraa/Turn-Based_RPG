#include "Team.h"

Team::Team()
{
    player = characters.PlayerCharacter();
    mage = characters.MageCreation();
    team.push_back(player);
    team.push_back(mage);
    typeSelected = 0;
}

void Team::TeamUpdate()
{
    team.clear();
    if(typeSelected == 0)
    {
        team.push_back(player);
    }
    if(typeSelected == 2)
    {
        team.push_back(player);
    }
    if(typeSelected == 3)
    {
        team.push_back(mage);
    }
    if(typeSelected == 3)
    {
        team.push_back(mage);
    }
}

void Team::TeamDraw()
{

}

void Team::SetPlayer(int &typeSelect)
{
    typeSelected = typeSelect;
}
