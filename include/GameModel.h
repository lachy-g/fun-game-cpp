#include "GameNode.h"
#include "Agent.h"

#include <functional> 
#include <vector>
#include <string>
#include <set>
#include <memory>

#include <iostream>

#ifndef GAMEMODEL_H
#define GAMEMODEL_H

struct PlayerPosition
{
    int xPos;
    int yPos;
    AgentType agentType;
};

/**
 * 2d Game model
 * top left = (0,0). Bottom right = (rows-1, cols-1)
 * stored in a 1d vector for performance, mapping to 2d done by set and getvalue
 */ 
class GameModel
{
    private:
        const int rows;
        const int cols;
        const int size;
        
        std::vector<int> map;
        std::shared_ptr<std::vector<PlayerPosition>> playerPositions;

        std::string rowBounds;
        std::string colBounds; 

        std::set<GameNode> available_game_nodes;

        void setValue(int row, int col, int val);
        int getValue(int row, int col);

    public:
        GameModel(int x, int y, std::function<void(std::vector<int>&, int, int)> generateMap);

        // There should only be one game model, we don't want to allow it to be copied
        GameModel(const GameModel& gameModel) = delete;

        virtual ~GameModel();
        const std::vector<int>& getMap();
        std::vector<PlayerPosition>& getPlayerPositions();
        void printMap();
        void getMapDimensions(int&, int&);
};

#endif