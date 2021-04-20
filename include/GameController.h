#include "EnemyAgent.h"
#include "GameModel.h"
#include <memory>
#include <set>

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

namespace GameBackend 
{
    /**
     * GameController is the central entity of the game. It handles interaction of agents with the map, and triggers move planning and position updating.
     * It also initialises the agents and supplies a reference of these to the model so it can update the UI
     */
    class GameController
    {
        private:
            std::shared_ptr<std::vector<GameBackend::EnemyAgent>> enemyAgents;
            std::unique_ptr<GameModel> gameModel;

            // Store the map dimensions here for convenience
            int mapRows;
            int mapCols;

            /**
             * Checks whether the desired position already contains an Agent
             */
            bool isEnemyExistAtPosition(int, int);

            /**
             * When an agent dies, it will delete the underlying instance ensuring the model does not display the agent
             */
            void deleteAgent(int uniqueIdOfAgentToDelete);

        public:
            GameController(std::shared_ptr<std::vector<GameBackend::EnemyAgent>> enemyAgents, std::unique_ptr<GameModel> gameModel);

            // Currently we only ever want one game controller
            GameController(const GameController& gameController) = delete;
            
            virtual ~GameController();

            void startGame();
    };
}
#endif