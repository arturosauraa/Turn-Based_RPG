#include "MainMenu.h"

MainMenu::MainMenu()
{
    newGame = false;
    selectCharacter = false;
    knight = character.CreateCharacter("Simple Knigth", "Knigth");
    mage = character.CreateCharacter("Simple Mage", "Mage");
    archer = character.CreateCharacter("Simple Archer", "Archer");
    warrior = character.CreateCharacter("Simple Warrior", "Warrior");

    rec1 = {25, 200, 250, 400};
    rec2 = {325, 200, 250, 400};
    rec3 = {625, 200, 250, 400};
    rec4 = {925, 200, 250, 400};

    characterType.push_back(std::make_pair(knight,rec1));
    characterType.push_back(std::make_pair(mage,rec2));
    characterType.push_back(std::make_pair(archer,rec3));
    characterType.push_back(std::make_pair(warrior,rec4));

    selectrec1 = {25, 625, 250, 100};
    selectrec2 = {325, 625, 250, 100};
    selectrec3 = {625, 625, 250, 100};
    selectrec4 = {925, 625, 250, 100};
    selectList.push_back(selectrec1);
    selectList.push_back(selectrec2);
    selectList.push_back(selectrec3);
    selectList.push_back(selectrec4);

}

void MainMenu::Update(bool& isOnMenu,std::vector<Characters::Character>& team, bool& exitGame, Player& player)
{
    if(!newGame)
    {
        SelectNewGame();
        ExitGame(exitGame);
    }
    else
    {
        SelectCharacter(isOnMenu,team,player);
    }
}

void MainMenu::Draw()
{
    if(!newGame)
    {
        DrawRectangle(0,0,GetScreenWidth(),GetScreenHeight(), BLACK);
        //NEW GAME
        DrawRectangleLines(GetScreenWidth()/2 - 100, GetScreenHeight()/2 - 150, 200, 100, WHITE);
        DrawText("NEW GAME", GetScreenWidth()/ 2 - 80, GetScreenHeight()/2 - 130, 30, WHITE);
        //SETTINGS
        DrawRectangleLines(GetScreenWidth()/2 - 100, GetScreenHeight()/2, 200, 100, WHITE);
        DrawText("SETTINGS", GetScreenWidth()/ 2 - 70, GetScreenHeight()/2 + 30, 30, WHITE);
        //EXIT
        DrawRectangleLines(GetScreenWidth()/2 - 100, GetScreenHeight()/2 + 150, 200, 100, WHITE);
        DrawText("EXIT", GetScreenWidth()/ 2 - 50, GetScreenHeight()/2 + 180, 30, WHITE);
    }
    else if(newGame)
    {
        DrawRectangle(0,0,GetScreenWidth(),GetScreenHeight(), BLACK);
        for(auto& character : characterType)
        {
            DrawRectangleLinesEx(character.second, 2, WHITE);
            DrawText(character.first.role.c_str(),character.second.x + 100,character.second.y + 20, 20, WHITE);
            DrawTexturePro(character.first.icon.image,character.first.icon.source,Rectangle{character.second.x + 75, character.second.y + 50, 100, 100},Vector2{0,0}, 0, WHITE);
            
            DrawText("LEVEL: ", character.second.x + 25, character.second.y + 130, 15, WHITE);
            DrawText(TextFormat("%i",character.first.level),character.second.x + 175,character.second.y + 130, 15, WHITE);
            DrawText("VITALITY: ", character.second.x + 25, character.second.y + 150, 15, WHITE);
            DrawText(TextFormat("%i",character.first.attribute.vitality),character.second.x + 175,character.second.y + 150, 15, WHITE);
            DrawText("STRENGTH: ", character.second.x + 25, character.second.y + 170, 15, WHITE);
            DrawText(TextFormat("%i",character.first.attribute.strength),character.second.x + 175,character.second.y + 170, 15, WHITE);
            DrawText("ENDURANCE: ", character.second.x + 25, character.second.y + 190, 15, WHITE);
            DrawText(TextFormat("%i",character.first.attribute.endurance),character.second.x + 175,character.second.y + 190, 15, WHITE);
            DrawText("DEXTERITY: ", character.second.x + 25, character.second.y + 210, 15, WHITE);
            DrawText(TextFormat("%i",character.first.attribute.dexterity),character.second.x + 175,character.second.y + 210, 15, WHITE);
            DrawText("RESISTANCE: ", character.second.x + 25, character.second.y + 230, 15, WHITE);
            DrawText(TextFormat("%i",character.first.attribute.resistance),character.second.x + 175,character.second.y + 230, 15, WHITE);
            DrawText("INTELLIGENCE: ", character.second.x + 25, character.second.y + 250, 15, WHITE);
            DrawText(TextFormat("%i",character.first.attribute.intelligence),character.second.x + 175,character.second.y + 250, 15, WHITE);

            DrawText("Skills", character.second.x + 100, character.second.y + 275, 20, WHITE);
            DrawText(character.first.skills[0].name.c_str(), character.second.x + 10, character.second.y + 300, 20, WHITE);
            DrawText(character.first.skills[1].name.c_str(), character.second.x + 130, character.second.y + 300, 20, WHITE);
            DrawText(character.first.skills[2].name.c_str(), character.second.x + 10, character.second.y + 350, 20, WHITE);
            DrawText(character.first.skills[3].name.c_str(), character.second.x + 130, character.second.y + 350, 20, WHITE);
        }
        ChangeFrames();

        for(auto& rec : selectList)
        {
            DrawRectangleLinesEx(rec,2, WHITE);
            DrawText("SELECT", rec.x + 50, rec.y + 25, 30, WHITE);
        }
    }
    
}

