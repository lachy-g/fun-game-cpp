#include <queue>
#include <memory>

#include "Agent.h"
#include "GameModel.h"

#ifndef ENEMYAGENT_H
#define ENEMYAGENT_H

class EnemyAgent : public Agent
{
    private:
        const int defaultMove;
        std::queue<int> moves;
        const int uniqueId;
        std::shared_ptr<GameModel> gameModel;

        int xPos;
        int yPos;

    public:
        EnemyAgent(std::shared_ptr<GameModel>);
        virtual ~EnemyAgent();
        AgentType getAgentType();
        int getUniqueId() const;
        
        // Game functions
        void updatePosition(int, int);
        int getNextMove();
        void generateMoves(int);
};

#endif