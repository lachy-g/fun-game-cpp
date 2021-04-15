#include "GameNode.h"
#include "EnemyAgent.h"

#include <functional> 
#include <vector>
#include <string>
#include <set>
#include <memory>
#include<map>
#include <iostream>

#ifndef GAMEMODEL_H
#define GAMEMODEL_H


/**
 * 2d Game model
 * X axis refers to vertical axis, Y axis refers to horizontal axis.
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

        std::map<int, GameNode> available_game_nodes;

        // Refernece to enemy agents //
        std::vector<std::shared_ptr<EnemyAgent>> enemyAgents;

        void setValue(int row, int col, int val);

        // Used to map a 1D coordinate to its 2D representation
        void map1DTo2D(int oneD, int& xPos, int& YPos);
        
        // Returns the 1D point corresponding to the row, col
        int map2DTo1D(int row, int col);

    public:
        GameModel(int x, int y, std::function<void(std::vector<int>&, int, int)> generateMap);

        // There should only be one game model, we don't want to allow it to be copied
        GameModel(const GameModel& gameModel) = delete;

        virtual ~GameModel();
        const std::vector<int>& getMap();
        void printMap();
        void getMapDimensions(int&, int&);
        
        int getValue(int row, int col);

        // Used by GameController to provide initialised enemy agents
        // Used at the start, or can be used to provide any additional agents created throughout the program life cycle...
        void provideInitialisedAgents(std::vector<std::shared_ptr<EnemyAgent>> enemyAgents);

        // Returns whether enemy can spawn or move to a position i.e is not blocked or lava
        // Does not care if an enemy player is currently there. Game controller will handle these interactions.
        bool isEnemyPositionValid(int xpos, int ypos);
};

#endif