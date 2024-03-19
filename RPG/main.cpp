#include <raylib.h>
#include <iostream>
#include "Game.h"

using namespace std;





int main()
{
    InitWindow(1200, 800, "RPG");
    SetTargetFPS(60);
    Game game = Game();

    while(WindowShouldClose() == false)
    {
        BeginDrawing();

        //Update
        game.GameUpdate();
        

        ClearBackground(Color{80,100,60, 255});

        //Draw
        game.GameDraw();
        
        
        EndDrawing();
    }
    CloseWindow();
    return 0;
} 