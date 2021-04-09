#include "EnemyAgent.h"
#include <stdlib.h>
#include <iostream>
#include <utility>

EnemyAgent::EnemyAgent(std::shared_ptr<GameModel> gameModel) : defaultMove(RIGHT), uniqueId(rand()), gameModel(std::move(gameModel)){
    std::cout<<"Created an enemy agent with id " << uniqueId << "\n";
    this->agentType = AgentType::ENEMY;
}

EnemyAgent::~EnemyAgent() {

}



AgentType EnemyAgent::getAgentType() {
    return this->agentType;
}

// Game functions

int EnemyAgent::getNextMove() {
    if (moves.empty()) {
        return defaultMove;
    } else {
        int move = moves.front();
        moves.pop();
        return move;
    }
}

int EnemyAgent::getUniqueId() const{
    return uniqueId;
}

void EnemyAgent::updatePosition(int newXPos, int newYPos) {
    xPos = newXPos;
    yPos = newYPos;
}

void EnemyAgent::generateMoves(int turns) {
    // flush the queue first
    while (!moves.empty()) {
        moves.pop();
    }
    
    // Now generate the moves TODO
}