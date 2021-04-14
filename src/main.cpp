#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <functional>
#include <vector>
#include <memory>
#include <utility>

#include "EnemyAgent.h"
#include "GameModel.h"
#include "GameController.h"

std::function<void(std::vector<int>&, int, int)> easyMapGenerator();
std::function<void(std::vector<int>&, int, int)> hardMapGenerator();

int main() {
	srand((unsigned) time(0));
	const int rows = 10;
	const int cols = 10;

	
	std::unique_ptr<GameModel> gameModelPtr = std::make_unique<GameModel>(rows, cols, easyMapGenerator());
	
	std::vector<std::shared_ptr<EnemyAgent>> enemyAgents;
	// Create the agents
	for (int i=0; i<2; i++) {
		enemyAgents.push_back(std::make_shared<EnemyAgent>());
	}	

	GameController gameController(enemyAgents, std::move(gameModelPtr));

	return 0;
}


/**
 * TODO actually write some easy map algorithm
 */
std::function<void(std::vector<int>&, int, int)> easyMapGenerator() {
	return [](std::vector<int>& map, int rows, int cols) -> void { 
		for (int row = 0; row<rows; row++) {
			for (int col=0; col<cols; col++) {

				int val = rand() % (AVAILABLE_NODES - 1);

				if (row == 0) {
					map.at(col) = val;
				} else if (col == 0) {
					map.at(row * cols) = val;
				} else {
					int index = (row * cols) + col;
					map.at(index) = val;
				}
			}
		}
	
	};
}

/**
 * TODO actually write some hard map algorithm
 */
std::function<void(std::vector<int>&, int, int)> hardMapGenerator() {
	return [](std::vector<int>& map, int rows, int cols) -> void { 
		for (int row = 0; row<rows; row++) {
			for (int col=0; col<cols; col++) {

				int val = rand() % (AVAILABLE_NODES - 1);

				if (row == 0) {
					map.at(col) = val;
				} else if (col == 0) {
					map.at(row * cols) = val;
				} else {
					int index = (row * cols) + col;
					map.at(index) = val;
				}
			}
		}
	};
}
