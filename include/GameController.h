#include "EnemyAgent.h"
#include "GameModel.h"
#include <memory>
#include <set>

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

class GameController
{
    private:
        std::vector<EnemyAgent*> enemyAgents;
        std::unique_ptr<GameModel> gameModel;
        int mapRows;
        int mapCols;

        // Our enemy agents are shared across both the controller and model, this will ensure that they are removed from the vector of each of these entities
        void deleteAgent(EnemyAgent* enemyAgent);

    public:
        GameController(std::vector<EnemyAgent*>& enemyAgents, std::unique_ptr<GameModel> gameModel);
        void startGame();
        virtual ~GameController();
        void printAgents();

        bool isPositionPopulated(int, int);
};

#endif