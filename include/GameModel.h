#include "GameNode.h"
#include "EnemyAgent.h"

#include <functional> 
#include <vector>
#include <string>
#include <memory>
#include<map>
#include <iostream>

#ifndef GAMEMODEL_H
#define GAMEMODEL_H

namespace GameBackend 
{
    /**
     * Class that defines the games model. Will be used to populate the UI
     * Currently is a 2D Game model
     * X axis refers to horizontal axis from left to right, Y axis refers to the vertical axis from top to bottom.
     * We store the 2D model in a 1D vector and map this to 2D. It is stored as flattened rows
     * top left = (0,0). Bottom right = (rows-1, cols-1)
     * The map the model stores contains integer values which are transformed to the corresponding GameNode they represent
     */ 
    class GameModel
    {
        private:
            const int rows;
            const int cols;
            const int size;
            
            // The map the model stores contains integer values which are transformed to the corresponding GameNode they represents
            std::vector<int> map;

            // Used to map int values to the GameNode they represent
            std::map<int, GameNode> available_game_nodes;

            std::shared_ptr<std::vector<GameBackend::EnemyAgent>> enemyAgents;

            // Not currently impleted
            void updateMapValue(int row, int col, int val);

            // Used to map a 1D coordinate to its 2D representation. Currently not used and is WIP
            void map1DTo2D(int oneD, int& xPos, int& YPos);
            
            // Returns the 1D point corresponding to the row, col
            int map2DTo1D(int row, int col);

        public:
            GameModel(int x, int y, std::function<void(std::vector<int>&, int, int)> generateMap, 
                      std::shared_ptr<std::vector<GameBackend::EnemyAgent>> enemyAgents);

            // There should only be one game model, we don't want to allow it to be copied
            GameModel(const GameModel& gameModel) = delete;

            virtual ~GameModel();
            const std::vector<int>& getMap();
            void printMap();
            void getMapDimensions(int&, int&);
            
            int getValue(int row, int col);
            
            // Returns whether enemy can spawn or move to a position i.e is not blocked or lava
            // Does not care if an enemy player is currently there. Game controller will handle these interactions.
            bool isEnemyPositionValid(int xpos, int ypos);
    };
}

#endif