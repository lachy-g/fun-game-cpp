#include "GameController.h"
#include <iostream>
#include <stdio.h>
#include <utility>
#include <cmath>
#include <algorithm>

namespace GameBackend
{
    GameController::GameController(std::shared_ptr<std::vector<GameBackend::EnemyAgent>> enemyAgents, std::unique_ptr<GameModel> gameModel) : 
                                    gameModel(std::move(gameModel)), enemyAgents(std::move(enemyAgents)) {
        GameController::gameModel->getMapDimensions(mapRows, mapCols);

        std::cout<<"Retrieved rows "<< mapRows << " and cols " << mapCols << " from game model " << "\n";

        // Spawn enemy agents i.e initialise their starting position and provide a referece of the agents to the model
        // Enemy players can start at any valid node in the top half of the map (in < rows / 2)
        const std::vector<int> map = GameController::gameModel->getMap();
        const int rowRemainder = std::floor( mapRows / 2 ) - 1;

        for (auto& it : *GameController::enemyAgents.get()) {
            int startingXPos = rand() % mapCols;
            int startingYPos = rand() % rowRemainder;
                
            while (!GameController::gameModel->isEnemyPositionValid(startingXPos, startingYPos) && !isEnemyExistAtPosition(startingXPos, startingYPos)) {
                startingXPos = rand() % mapCols;
                startingYPos = rand() % rowRemainder;
            }

            std::cout<<"Spawning enemy agent " << it.getUniqueId() << " at x,y coordinates (" << startingXPos << "," << startingYPos << ")\n";
            it.updatePosition(startingXPos, startingYPos);        
        }

        // GameController::gameModel.get()->receiveEnemyAgentsReference(GameController::enemyAgents);

        deleteAgent(GameController::enemyAgents.get()->at(0).getUniqueId());

        // For debugging
        GameController::gameModel.get()->printMap();
    }

    GameController::~GameController() {
    }

    bool GameController::isEnemyExistAtPosition(const int xPosToCheck, const int yPosToCheck) {
        int agent_x_pos, agent_y_pos;
        for (auto& it : *enemyAgents.get()) {
            it.getCurrentPosition(agent_x_pos, agent_y_pos);
            if (agent_x_pos == xPosToCheck && agent_y_pos == yPosToCheck) {
                return true;
            }
        }
        return false;
    }

    void GameController::startGame() {
        
    }

    void GameController::deleteAgent(const int uniqueIdToDelete) {
        enemyAgents.get()->erase(std::remove_if(enemyAgents.get()->begin(), enemyAgents.get()->end(), 
                                [uniqueIdToDelete] (EnemyAgent& enemyAgent) -> bool { return enemyAgent.getUniqueId() == uniqueIdToDelete; }),
                                enemyAgents.get()->end());
    }
}