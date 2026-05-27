#include "draw_scene.hpp"
#include "rails.hpp"

/// Camera parameters
float angle_theta{45.0}; // Angle between x axis and viewpoint
float angle_phy{30.0};   // Angle between z axis and viewpoint
float dist_zoom{30.0};   // Distance between origin and viewpoint

GLBI_Engine myEngine;

GLBI_Set_Of_Points somePoints(3);
GLBI_Set_Of_Points axisX(3);
GLBI_Set_Of_Points axisY(3);
GLBI_Set_Of_Points axisZ(3);

GLBI_Convex_2D_Shape ground{3};

IndexedMesh *meshCube;
IndexedMesh *meshCylinder;

void drawRail()
{

    float center = taille_case/2;
    myEngine.setFlatColor(0.6f, 0.6f, 0.6f); //gris

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({center-posx_rail1, 0.0f, 2*rr + sr/2});
    myEngine.mvMatrixStack.addHomothety(Vector3D(sr, taille_case, sr));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({center-posx_rail2, 0.0f, 2*rr + sr/2});
    myEngine.mvMatrixStack.addHomothety(Vector3D(sr, taille_case, sr));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();


    myEngine.setFlatColor(0.4f, 0.25f, 0.15f); // marron 

    float positionsY[5] = {-2.0f, -1.0f, 0.0f, 1.0f, 2.0f};

    for (int i = 0; i < 5; ++i)
    {
        myEngine.mvMatrixStack.pushMatrix();

        myEngine.mvMatrixStack.addRotation(M_PI_2, Vector3D(0, 0, 1)); // on rotationne le bois pour etre perpendiculaire au rail
        myEngine.mvMatrixStack.addTranslation({positionsY[i]*rr*10,-longueur_bois/2 , rr}); // on le place bien (j'espere)

        myEngine.updateMvMatrix();
        meshCylinder->draw();
        myEngine.mvMatrixStack.popMatrix();
    }
}

void initScene()
{

    std::vector<float> points{
        0.0, 0.0, 0.0};

    somePoints.initSet(points, 1.0, 1.0, 1.0);


    std::vector<float> baseCarre{
        -10.0, -10.0, 0.0,
         10.0, -10.0, 0.0,
         10.0,  10.0, 0.0,
        -10.0,  10.0, 0.0};

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
    //axisX.drawSet();
    axisY.drawSet();
    //axisZ.drawSet();

    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.0f, 0.5f, 0.0f);
    ground.drawShape();
    myEngine.mvMatrixStack.popMatrix();
    }


    drawRail();


    drawRail();
}