#include "Arena.h"

Arena::Arena()
{
    int arena[7][19] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,2,0,0,0,0,0,3,0,0,0,0,0,1},
    {1,0,0,0,0,2,0,2,0,0,0,3,0,3,0,0,0,0,1},
    {1,0,0,0,0,0,2,0,0,0,0,0,3,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

    };
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 19; j++) {
            arena1[i][j] = arena[i][j];
            if((arena1[i][j] == 2))
            {
                teamPos.push_back({(float)j * TILE_SIZE* 2, (float)i * TILE_SIZE* 2});
            }
            else if((arena1[i][j] == 3))
            {
                monsterPos.push_back({(float)j * TILE_SIZE* 2, (float)i * TILE_SIZE* 2});
            }
        }
    }
    tree = LoadTexture("sprites/Simple-Forest/Tree.png");
    grass = LoadTexture("sprites/Simple-Forest/Grass1.png");
    dirt = LoadTexture("sprites/Simple-Forest/Dirt.png");

    Rectangle rec1 = {0,448, (float)GetScreenWidth()/2,536 - 448};
    Rectangle rec2 = {0,536, (float)GetScreenWidth()/2,624 - 536};
    Rectangle rec3 = {0,624, (float)GetScreenWidth()/2,712 - 624};
    Rectangle rec4 = {0,712, (float)GetScreenWidth()/2,(float)GetScreenHeight()};
    characterRec.push_back(rec1);
    characterRec.push_back(rec2);
    characterRec.push_back(rec3);
    characterRec.push_back(rec4);

    characterSelected = false;
    characterIndex = 0;
    round = 0;
    frame = 0;

    Rectangle skillrec1 = {(float)GetScreenWidth() / 2 + 10, 448, (float)GetScreenWidth()/2, 536 - 448};
    Rectangle skillrec2 = {(float)GetScreenWidth() / 2 + 10, 536, (float)GetScreenWidth()/2, 624 - 536};
    Rectangle skillrec3 = {(float)GetScreenWidth() / 2 + 10, 624, (float)GetScreenWidth()/2, 712 - 624};
    Rectangle skillrec4 = {(float)GetScreenWidth() / 2 + 10, 712, (float)GetScreenWidth()/2, (float)GetScreenHeight()};
    skillRec.push_back(skillrec1);
    skillRec.push_back(skillrec2);
    skillRec.push_back(skillrec3);
    skillRec.push_back(skillrec4);

    usedAttack = false;
    selectedMonsterIndex = 0;

    roundBtn = {(float)GetScreenWidth() / 2 - 75, 350, 150, 75};
    numMonsAttack = 0;
}

void Arena::RestartArena()
{
    characterSelected = false;
    characterIndex = 0;
    round = 0;
    frame = 0;
    usedAttack = false;
    selectedMonsterIndex = 0;
    numMonsAttack = 0;
    teamInfo.clear();
    monsterInfo.clear();
}

void Arena::SelectMonster()
{
    int mouseX = GetMouseX();
    int mouseY = GetMouseY();

    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
    {
        int index = 0;
        for(auto monsterPos : monsterInfo)
        {
            if(mouseX >= monsterPos.second.x && mouseX <= monsterPos.second.x + 50 
            && mouseY >= monsterPos.second.y && mouseY <= monsterPos.second.y + 50)
            {
                selectedMonsterIndex = index;
            }
            index++;
        }
    }
}

void Arena::GetMonster(Monsters::Monster& monster)
{
    int amountMonsters = (rand() % 3) + 1;
    for(int i = 0; i < amountMonsters; i++)
    {
        monsterInfo.push_back(std::make_pair(monster,monsterPos[i]));
    }
    monsterId = monster;
}

void Arena::GetTeam(std::vector<Characters::Character>& teams)
{
    int i = 0;
    for(auto& character : teams)
    {
        teamInfo.push_back(std::make_pair(character,teamPos[i++]));
    }
}

void Arena::ArenaUpdate(std::vector<Monsters::Monster>& monsterList,bool& figthStarted,bool& arenaStarted, Player &player)
{
    SelectMonster();
    SelectCharacter();

    if(round % 2 == 0)
    {
        SelectSkill();
        EndRound();
    }
    else 
    {
        MonsterSkill();
    }
    if(ArenaSkillCheck.IsAllMonsterDead(monsterInfo))
    {
        ArenaSkillCheck.WinArena(monsterList, monsterId);
        RestartArena();
        figthStarted = false;
        arenaStarted = false;
    }
    else if(ArenaSkillCheck.IsAllTeamDead(teamInfo))
    {
        ArenaSkillCheck.LoseArena(player);
        RestartArena();
        figthStarted = false;
        arenaStarted = false;
    }
    if(ArenaSkillCheck.IsMonsterDead(monsterInfo))
    {
        selectedMonsterIndex = 0;
    }
    ArenaSkillCheck.IsTeammatesDead(teamInfo);

}



