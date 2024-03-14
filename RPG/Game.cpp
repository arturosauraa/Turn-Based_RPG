#include "Game.h"

Game::Game() : player(), map(), monster(), arena()
{
    camera.target = player.playerPos;
    camera.offset = (Vector2){GetScreenWidth()/2.0f,GetScreenHeight()/2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 2.0f;
    fightStart = false;
    arenaStarted = false;
}

void Game::GameUpdate()
{

    if(!fightStart)
    {
        if(player.IsPlayerCollidingMonster(monster.monsterList))
        {
            fightStart = true;
        }
        camera.target = player.playerPos;
        map.UpdateMap();
        player.UpdatePlayer();
        monster.MonstersUpdate();
    }
    if(fightStart)
    {
        if(!arenaStarted)
        {
            arena.GetMonster(player.monsterEncounter);
            arena.GetTeam(team.team);
            arenaStarted = true; 
        }
        else
        {
            arena.ArenaUpdate(monster.monsterList,fightStart,arenaStarted,player);
        }
    }

}

void Game::GameDraw()
{
    if(!fightStart)
    {
        BeginMode2D(camera);
        map.DrawMap();
        monster.MonstersDraw();
        player.DrawPlayer();
        EndMode2D();
    }
    else
    {
        arena.ArenaDraw();
    }
}
