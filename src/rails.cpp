#include "rails.hpp"


std::vector<Rail> CreateRailPath(GridParam par){
    std::vector<Rail> rail_path;

    for (size_t i = 0; i < par.path.size(); i++){
        Rail r;
        r.angle=0;
        r.type=DROIT;
        r.pos = par.path[i];
        rail_path.push_back(r);
    }

    return rail_path;
}