void Arena::ArenaDraw()
{
    for (int y = 0; y < 7; y++) {
        for (int x = 0; x < 19; x++) {
            DrawTextureEx(grass,Vector2{(float)x * TILE_SIZE * 2, (float)y * TILE_SIZE* 2},0, 4, WHITE);
            if((arena1[y][x] == 1))
            {
                DrawTextureEx(tree,Vector2{(float)x * TILE_SIZE* 2, (float)y * TILE_SIZE* 2},0, 4, WHITE);
            }
            if((arena1[y][x] == 2) || (arena1[y][x] == 3))
            {
                DrawTextureEx(dirt,Vector2{(float)x * TILE_SIZE* 2, (float)y * TILE_SIZE* 2},0, 4, WHITE);
            }
        }
    }
    DrawRectangle(0,448,GetScreenWidth(), GetScreenHeight() - 448, BLACK);
    DrawLineBezier(Vector2{0,448},Vector2{(float)GetScreenWidth(),448},10,WHITE);
    DrawLineBezier(Vector2{(float)GetScreenWidth()/2, 448},Vector2{(float)GetScreenWidth()/2,(float)GetScreenHeight()}, 10, WHITE);

    DrawLine(0, 536,GetScreenWidth(), 536, WHITE);
    DrawLine(0, 624,GetScreenWidth(), 624, WHITE);
    DrawLine(0, 712,GetScreenWidth(), 712, WHITE);

    //Anims
    for(int i = 0; i < teamInfo.size(); i++)
    {
        ArenaSkillCheck.CharacterAnim(teamInfo[i].first);
    }
    for(int i = 0; i < monsterInfo.size(); i++)
    {
        ArenaSkillCheck.MonsterAnim(numMonsAttack,monsterInfo[i].first,teamInfo);
    }

    TeamDraw();
    MonsterDraw();
    CharacterSkillsDraw();
    //Round Btn
    DrawRectangleRec(roundBtn,WHITE);
    DrawText("End Round", roundBtn.x + 25, roundBtn.y + 25, 20, BLACK);

    if(round % 2 == 0)
    {
        DrawText("Player Round", GetScreenWidth()/2 - 75, 100, 25, WHITE);
    }
    else 
    {
        DrawText("Monster Round", GetScreenWidth()/2 - 75, 100, 25, WHITE);
    }
    
    
    
}

void Arena::TeamDraw()
{   
    DrawRectangle(characterRec[characterIndex].x,characterRec[characterIndex].y,characterRec[characterIndex].width,characterRec[characterIndex].height, Color{200, 200, 200, 50});
    int i = 0;
    for(auto& character : teamInfo)
    {   
        //Icon
        DrawTexturePro(character.first.icon,character.first.source,Rectangle{characterRec[i].x + 50,characterRec[i].y + 12,75,75},{0,0},0,WHITE);
        //Character In fight
        DrawTexturePro(character.first.anims[character.first.animIndex].image,character.first.anims[character.first.animIndex].source,
        Rectangle{character.second.x - 16,character.second.y - 16,100,100},{0,0},0,WHITE);
        //HP
        DrawRectangle(characterRec[i].x + 120,characterRec[i].y + 12,character.first.HPLeft, 15, RED);
        DrawRectangleLines(characterRec[i].x + 120,characterRec[i].y + 12,character.first.HP, 15, WHITE);
        //Stamina
        DrawRectangle(characterRec[i].x + 120,characterRec[i].y + 32,character.first.staminaLeft, 15, GREEN);
        DrawRectangleLines(characterRec[i].x + 120,characterRec[i].y + 32,character.first.stamina, 15, WHITE); 
        //Mana
        DrawRectangle(characterRec[i].x + 120,characterRec[i].y + 50,character.first.manaLeft, 15, SKYBLUE);
        DrawRectangleLines(characterRec[i].x + 120,characterRec[i].y + 50,character.first.mana, 15, WHITE);  
        //Shield
        DrawText(TextFormat("%i", character.first.shieldLeft), characterRec[i].x + 400, characterRec[i].y + 40, 30, GRAY);
        i++;
    }
    
    
}

