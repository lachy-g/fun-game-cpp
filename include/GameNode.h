#include<cstdlib>
#include <string>
#include <ctime>
#include <iostream>

#ifndef GAMENODE_H
#define GAMENODE_H

#define AVAILABLE_NODES 4

/**
 * Defines the type of node
 */
enum class NodeType {
            LAVA = 0, 
            GRASS = 1, 
            MONEY = 2,
            BLOCK = 3
};

/**
 * Defines the consequences of moving into a node 
 * Will be intepreted by the game controller
 */
enum class NodeConsequence {
    CAN_MOVE, DEATH, BLOCKED
};

/**
 * TODO break this into a parent with child classes
 */
class GameNode 
{
    NodeType nodeType;
    NodeConsequence nodeConsequence;
    std::string name;
    int val;

    public:
        GameNode(int val);

        int getReward();

        NodeConsequence getConsequence() const {
            return nodeConsequence;
        }
        
        int getValue() const {
            return (int)nodeType;
        }

        NodeType getType() const {
            return nodeType;
        }

        std::string getName() const {
            return name;
        }

        bool operator< (const GameNode &toCompare) const {
            return val < toCompare.val;
        }

        static std::string mapConsequenceToString(const NodeConsequence& nodeConsequence) {
            std::string consequence;
            switch (nodeConsequence) {
                case NodeConsequence::BLOCKED:
                    consequence = "BLOCKED";
                    break;
                case NodeConsequence::DEATH:
                    consequence = "DEATH";
                    break;
                case NodeConsequence::CAN_MOVE:
                    consequence = "CAN_MOVE";
                    break;
            }
            return consequence;
        }
};

#endif