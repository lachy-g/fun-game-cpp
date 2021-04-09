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
        GameNode(int val) : val(val) {
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

        int getReward() {
            if (nodeType ==  NodeType::MONEY) {
                return rand() % 100 + 1;
            } else {
                std::cout<<"Warning, get reward specified for GameNode of non type money";
                return -1;
            }
        }

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