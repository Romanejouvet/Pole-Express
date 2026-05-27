#pragma once
#include "json_handler.hpp"
#include "glbasimac/glbi_engine.hpp"
#include "glbasimac/glbi_set_of_points.hpp"
#include "glbasimac/glbi_convex_2D_shape.hpp"
#include "tools/basic_mesh.hpp"

enum railType
{
    DROIT,
    COURBE
};

struct Rail
{
public:
    Position pos;
    int angle;
    railType type;
};

const float sr = 0.4f; // section d'un rail    
const float rr = 0.2f; // rayon d'une balast        
const float posx_rail1 = 3.0f; // position x du rail 1
const float posx_rail2 = 7.0f;  // position x du rail 2 
const float taille_case = 10.0f; // bon c'est la taille d'une case quoi
const float longueur_bois = 6.0f; // longueur de la balast

// primitives
void drawLocalCube(float dx, float dy, float dz);
void drawLocalCylinder(float radius, float x_start, float x_end);

