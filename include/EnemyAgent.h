#include <queue>
#include <memory>

#include "Agent.h"

#ifndef ENEMYAGENT_H
#define ENEMYAGENT_H

#define UNINITAILISED_POSITION -1

class EnemyAgent : public Agent
{
    private:
        const int defaultMove;
        std::queue<int> moves;
        const int uniqueId;

        // Start position is provided to agent
        int xPos = UNINITAILISED_POSITION;
        int yPos = UNINITAILISED_POSITION;

    public:
        EnemyAgent();
        virtual ~EnemyAgent();
        AgentType getAgentType();
        int getUniqueId() const;
        
        // Game functions
        void updatePosition(int, int);
        int getNextMove();
        void generateMoves(int);

        /**
         * Returns the current position this agent is in
         */
        void getCurrentPosition(int&, int&);
};

#endif