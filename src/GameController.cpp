#include "GameController.h"
#include <iostream>
#include <stdio.h>
#include <utility>
#include <cmath>


GameController::GameController(std::vector<std::shared_ptr<EnemyAgent>> enemyAgents, std::unique_ptr<GameModel> gameModel) : gameModel(std::move(gameModel)) {
    std::cout<<"Created game controller\n";
    GameController::gameModel->getMapDimensions(mapRows, mapCols);

    // Copy across shared pointers to enemyAgents
    for (auto enemyAgentPtr : enemyAgents) {
        GameController::enemyAgents.push_back(std::move(enemyAgentPtr));
    }

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
        std::cout<<"Spawning Enemy player " << enemyAgentPtr.get()->getUniqueId() << "Spawning at x,y = (" << startingXPos << "," << startingYPos << ")\n";
        enemyAgentPtr.get()->updatePosition(startingXPos, startingYPos);
    }

    GameController::gameModel.get()->provideInitialisedAgents(GameController::enemyAgents);

    GameController::gameModel.get()->printMap();

}

GameController::~GameController() {

}

void GameController::printAgents() {
    
}

bool GameController::isEnemyPositionValid(int position) {
    return true;
}
