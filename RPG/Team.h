#pragma once
#include "Characters.h"


class Team
{
public:

    Characters::Character player;
    Characters::Character mage;
    Characters::Character archer;
    Characters::Character warrior;
    std::vector<Characters::Character> team;

    int typeSelected;

    Team();
    void TeamUpdate();
    void TeamDraw();
    void CreateTeam();

private:
Characters characters;
};