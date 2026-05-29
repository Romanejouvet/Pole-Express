#pragma once
#include "json_handler.hpp"
#include "rails.hpp"

struct Train
{
    Position pos;
    float angle;

    Train(Position p, float a)
    : pos(p), angle(a) {}
};

void drawTrain();