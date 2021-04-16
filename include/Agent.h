#ifndef AGENT_H
#define AGENT_H

#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3

namespace GameBackend
{
    enum class AgentType
    {
        ENEMY,
        FRIEND,
        PLAYER
    };

    /**
     * Base class for agents. Agents are entities that plan their actions independently, or are triggered through user input.
     * The GameCotroller will facilitate this planning and receive their planned moves for which the model will use to update its UI view with.
     */
    class Agent 
    {
        protected:
            AgentType agentType;

        public:
            Agent() {
            }
            
            virtual ~Agent() {

            }

            /**
             * Move scheme defined by 0 = left, 1 = up, 2 = right, 3 = down
             */
            virtual int getNextMove() = 0;

            virtual AgentType getAgentType() = 0;
    };
}
#endif