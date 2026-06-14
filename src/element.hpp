#pragma once
#include "json_handler.hpp"
#include "rails.hpp"
#include "train.hpp"

struct Element
{
    Position pos;
    float angle;

    Element(Position p, float a)
    : pos(p), angle(a) {}
};

void drawElement();