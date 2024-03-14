#pragma once
#include "Player.h"
#include "Arena.h"

class Game{

public:
    Camera2D camera;
    Game();
    void GameUpdate();
    void GameDraw();

private:
    bool fightStart;
    Player player;
    Map map;
    Monsters monster;
    Arena arena;
    Team team;
    bool arenaStarted;
};