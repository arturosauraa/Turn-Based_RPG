#pragma once
#include "Arena.h"

class Game{

public:
    Camera2D camera;
    Game();
    void GameUpdate(bool& exitGame);
    void GameDraw();

private:
    MainMenu mainMenu;
    bool fightStart;
    Player player;
    Map map;
    Monsters monster;
    Arena arena;
    Team team;
    bool arenaStarted;

    bool isOnMenu = true;
    
};