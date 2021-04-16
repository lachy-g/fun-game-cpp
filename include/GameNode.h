#include<cstdlib>
#include <string>
#include <ctime>
#include <iostream>

#ifndef GAMENODE_H
#define GAMENODE_H

#define AVAILABLE_NODES 4

namespace GameBackend {
    /**
     * Defines the type of node
     * Each NodeType has a different consquence with respect to an agent moving to it / attempting to move to it
     * Also each will be displayed differently to the User.
     * Note that the ordering of these must be preserved
     */
    enum class NodeType {
        LAVA, GRASS, MONEY, STONE
    };

    /**
     * Defines the consequences of moving into a node 
     * Will be intepreted by the game controller
     */
    enum class NodeConsequence {
        CAN_MOVE, DEATH, BLOCKED
    };

    /**
     * Class used for consolidationg a NodeType with a consequence.
     */
    class GameNode 
    {
        NodeType nodeType;
        NodeConsequence nodeConsequence;
        std::string name;
        int nodeTypeEnumOrdinal;

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
                return nodeTypeEnumOrdinal < toCompare.nodeTypeEnumOrdinal;
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
}

#endif