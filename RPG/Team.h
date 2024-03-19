#pragma once
#include "Characters.h"


class Team
{
public:

    Characters::Character player;
    Characters::Character mage;
    Characters::Character companion2;
    Characters::Character companion3;
    std::vector<Characters::Character> team;

    int typeSelected;

    Team();
    void TeamUpdate();
    void TeamDraw();
    void SetPlayer(int& typeSelect);

private:
Characters characters;
};