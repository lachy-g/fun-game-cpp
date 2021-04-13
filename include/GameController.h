#include "EnemyAgent.h"
#include "GameModel.h"
#include <vector>
#include <memory>

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

class GameController
{
    private:
        std::vector<EnemyAgent> agents;
        std::unique_ptr<GameModel> gameModel;
        int mapRows;
        int mapCols;

    public:
        GameController(std::vector<EnemyAgent> agents, std::unique_ptr<GameModel> gameModel);
        void startGame();
        virtual ~GameController();
        void printAgents();
};

#endif