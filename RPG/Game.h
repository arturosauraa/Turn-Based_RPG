#pragma once
#include "Arena.h"

class Game{

public:
    Camera2D camera;
    Game();
    void GameUpdate();
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

    bool exitGame = false;
    bool isOnMenu = true;
    
};