#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <functional>
#include <vector>
#include <memory>
#include <utility>
#include <set>

#include "EnemyAgent.h"
#include "GameModel.h"
#include "GameController.h"
#include "MapGenerator.h"

#define STARTING_ENEMIES_DEFAULT 3

int main() {
	srand((unsigned) time(0));
	const int rows = 10;
	const int cols = 10;
	
	std::unique_ptr<GameBackend::GameModel> gameModelPtr = std::make_unique<GameBackend::GameModel>(rows, cols, GameBackend::easyMapGenerator());
	
	std::vector<GameBackend::EnemyAgent*> enemyAgents;
	// Create the agents
	for (int i=0; i<STARTING_ENEMIES_DEFAULT; i++) {
		enemyAgents.push_back(new GameBackend::EnemyAgent());
	}	

	GameBackend::GameController gameController(enemyAgents, std::move(gameModelPtr));

	return 0;
}
