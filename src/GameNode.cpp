#include "../include/GameNode.h"

GameNode::GameNode(int val) : val(val) {
    switch (val) {
        case 0:
            nodeType = NodeType::LAVA;
            nodeConsequence = NodeConsequence::DEATH;
            name = "LAVA";
            break;
        case 1:
            nodeType =  NodeType::GRASS;
            nodeConsequence = NodeConsequence::CAN_MOVE;
            name = "GRASS";
            break;
        case 2:
            nodeType =  NodeType::MONEY;
            nodeConsequence = NodeConsequence::CAN_MOVE;
            name = "MONEY";
            break;
        case 3:
            nodeType = NodeType::BLOCK;
            nodeConsequence = NodeConsequence::BLOCKED;
            name = "BLOCK";
            break;
        default:
            std::cout<<"Illegal argument val "<<val<< " provided\n";
            name = nullptr;
    }

    srand((unsigned) time(0));
}

int GameNode::getReward() {
    if (nodeType ==  NodeType::MONEY) {
        return rand() % 100 + 1;
    } else {
        std::cout<<"Warning, get reward specified for GameNode of non type money";
        return -1;
    }
}