void Arena::MonsterDraw()
{
    for(auto& monster : monsterInfo)
    {
        //Monster Img
        DrawTexturePro(monster.first.anims[monster.first.animIndex].image,monster.first.anims[monster.first.animIndex].source,
        Rectangle{monster.second.x - 16,monster.second.y - 16,100,100},{0,0},0,WHITE);
        //Monster HP
        int HPLeft = (monster.first.healthLeft * 100) / monster.first.health;
        DrawRectangle(monster.second.x - 25,monster.second.y + 100 - 25,100, 15, BLACK);
        DrawRectangle(monster.second.x - 25,monster.second.y + 100 - 25,HPLeft, 15, RED);
        //Monster Shield
        int ShieldLeft = (monster.first.shieldLeft * 100) / monster.first.shield;
        DrawRectangle(monster.second.x - 25,monster.second.y + 110 - 25,100, 10, BLACK);
        DrawRectangle(monster.second.x - 25,monster.second.y + 110 - 25,ShieldLeft, 10, LIGHTGRAY);
    }
}

void Arena::SelectCharacter()
{
    int mouseX = GetMouseX();
    int mouseY = GetMouseY();
    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        int i = 0;
        for(auto rec : characterRec)
        {
            if((mouseX >= rec.x && mouseX <= rec.x + rec.width && mouseY >= rec.y && mouseY <= rec.y + rec.height) && i < teamInfo.size())
            {
                characterSelected = true;
                characterIndex = i;
            }
            i++;
        }
    }
}

void Arena::CharacterSkillsDraw()
{
    if(!teamInfo.empty())
    {
        if(characterSelected)
        {
            DrawText(teamInfo[characterIndex].first.skills[0].name.c_str(),GetScreenWidth() / 2 + 100, 480, 30, WHITE);
            DrawText(teamInfo[characterIndex].first.skills[1].name.c_str(),GetScreenWidth() / 2 + 100, 575, 30, WHITE);
            DrawText(teamInfo[characterIndex].first.skills[2].name.c_str(),GetScreenWidth() / 2 + 100, 650, 30, WHITE);
            DrawText(teamInfo[characterIndex].first.skills[3].name.c_str(),GetScreenWidth() / 2 + 100, 750, 30, WHITE);

            //Skill Stats
        }
    }

}

void Arena::EndRound()
{
    int mouseX = GetMouseX();
    int mouseY = GetMouseY();
    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
    {
        if(mouseX >= GetScreenWidth() / 2 - 75 && mouseX <= GetScreenWidth() / 2 - 75 + 150 
        && mouseY >= 350 && mouseY <= 350 + 75)
        {
            round++;
        }
    }
}

void Arena::MonsterSkill()
{
    if(numMonsAttack == 0)
    {
        if(numMonsAttack < monsterInfo.size())
        {
            monsterInfo[numMonsAttack].first.animIndex = 1;
        }
    }
    if(numMonsAttack == 1)
    {
        if(numMonsAttack < monsterInfo.size())
        {
            monsterInfo[numMonsAttack].first.animIndex = 1;
        }
    }
    if(numMonsAttack == 2)
    {
        if(numMonsAttack < monsterInfo.size())
        {
            monsterInfo[numMonsAttack].first.animIndex = 1;
        }
    }
    if(numMonsAttack == 3)
    {
        if(numMonsAttack < monsterInfo.size())
        {
            monsterInfo[numMonsAttack].first.animIndex = 1;
        }
    }
    if(numMonsAttack == monsterInfo.size())
    {
        numMonsAttack = 0;
        round++;
        ArenaSkillCheck.RestStaminaMana(teamInfo);
    }
}
void Arena::SelectSkill()
{
    if(characterSelected)
    {
        int mouseX = GetMouseX();
        int mouseY = GetMouseY();
        if(usedAttack)
        {
            frame++;
            if(frame > 12)
            {
                usedAttack = false;
                frame = 0;
            }
        }
        if(!usedAttack)
        {
            if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                int i = 0;
                for(auto rec : skillRec)
                {
                    if(mouseX >= rec.x && mouseX <= rec.x + rec.width && mouseY >= rec.y && mouseY <= rec.y + rec.height)
                    {
                        CharacterSkill(i);
                    }
                    i++;
                }
            }
        }
    }
}

void Arena::CharacterSkill(int skillIndex)
{
    if(ArenaSkillCheck.CheckManaLeft(teamInfo[characterIndex].first.skills[skillIndex], teamInfo[characterIndex].first.manaLeft)
    && ArenaSkillCheck.CheckStaminaLeft(teamInfo[characterIndex].first.skills[skillIndex], teamInfo[characterIndex].first.staminaLeft))
    {
        if(teamInfo[characterIndex].first.skills[skillIndex].type == "Single Attack" || teamInfo[characterIndex].first.skills[skillIndex].type == "Multi Attack" )
        {
            ArenaSkillCheck.AttackSkill(teamInfo[characterIndex].first,skillIndex,monsterInfo[selectedMonsterIndex].first, monsterInfo);
        }
        if(teamInfo[characterIndex].first.skills[skillIndex].type == "Buff")
        {
            ArenaSkillCheck.BuffSkill(teamInfo, skillIndex, characterIndex);
        }
        usedAttack = true;
    }

}
                

