#include "..\include\GameModel.h"

#include <iostream>
#include <exception>
#include <string>
#include <sstream>
#include <cmath>

/**
 * Takes total rows and cols starting from 1
 */
GameModel::GameModel(int rows, int cols, std::function<void(std::vector<int>&, int, int)> generateMap) : rows(rows), cols(cols), size(rows * cols) {
   
    // Generate the game nodes
    for (int i=0; i<AVAILABLE_NODES; i++) {
        GameNode gameNode(i);
        available_game_nodes.insert(std::make_pair(i, gameNode));
    }

    // Set the map to default values
    for (int i=0; i<size; i++) {
        map.push_back(0);
    }

    generateMap(map, GameModel::rows, GameModel::cols);
}

GameModel::~GameModel() {
}

const std::vector<int>& GameModel::getMap() {
    return map;
}

void GameModel::printMap() {
    int line_counter = 0;

    // Temporarily display enemy agents on map for debugging, later will need to improve this..
    std::set<int> enemyAgentsPositions;
    bool enemyAgentsProvided = !enemyAgents.empty();
    if (enemyAgentsProvided) {
        for (auto& enemyAgent : enemyAgents) {
            int x, y;
            enemyAgent.get()->getCurrentPosition(x, y);
            enemyAgentsPositions.insert(map2DTo1D(y, x));
        }
    }

    for (int i=0;i<size; i++) {

        std::map<int, GameNode>::iterator it = available_game_nodes.find(map[i]);

        if (it == available_game_nodes.end()) {
            std::cout<<"ERROR";
        } else {
            std::cout<<it->second.getName();
        }

        if (enemyAgentsPositions.count(i) == 1) {
            std::cout<<"::ENEMY";
        } 

        if (++line_counter == (cols)) {
            std::cout<<"\n";
            line_counter = 0;
        } else {
            std::cout<<"\t";
        }
    }
}

/**
 * Takes row, col at index starting at 0
 */
void GameModel::setValue(int row, int col, int val) {
     map.at(map2DTo1D(row, col)) = val;
}

 /**
 * Takes row, col at index starting at 0
 */       
int GameModel::getValue(int row, int col) {
    return map.at(map2DTo1D(row, col));
}

void GameModel::getMapDimensions(int& r, int& c) {
    r = rows;
    c = cols;
}

void GameModel::provideInitialisedAgents(std::vector<std::shared_ptr<EnemyAgent>> enemyAgents) {
    for (auto enemyAgentPtr : enemyAgents) {
        GameModel::enemyAgents.push_back(std::move(enemyAgentPtr));
    }
}


void GameModel::map1DTo2D(int oneDPos, int& row, int& col) {
    if (oneDPos < cols) {
        row = 0;
        col = oneDPos;
    } else {
        // TODO
        row = std::floor(oneDPos/cols);
        col = oneDPos % cols;
    }
}
        
        
int GameModel::map2DTo1D(int row, int col) {
    return ((row * cols) + col);
}

bool GameModel::isEnemyPositionValid(int xpos, int ypos) {
    const int value = getValue(ypos, xpos);
    std::map<int, GameNode>::iterator it = available_game_nodes.find(value);

    if (it == available_game_nodes.end()) {
        std::cout<<"ERROR, unexepected value at enemy new position ( " << xpos <<  " , " << ypos << ") however node value " << value << " at that position is not supported by avaiable game nodes";
        return false;
    } else {
        const NodeConsequence nodeConsequence = it->second.getConsequence();
        return nodeConsequence == NodeConsequence::CAN_MOVE;
    }
}

