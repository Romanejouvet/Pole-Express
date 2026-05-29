#include "draw_scene.hpp"
#include "rails.hpp"
#include "train.hpp"

/// Camera parameters
float angle_theta{45.0}; // Angle between x axis and viewpoint
float angle_phy{30.0};   // Angle between z axis and viewpoint
float dist_zoom{30.0};   // Distance between origin and viewpoint

GLBI_Engine myEngine;
IndexedMesh *meshCube;
IndexedMesh *meshCylinder;

GLBI_Set_Of_Points somePoints(3);
GLBI_Set_Of_Points axisX(3);
GLBI_Set_Of_Points axisY(3);
GLBI_Set_Of_Points axisZ(3);

GLBI_Convex_2D_Shape ground{3};

void initScene()
{

    std::vector<float> points{
        0.0, 0.0, 0.0};

    somePoints.initSet(points, 1.0, 1.0, 1.0);

    std::vector<float> baseCarre{
        -50.0, -50.0, 0.0,
        50.0, -50.0, 0.0,
        50.0, 50.0, 0.0,
        -50.0, 50.0, 0.0};

    ground.initShape(baseCarre);
    ground.changeNature(GL_TRIANGLE_FAN);

    std::vector<float> coord_axisX{
        0, 0, 0,
        10., 0, 0};

    std::vector<float> color_axisX{
        1., 0, 0,
        1., 0, 0};

    axisX.initSet(coord_axisX, color_axisX);
    axisX.changeNature(GL_LINES);

    std::vector<float> coord_axisY{
        0, 0, 0,
        0, 10., 0};

    std::vector<float> color_axisY{
        0, 1, 0,
        0, 1., 0};

    axisY.initSet(coord_axisY, color_axisY);
    axisY.changeNature(GL_LINES);

    std::vector<float> coord_axisZ{
        0, 0, 0,
        0, 0, 10.};

    std::vector<float> color_axisZ{
        0, 0, 1.,
        0, 0, 1.};

    axisZ.initSet(coord_axisZ, color_axisZ);
    axisZ.changeNature(GL_LINES);

    meshCube = basicCube();
    meshCube->createVAO();

    meshCylinder = basicCylinder(
        longueur_bois,
        rr);

    meshCylinder->createVAO();
}

void drawScene()
{
    {
        myEngine.mvMatrixStack.pushMatrix();
        myEngine.updateMvMatrix();
        // axisX.drawSet();
        axisY.drawSet();
        // axisZ.drawSet();

        myEngine.updateMvMatrix();
        myEngine.setFlatColor(0.0f, 0.5f, 0.0f);
        ground.drawShape();
        myEngine.mvMatrixStack.popMatrix();
    }

    GridParam pars = readJson("../src/config.json");
    std::vector<Rail> rail_path = CreateRailPath(pars);
    for (auto rail : rail_path)
    {
        drawRail(rail, myEngine);
    }
    drawTrain();

    return;
}