void MainMenu::ExitGame(bool& exitGame)
{
    if(!newGame)
    {
        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            int mouseX = GetMouseX();
            int mouseY = GetMouseY();
            if(mouseX >= GetScreenWidth()/2 - 100 && mouseX <= GetScreenWidth()/2 - 100 + 200
            && mouseY >= GetScreenHeight()/2 + 150 && mouseY <= GetScreenHeight()/2 + 150 + 100)
            {
                exitGame = true;
            }
        }
    }
}

void MainMenu::SelectNewGame()
{
    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
    {
        int mouseX = GetMouseX();
        int mouseY = GetMouseY();
        if(mouseX >= GetScreenWidth()/2 - 100 && mouseX <= GetScreenWidth()/2 - 100 +200
        && mouseY >= GetScreenHeight()/2 - 150 && mouseY <= GetScreenHeight()/2 - 150 + 100)
        {
            newGame = true;
        }
    }
}

void MainMenu::SelectCharacter(bool& isOnMenu,std::vector<Characters::Character>& team, Player& player)
{
    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
    {
        int mouseX = GetMouseX();
        int mouseY = GetMouseY();
        int i = 0;
        for(auto& rec : selectList)
        {
            if(mouseX >= rec.x && mouseX <= rec.x + rec.width
            && mouseY >= rec.y && mouseY <= rec.y + rec.height)
            {
                selectCharacter = true;
                isOnMenu = false;
                characterType[i].first.icon.source.x = 0;
                team.clear();
                team.push_back(characterType[i].first);
                player.playerImg = characterType[i].first.icon.image;
                player.playerType = characterType[i].first.role;
            }
            i++;
        }
    }
}

void MainMenu::ChangeFrames()
{
    for(auto& character : characterType)
    {
        character.first.icon.frame++;
        if(character.first.icon.frame > 12)
        {
            character.first.icon.frame = 0;
            character.first.icon.source.x += 32;
            if(character.first.icon.source.x >= character.first.icon.image.width)
            {
                character.first.icon.source.x = 0;
            }
        }
    }
}
