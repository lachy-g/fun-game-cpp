#include "GameNode.h"
#include "Agent.h"

#include <functional> 
#include <vector>
#include <string>
#include <set>

#ifndef GAMEMODEL_H
#define GAMEMODEL_H

struct PlayerPosition
{
    int xPos;
    int yPos;
    AgentType agentType;
};

class GameModel
{
    private:
        const int rows;
        const int cols;
        const int size;
        
        std::vector<int> map;
        std::vector<PlayerPosition> playerPositions;

        std::string rowBounds;
        std::string colBounds; 

        std::set<GameNode> available_game_nodes;

        void setValue(int row, int col, int val);
        int getValue(int row, int col);

    public:
        GameModel(int x, int y, std::function<void(std::vector<int>&, int, int)> generateMap);
        virtual ~GameModel();
        const std::vector<int>& getMap();
        const std::vector<PlayerPosition>& getPlayerPositions();
        void printMap();
};

#endif