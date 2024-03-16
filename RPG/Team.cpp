#include "Team.h"

Team::Team()
{
    player = characters.PlayerCharacter();
    Characters::Character mage = characters.MageCreation();
    team.push_back(player);
    team.push_back(mage);
}

void Team::TeamUpdate()
{

}

void Team::TeamDraw()
{

}
