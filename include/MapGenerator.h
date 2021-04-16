#include <functional>
#include <vector>

#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

namespace GameBackend
{
    std::function<void(std::vector<int>&, int, int)> easyMapGenerator();
    std::function<void(std::vector<int>&, int, int)> hardMapGenerator();
}

#endif