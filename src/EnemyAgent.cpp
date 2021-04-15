#include "..\include\EnemyAgent.h"
#include <stdlib.h>
#include <iostream>
#include <utility>

EnemyAgent::EnemyAgent() : defaultMove(RIGHT), uniqueId(rand()) {
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
    if (xPos == UNINITAILISED_POSITION || yPos == UNINITAILISED_POSITION) {
        std::cout<<"Warning, agent has not been initailised, please provide initial position before getting moves\n";
    }

    if (moves.empty()) {
        return defaultMove;
    } else {
        int move = moves.front();
        moves.pop();
        return move;
    }
}

int EnemyAgent::getUniqueId() const {
    return uniqueId;
}

void EnemyAgent::updatePosition(int newXPos, int newYPos) {
    std::cout<<"Updating position of enemy with ID "<< uniqueId << " to (" << newXPos << " , " << newYPos << ")\n";
    xPos = newXPos;
    yPos = newYPos;
}

void EnemyAgent::getCurrentPosition(int& xRef, int& yRef) const {
    xRef = xPos;
    yRef = yPos;
}

void EnemyAgent::generateMoves(int turns) {
    // flush the queue first
    while (!moves.empty()) {
        moves.pop();
    }
    
    // Now generate the moves TODO
}