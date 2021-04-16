#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <functional>
#include <vector>
#include <memory>
#include <utility>
#include <set>

#include "../include/EnemyAgent.h"
#include "../include/GameModel.h"
#include "../include/GameController.h"
#include "../include/MapGenerator.h"

#define STARTING_ENEMIES_DEFAULT 3

int main() {
	srand((unsigned) time(0));
	const int rows = 10;
	const int cols = 10;
	
	std::unique_ptr<GameModel> gameModelPtr = std::make_unique<GameModel>(rows, cols, easyMapGenerator());
	
	std::vector<EnemyAgent*> enemyAgents;
	// Create the agents
	for (int i=0; i<STARTING_ENEMIES_DEFAULT; i++) {
		enemyAgents.push_back(new EnemyAgent());
	}	

	GameController gameController(enemyAgents, std::move(gameModelPtr));

	return 0;
}
