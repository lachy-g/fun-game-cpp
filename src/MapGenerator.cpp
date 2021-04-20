#include "MapGenerator.h"
#include "GameNode.h"

namespace GameBackend
{
    /**
     * TODO actually write some easy map algorithm
     */
    std::function<void(std::vector<int>&, int, int)> easyMapGenerator() {
        return [](std::vector<int>& map, int rows, int cols) -> void { 
            for (int row = 0; row<rows; row++) {
                for (int col=0; col<cols; col++) {

                    int val = rand() % (AVAILABLE_NODES);

                    if (row == 0) {
                        map.at(col) = val;
                    } else if (col == 0) {
                        map.at(row * cols) = val;
                    } else {
                        int index = (row * cols) + col;
                        map.at(index) = val;
                    }
                }
            }
        
        };
    }

    /**
     * TODO actually write some hard map algorithm
     */
    std::function<void(std::vector<int>&, int, int)> hardMapGenerator() {
        return [](std::vector<int>& map, int rows, int cols) -> void { 
            for (int row = 0; row<rows; row++) {
                for (int col=0; col<cols; col++) {

                    int val = rand() % (AVAILABLE_NODES - 1);

                    if (row == 0) {
                        map.at(col) = val;
                    } else if (col == 0) {
                        map.at(row * cols) = val;
                    } else {
                        int index = (row * cols) + col;
                        map.at(index) = val;
                    }
                }
            }
        };
    }
}