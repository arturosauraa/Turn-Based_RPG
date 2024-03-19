#pragma once
#include "Team.h"

class MainMenu
{
public:
    MainMenu();
    void Update(bool& isOnMenu, std::vector<Characters::Character>& team);
    void Draw(bool& exitGame);
    void ExitGame(bool& exitGame);
    void SelectNewGame();
    void SelectCharacter(bool& isOnMenu,std::vector<Characters::Character>& team);
    void ChangeFrames();
    bool newGame;
    bool selectCharacter;

private:
    Team team;
    Characters character;
    Characters::Character knight;
    Characters::Character mage;
    Characters::Character thief;
    Characters::Character archer;
    Rectangle rec1;
    Rectangle rec2;
    Rectangle rec3;
    Rectangle rec4;
    std::vector<std::pair<Characters::Character, Rectangle>> characterType;

    Rectangle selectrec1;
    Rectangle selectrec2;
    Rectangle selectrec3;
    Rectangle selectrec4;
    std::vector<Rectangle> selectList;

};