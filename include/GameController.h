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
        std::shared_ptr<GameModel> gameModel;

    public:
        GameController(const std::vector<EnemyAgent>, std::shared_ptr<GameModel> gameModel);
        void startGame();
        virtual ~GameController();
        void printAgents();
};

#endif