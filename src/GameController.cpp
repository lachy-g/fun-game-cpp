#include "GameController.h"
#include <iostream>
#include <stdio.h>
#include <utility>
#include <cmath>

namespace GameBackend
{
    GameController::GameController(std::vector<EnemyAgent*>& enemyAgents, std::unique_ptr<GameModel> gameModel) : gameModel(std::move(gameModel)), enemyAgents(enemyAgents) {
        GameController::gameModel->getMapDimensions(mapRows, mapCols);

        std::cout<<"Retrieved rows "<< mapRows << " and cols " << mapCols << " from game model " << "\n";

        // Spawn enemy agents i.e initialise their starting position and provide a referece of the agents to the model
        // Enemy players can start at any valid node in the top half of the map (in < rows / 2)
        const std::vector<int> map = GameController::gameModel->getMap();
        const int rowRemainder = std::floor( mapRows / 2 ) - 1;
        for (auto& enemyAgentPtr : GameController::enemyAgents ) {
            int startingXPos = rand() % mapCols;
            int startingYPos = rand() % rowRemainder;
                
            while (!GameController::gameModel->isEnemyPositionValid(startingXPos, startingYPos) && !isEnemyExistAtPosition(startingXPos, startingYPos)) {
                startingXPos = rand() % mapCols;
                startingYPos = rand() % rowRemainder;
            }

            std::cout<<"Spawning enemy agent " << enemyAgentPtr->getUniqueId() << " at x,y coordinates (" << startingXPos << "," << startingYPos << ")\n";
            enemyAgentPtr->updatePosition(startingXPos, startingYPos);
        }
        GameController::gameModel.get()->receiveEnemyAgentsReference(GameController::enemyAgents);

        // For debugging
        GameController::gameModel.get()->printMap();
    }

    GameController::~GameController() {
        for (auto enemyAgent : enemyAgents) {
            delete enemyAgent;
        }
    }

    bool GameController::isEnemyExistAtPosition(const int xPosToCheck, const int yPosToCheck) {
        int agent_x_pos, agent_y_pos;
        for (auto& it : enemyAgents) {
            it->getCurrentPosition(agent_x_pos, agent_y_pos);
            if (agent_x_pos == xPosToCheck && agent_y_pos == yPosToCheck) {
                return true;
            }
        }
        return false;
    }

    void GameController::startGame() {
        
    }

    void GameController::deleteAgent(EnemyAgent* enemyAgent) {
        for (auto& it : enemyAgents) {
            if (it->getUniqueId() == enemyAgent->getUniqueId()) {
                delete it;
                it = nullptr;
            }
        }
    }
}