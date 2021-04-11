#include "..\include\GameController.h"
#include <iostream>
#include <stdio.h>
#include <utility>
#include <cmath>


GameController::GameController(const std::vector<EnemyAgent> ag, std::shared_ptr<GameModel> gM) : agents(ag), gameModel(gM) {
    std::cout<<"Created game controller\n";
    gameModel->getMapDimensions(mapRows, mapCols);

    std::cout<<"Retrieved rows "<< mapRows << " and cols " << mapCols << " from game model " << "\n";
    // Initialise player positions
    // GameController provides to the players their starting position and then notifies the model of this
    // Enemy players can start at any valid column in top half ( i.e in < rows / 2)
    const std::vector<int> map = gameModel->getMap();

    // Ensure we handle both odd and even cases for row division to ensure enemy is not in bottow half
    const int rowRemainder = std::floor( mapRows / 2 ) - 1;
    std::cout<<"Spawing enemy players above or in row " << rowRemainder << "\n";

    for (std::vector<EnemyAgent>::const_iterator enemyAgent = agents.begin(); enemyAgent != agents.end(); enemyAgent++ ) {
        int startingXPos = rand() % rowRemainder;
        int startingYPos = rand() % mapCols;
        std::cout<<"Spawning Enemy player " << enemyAgent->getUniqueId() << "Spawning at (" << startingXPos << "," << startingYPos << ")\n";
    }
}

GameController::~GameController() {

}

void GameController::printAgents() {
    
}