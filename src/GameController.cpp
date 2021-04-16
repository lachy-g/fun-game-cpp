#include "..\include\GameController.h"
#include <iostream>
#include <stdio.h>
#include <utility>
#include <cmath>


GameController::GameController(std::vector<EnemyAgent*>& enemyAgents, std::unique_ptr<GameModel> gameModel) : gameModel(std::move(gameModel)), enemyAgents(enemyAgents) {
    std::cout<<"Created game controller\n";
    GameController::gameModel->getMapDimensions(mapRows, mapCols);

    std::cout<<"Retrieved rows "<< mapRows << " and cols " << mapCols << " from game model " << "\n";

    // Initialise player positions
    // GameController provides to the players their starting position and then notifies the model of this
    // Enemy players can start at any valid column in top half ( i.e in < rows / 2)
    const std::vector<int> map = GameController::gameModel->getMap();

    // Ensure we handle both odd and even cases for row division to ensure enemy is not in bottow half
    const int rowRemainder = std::floor( mapRows / 2 ) - 1;
    std::cout<<"Spawing enemy players above or in row " << rowRemainder << "\n";

    // TODO ensure spawn positions are valid I.E not lava && ensure they are unique.
    for (auto& enemyAgentPtr : GameController::enemyAgents ) {
        int startingXPos = rand() % mapCols;
        int startingYPos = rand() % rowRemainder;
            
        // TODO check enemy agent is not in that position
        while (!GameController::gameModel->isEnemyPositionValid(startingXPos, startingYPos) && !isPositionPopulated(startingXPos, startingYPos)) {
            startingXPos = rand() % mapCols;
            startingYPos = rand() % rowRemainder;
        }

        std::cout<<"Spawning Enemy player " << enemyAgentPtr->getUniqueId() << "Spawning at x,y = (" << startingXPos << "," << startingYPos << ")\n";
        enemyAgentPtr->updatePosition(startingXPos, startingYPos);
    }

    GameController::gameModel.get()->receiveEnemyAgentsReference(GameController::enemyAgents);

    startGame();

    GameController::gameModel.get()->printMap();

}

GameController::~GameController() {
    for (auto enemyAgent : enemyAgents) {
        delete enemyAgent;
    }
}

void GameController::printAgents() {
    
}

bool GameController::isPositionPopulated(const int xPosToCheck, const int yPosToCheck) {

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
    EnemyAgent* toDelete;
    int i = 0;
    for (auto enemyAgent : enemyAgents) {
        if (i++ == 1) {
            toDelete = enemyAgent;
        }
    }
    deleteAgent(toDelete);
}

void GameController::deleteAgent(EnemyAgent* enemyAgent) {
    // std::set<EnemyAgent*>::iterator it = enemyAgents.find(enemyAgent);
    // if (it != enemyAgents.end()) {
    //     delete *it;
    //     *it = nullptr;
    // }
    for (auto& it : enemyAgents) {
        if (it->getUniqueId() == enemyAgent->getUniqueId()) {
            delete it;
            it = nullptr;
        }
    }
}

