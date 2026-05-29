#pragma once

#include "glbasimac/glbi_engine.hpp"
#include "glbasimac/glbi_set_of_points.hpp"
#include "glbasimac/glbi_convex_2D_shape.hpp"
#include "tools/basic_mesh.hpp"
#include "train.hpp"
#include "rails.hpp"
#include "json_handler.hpp"
#include <vector>

using namespace glbasimac;

struct Rail;

/* Camera parameters and functions */
static const float Z_NEAR {0.1f};
static const float Z_FAR {500.f};
extern float angle_theta;      // Angle between x axis and viewpoint
extern float angle_phy  ;      // Angle between z axis and viewpoint
extern float dist_zoom  ;      // Distance between origin and viewpoint
extern bool camPOV; // define if cam is in POV mode
extern float anglePOV;
extern float xPOV, yPOV;
extern Vector3D viewPOV;
/* OpenGL Engine */
extern GLBI_Engine myEngine;

void initScene();

void drawScene(std::vector<Rail> rail_path);