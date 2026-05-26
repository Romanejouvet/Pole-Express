#include "draw_scene.hpp"

/// Camera parameters
float angle_theta{45.0}; // Angle between x axis and viewpoint
float angle_phy{30.0};	 // Angle between z axis and viewpoint
float dist_zoom{30.0};	 // Distance between origin and viewpoint

GLBI_Engine myEngine;
GLBI_Set_Of_Points somePoints(3);
GLBI_Set_Of_Points axisX(3);
GLBI_Set_Of_Points axisY(3);
GLBI_Set_Of_Points axisZ(3);
GLBI_Convex_2D_Shape ground{3};

void initScene()
{
	std::vector<float> points{0.0, 0.0, 0.0};
	somePoints.initSet(points, 1.0, 1.0, 1.0);

	std::vector<float> baseCarre{-10.0, -10.0, 0.0,
								 10.0, -10.0, 0.0,
								 10.0, 10.0, 0.0,
								 -10.0, 10.0, 0.0};

	std::vector<float> coord_axisX{0, 0, 0,
								   10., 0, 0};
	std::vector<float> color_axisX{1., 0, 0,
								   1., 0, 0};
	axisX.initSet(coord_axisX, color_axisX);
	axisX.changeNature(GL_LINES);

	std::vector<float> coord_axisY{0, 0, 0,
								   0, 10., 0};
	std::vector<float> color_axisY{0, 1, 0,
								   0, 1., 0};
	axisY.initSet(coord_axisY, color_axisY);
	axisY.changeNature(GL_LINES);

	std::vector<float> coord_axisZ{0, 0, 0,
								   0, 0, 10.};
	std::vector<float> color_axisZ{0, 0, 1.,
								   0, 0, 1.};
	axisZ.initSet(coord_axisZ, color_axisZ);
	axisZ.changeNature(GL_LINES);

	ground.initShape(baseCarre);
	ground.changeNature(GL_TRIANGLE_FAN);
}

void drawScene()
{
	glPointSize(10.0);

	somePoints.drawSet();
	axisX.drawSet();
	axisY.drawSet();
	axisZ.drawSet();

	myEngine.setFlatColor(0.0, 0.5, 0.0);
	ground.drawShape();
}
