#include "EnemyAgent.h"
#include "GameModel.h"
#include <vector>
#include <memory>

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

class GameController
{
    private:
        std::vector<std::shared_ptr<EnemyAgent>> enemyAgents;
        std::unique_ptr<GameModel> gameModel;
        int mapRows;
        int mapCols;

        bool isEnemyPositionValid(int position);

    public:
        GameController(std::vector<std::shared_ptr<EnemyAgent>> enemyAgents, std::unique_ptr<GameModel> gameModel);
        void startGame();
        virtual ~GameController();
        void printAgents();
};

#endif