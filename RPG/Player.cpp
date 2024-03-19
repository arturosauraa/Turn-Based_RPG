#include "Player.h"

Player::Player()
{
    playerImg = LoadTexture("sprites/character/Human-Soldier-Red.png");
    source = {0,32,32.0f,32.0f};
    playerPos = {75,75};
    frame = 0;
    speedX = 0;
    speedY = 0;
    direction = "south";
    playerCenter = {playerPos.x + 16, playerPos.y + 16};
    playerRadius = 7;
    playerType = "Knigth";
}

void Player::UpdatePlayer()
{
    // Update player movement
    PlayerMovement();
}
void Player::PlayerMovement()
{
    //Y Axis
    if(IsKeyDown(KEY_W))
    {
        speedY = -2;
        direction = "north";
    }
    if(IsKeyDown(KEY_S))
    {
        speedY = 2;
        direction = "south";
    } 
    // X Axis
    if(IsKeyDown(KEY_A))
    {
        speedX = -2;
        direction = "west";
    } 
    if(IsKeyDown(KEY_D))
    {
        speedX = 2;
        direction = "east";
    }
    if(IsKeyDown(KEY_W) && IsKeyDown(KEY_A)) direction = "northWest";
    if(IsKeyDown(KEY_W) && IsKeyDown(KEY_D)) direction = "northEast";
    if(IsKeyDown(KEY_S) && IsKeyDown(KEY_A)) direction = "southWest";
    if(IsKeyDown(KEY_S) && IsKeyDown(KEY_D)) direction = "southEast";
    if(!(IsKeyDown(KEY_W) || IsKeyDown(KEY_S)))
    {
        speedY = 0;
    }
    if(!( IsKeyDown(KEY_A) || IsKeyDown(KEY_D)))
    {
        speedX = 0;
    }
    //Checking if player is collinding
    IsPlayerCollidingWall();
    playerPos.x += speedX;
    playerPos.y += speedY;

    PlayerImg();

}
void Player::DrawPlayer()
{
    DrawTextureRec(playerImg,source,playerPos,WHITE); 
}

void Player::PlayerImg()
{
    if(direction == "south") source.y = 0;
    if(direction == "southEast") source.y = 32;
    if(direction == "east") source.y = 64;
    if(direction == "northEast") source.y = 96;
    if(direction == "north") source.y = 128;
    if(direction == "northWest") source.y = 160;
    if(direction == "west") source.y = 192;   
    if(direction == "southWest") source.y = 224;
    
    if(playerType == "Knigth")
    {
        frame++;
        if(frame > 12)
        {
            frame = 0;
            source.x += 32;
            if(source.x >= 64 && (speedX == 0 && speedY == 0))
            {

                source.x = 0;
            }
            if(source.x >= 160 && (speedX != 0 || speedY != 0))
            {
                source.x = 64;
            }
        }
    }
    else
    {
        frame++;
        if(frame > 12)
        {
            frame = 0;
            source.x += 32;
            if(source.x >= 64 && (speedX == 0 && speedY == 0))
            {

                source.x = 0;
            }
            if(source.x >= 128 && (speedX != 0 || speedY != 0))
            {
                source.x = 64;
            }
        }
    }

}

void Player::IsPlayerCollidingWall()
{
    playerCenter = {playerPos.x + 16, playerPos.y + 16};
    for(auto& rect: map.wallTileList)
    {
        if(CheckCollisionCircleRec({playerCenter.x, playerCenter.y + speedY},playerRadius,rect))
        {
            speedY = 0;
        }
        if(CheckCollisionCircleRec({playerCenter.x + speedX, playerCenter.y},playerRadius,rect))
        {
            speedX = 0;
        }
    }
}

bool Player::IsPlayerCollidingMonster(std::vector<Monsters::Monster> monsterList)
{
    playerCenter = {playerPos.x + 16, playerPos.y + 16};
    for(auto& monsters : monsterList)
    {
        if(CheckCollisionCircles(playerCenter,playerRadius,monsters.movement.monsterCenter,monsters.movement.monsterRadius))
        {
            monsterEncounter = monsters;
            return true;
        }
    }
    return false;
}

Rectangle Player::RectangleScale(Rectangle rec, float xscale)
{ 
    return (Rectangle){rec.x, rec.y, rec.width*xscale, rec.height};
}
