#include "..\include\GameModel.h"

#include <iostream>
#include <exception>
#include <string>
#include <sstream>

/**
 * Takes total rows and cols starting from 1
 */
GameModel::GameModel(int x, int y, std::function<void(std::vector<int>&, int, int)> generateMap) : rows(x), cols(y), size(rows * cols) {
    std::stringstream errorGenerationStream;
    errorGenerationStream << "Row bounds between 0 and " << rows;
    rowBounds = errorGenerationStream.str();
    errorGenerationStream.str(std::string());

    errorGenerationStream << "Col bounds between 0 and " << cols;
    colBounds = errorGenerationStream.str();

    // Generate the game nodes
    for (int i=0; i<AVAILABLE_NODES; i++) {
        GameNode gameNode(i);
        available_game_nodes.insert(gameNode);
    }

    // Set the map to default values
    for (int i=0; i<size; i++) {
        map.push_back(0);
    }

    generateMap(map, rows, cols);
}

GameModel::~GameModel() {
}

const std::vector<int>& GameModel::getMap() {
    return map;
}

const std::vector<PlayerPosition>& GameModel::getPlayerPositions() {
    return playerPositions;
}


void GameModel::printMap() {
    using std::cout;

    int line_counter = 0;
    for (int i=0;i<size; i++) {
        int val = map[i];

        std::set<GameNode>::iterator it = available_game_nodes.find(GameNode(val));

        if (it == available_game_nodes.end()) {
            std::cout<<"ERROR";
        } else {
            std::cout<< (*it).getName() << " : " << GameNode::mapConsequenceToString((*it).getConsequence());
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
     if (row == 0) {
         map.at(col) = val;
     } else if (col == 0) {
         map.at(row * cols) = val;
     } else {
         int index = (row * cols) + col;
         map.at(index) = val;
     }
 }

 /**
 * Takes row, col at index starting at 0
 */       
int GameModel::getValue(int row, int col) {
    if (row == 0) {
        return map.at(row);
     } else if (col == 0) {
        return map.at(row * cols);
     } else {
         return map.at((row * cols) + col);
     }
}

void GameModel::getMapDimensions(int& r, int& c) {
    r = rows;
    c = cols
}
