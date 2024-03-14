#pragma once
#include "raylib.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <list>


#define MAP_WIDTH 50
#define MAP_HEIGHT 50
#define TILE_SIZE 32
class Map
{
public:
    struct Node
    {
        bool obstacle = false;
        bool visited = false;
        float globalGoal;
        float localGoal;
        int x;
        int y;
        std::vector<Node*> neighbours;
        Node* parent;
    };

    Node *nodes = nullptr;
    Node *nodeStart = nullptr;
	Node *nodeEnd = nullptr;
    std::vector<Node> nodeWithoutTree;
    std::vector<Vector2> cellWithoutTrees;
    

    int cellSize;
    int cellBorder;
    int map1[MAP_WIDTH][MAP_HEIGHT];
    std::vector<Rectangle> wallTileList;
    Texture2D tree;
    Texture2D grass;
    Texture2D grass1;
    Texture2D dirt;
    Map();
    void UpdateMap();
    void DrawMap();
private:
};