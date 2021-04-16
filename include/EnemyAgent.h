#include <queue>
#include <memory>

#include "Agent.h"

#ifndef ENEMYAGENT_H
#define ENEMYAGENT_H

#define UNINITAILISED_POSITION -1

namespace GameBackend
{
    /**
     * Defines an agent whose role it is to kill the player
     */
    class EnemyAgent : public Agent
    {
        private:
            // Each agent will have a default move that, if it has no moves planned left will take.
            const int defaultMove;

            // Agents plan their paths, this stores the moves the agent will take
            std::queue<int> moves;

            // Used to identify each agent instance uniquely.
            const int uniqueId;

            // Start position is provided to agent by GameController
            int xPos = UNINITAILISED_POSITION;
            int yPos = UNINITAILISED_POSITION;

        public:
            EnemyAgent();
            virtual ~EnemyAgent();
            AgentType getAgentType();
            int getUniqueId() const;
            
            // Game functions

            /**
             * Agents plan their positions, however whether or not their current position can be updated is determined by the Game Controller.
             * The Game controller takes an agents next desired move and tries to apply it. Otherwise it will apply the default move or otherwise
             * another valid move. It then provides the agent its updated position.
             */
            void updatePosition(int, int);

            int getNextMove();
            
            /**
             * Specifies for an agent to generate its next turns moves
             */ 
            void generateMoves(int turns);

            /**
             * Assigns the supplied references with the agents current position
             */
            void getCurrentPosition(int&, int&) const;

            bool operator< (const EnemyAgent& agentToCompare) const {
                return uniqueId < agentToCompare.uniqueId;
            }

            bool operator== (const EnemyAgent& agentToCompare) const {
                return uniqueId == agentToCompare.uniqueId;
            }
    };
}
#endif