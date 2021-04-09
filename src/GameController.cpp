#include "GameController.h"
#include <iostream>
#include "utility"


GameController::GameController(const std::vector<EnemyAgent> agents, std::shared_ptr<GameModel> gameModel) : agents(agents) , gameModel(std::move(gameModel)) {

}

GameController::~GameController() {

}

void GameController::printAgents() {
    
}