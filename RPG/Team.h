#pragma once
#include "Characters.h"


class Team
{
public:

    Characters::Character player;
    Characters::Character companion1;
    Characters::Character companion2;
    Characters::Character companion3;
    std::vector<Characters::Character> team;

    Team();
    void TeamUpdate();
    void TeamDraw();

private:
Characters characters;
};