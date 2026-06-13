#include "draw_scene.hpp"
#include "rails.hpp"
#include "train.hpp"
#include "gare.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "tools/stb_image.h"
#include "glbasimac/glbi_texture.hpp"

/// Camera parameters
float angle_theta{-90.0}; // Angle between x axis and viewpoint
float angle_phy{30.0};    // Angle between z axis and viewpoint
float dist_zoom{30.0};    // Distance between origin and viewpoint
bool camPOV{false};       // define if cam is in POV mode
float anglePOV{0};
float xPOV{1.f}, yPOV{1.f};
Vector3D view{Vector3D(xPOV, yPOV, 5)};
float lightAngle{0.f};
bool animLight{false}; // definit si on fait bouger la boule ou pas

// meshes
GLBI_Engine myEngine;
IndexedMesh *meshCube;
IndexedMesh *meshCylinder;
IndexedMesh *meshSphere;

// textures
GLBI_Texture grassTexture; // bon la c'est de la neige mais ca pourrait être n'importe quoi
GLBI_Texture signTexture;
GLBI_Texture brickTexture;
GLBI_Texture smallBrickTexture;

GLBI_Set_Of_Points somePoints(3);
GLBI_Set_Of_Points axisX(3);
GLBI_Set_Of_Points axisY(3);
GLBI_Set_Of_Points axisZ(3);
StandardMesh *ground;

void loadTextures()
{

    int width, height, channels;

    // ground textures

    unsigned char *data =
        stbi_load("../assets/textures/grass.jpg", &width, &height, &channels, 0);

    if (data == nullptr)
    {
        std::cerr << "Failed to load texture" << std::endl;
        return;
    }

    grassTexture.createTexture();

    grassTexture.attachTexture();

    grassTexture.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    grassTexture.loadImage(width, height, channels, data);

    grassTexture.detachTexture();

    stbi_image_free(data);

    // sign texture

    unsigned char *signData =
        stbi_load("../assets/textures/panneau.png", &width, &height, &channels, 0);

    if (signData == nullptr)
    {
        std::cerr << "Failed to load texture" << std::endl;
        return;
    }

    signTexture.createTexture();

    signTexture.attachTexture();

    signTexture.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    signTexture.loadImage(width, height, channels, signData);

    signTexture.detachTexture();

    stbi_image_free(signData);

    // brick texture 
    unsigned char *brickData =
    stbi_load("../assets/textures/briques_horizontal.png", &width, &height, &channels, 0);

    if (brickData == nullptr)
    {
        std::cerr << "Failed to load texture" << std::endl;
        return;
    }

    brickTexture.createTexture();

    brickTexture.attachTexture();

    brickTexture.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    brickTexture.loadImage(width, height, channels, brickData);

    brickTexture.detachTexture();

    stbi_image_free(brickData);

        // small side wall brick texture 
    unsigned char *smallBrickData =
    stbi_load("../assets/textures/briques_vertical.png", &width, &height, &channels, 0);

    if (smallBrickData == nullptr)
    {
        std::cerr << "Failed to load texture" << std::endl;
        return;
    }

    smallBrickTexture.createTexture();

    smallBrickTexture.attachTexture();

    smallBrickTexture.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    smallBrickTexture.loadImage(width, height, channels, smallBrickData);

    smallBrickTexture.detachTexture();

    stbi_image_free(smallBrickData);
}


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

    ground = basicRect(100.0, 100.0);
    ground->createVAO();

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

    loadTextures();

    meshSphere = basicSphere(0.5);
    meshSphere->createVAO();

    myEngine.switchToPhongShading();

    myEngine.setLightIntensity(Vector3D(500.f, 500.f, 500.f));

    myEngine.switchToFlatShading();
}

void drawScenery()
{
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.updateMvMatrix();
    // axisX.drawSet();
    axisY.drawSet();
    // axisZ.drawSet();

    myEngine.activateTexturing(true);
    grassTexture.attachTexture();
    myEngine.mvMatrixStack.addRotation(M_PI_2, Vector3D(1, 0, 0));
    myEngine.mvMatrixStack.addTranslation(Vector3D(-50, 0, -50));
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(1.0f, 1.f, 1.f);
    ground->draw();
    myEngine.mvMatrixStack.popMatrix();
    grassTexture.detachTexture();
    myEngine.activateTexturing(false);
}

void drawDirectionnalLight()
{
    myEngine.setLightPosition(Vector4D(0, 0, 50, 0.0f));
}

void drawPointLight(Vector3D vec)
{

    myEngine.setLightPosition(Vector4D(vec.x, vec.y, vec.z, 1.f));
}

void drawScene(std::vector<Rail> rail_path)
{
    myEngine.switchToPhongShading();

    drawDirectionnalLight();

    drawPointLight(Vector3D(10, 0, 25));

    drawScenery();

    for (auto rail : rail_path)
        drawRail(rail, myEngine);

    drawTrain();

    drawGare();

    myEngine.switchToFlatShading();
}