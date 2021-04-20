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
	
	// Create the agents container. Game Controller will update this, GameModel will use this to update the UI

	std::shared_ptr<std::vector<GameBackend::EnemyAgent>> enemyAgents = std::make_shared<std::vector<GameBackend::EnemyAgent>>();
	for (int i=0; i<STARTING_ENEMIES_DEFAULT; i++) {
		GameBackend::EnemyAgent agent;
		enemyAgents.get()->push_back(agent);
	}	

	// Provide the agents to the controller and the model
	std::unique_ptr<GameBackend::GameModel> gameModelPtr = std::make_unique<GameBackend::GameModel>(rows, cols, GameBackend::easyMapGenerator(), enemyAgents);

	GameBackend::GameController gameController(enemyAgents, std::move(gameModelPtr));

	return 0;
}
