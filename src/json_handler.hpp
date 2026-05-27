#pragma once
#include <fstream>
#include <vector>
#include "../json.hpp"
using json = nlohmann::json;

struct Position{
    int x {0};
    int y {0};

    Position(int x, int y)
    : x(x), y(y) {}
    Position () {}
};

struct GridParam{
    int size_grid {0};
    Position origin;
    std::vector<Position> path;
};

GridParam readJson(std::string path);

