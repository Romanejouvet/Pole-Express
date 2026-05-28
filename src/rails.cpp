#include "rails.hpp"

std::vector<Rail> CreateRailPath(GridParam par)
{
    std::vector<Rail> rail_path;

    std::vector<Position> &p = par.path;
    size_t size = p.size();

    for (size_t i = 0; i < size; i++)
    {
        Rail r;

        r.pos = p[i];
        r.type = DROIT;
        r.angle = 0;
        // parametres de base pour éviter les soucis

        size_t i_prev = (i == 0) ? size - 1 : i - 1;
        size_t i_next = (i == size - 1) ? 0 : i + 1;

        Position prev = p[i_prev];
        Position cur = p[i];
        Position next = p[i_next];

        int dx1 = cur.x - prev.x;
        int dy1 = cur.y - prev.y;

        int dx2 = next.x - cur.x;
        int dy2 = next.y - cur.y;
        // pour rendre la suite plus propre

        if (dy1 == 0 && dy2 == 0) r.angle = M_PI_2;

        else if (dx1 == 0 && dx2 == 0) r.angle = 0; // utile pour pas avoir des rails courbes de partout

        else
        {
            r.type = COURBE;

            if ((dx1 == 1 && dy2 == -1) || (dy1 == 1 && dx2 == -1)) r.angle = M_PI_2;
            else if ((dy1 == -1 && dx2 == 1) || (dx1 == -1 && dy2 == 1)) r.angle = -M_PI_2; 
            else if ((dx1 == -1 && dy2 == -1) || (dy1 == 1 && dx2 == 1)) r.angle = M_PI;
            // sinon angle a 0 
        }

        rail_path.push_back(r);
    }

    return rail_path;
}