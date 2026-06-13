#include "gare.hpp"

extern IndexedMesh *meshCube;
extern IndexedMesh *meshCylinder;
extern GLBI_Texture signTexture;
extern GLBI_Texture brickTexture;
extern GLBI_Texture smallBrickTexture;

void drawSiege()
{

    float r_rand = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    float g_rand = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    float b_rand = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);

    myEngine.setFlatColor(0.95, 0.80, 0.3);

    // dos
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(0.f, 4.4f, 4.5f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(1.8f, .2f, 2.f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

    // assise
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(0.f, 3.5f, 3.5f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(1.8f, 2.f, .2f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();
}

void drawGare()
{

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(0, 10, 0.f));
    // myEngine.mvMatrixStack.addRotation(M_PI_2,Vector3D(0,0,1));
    {
        // sol de la gare
        myEngine.setFlatColor(0.3f, 0.3f, 0.3f);
        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation(Vector3D(0.f, 1.f, 1.25f));
        myEngine.mvMatrixStack.addHomothety(Vector3D(10.f, 8.f, 2.5f));
        myEngine.updateMvMatrix();
        meshCube->draw();
        myEngine.mvMatrixStack.popMatrix();

        // plafond de la gare
        myEngine.setFlatColor(0.3f, 0.3f, 0.3f);
        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation(Vector3D(0.f, 1.f, 10.f));
        myEngine.mvMatrixStack.addHomothety(Vector3D(10.f, 8.f, 0.5f));
        myEngine.updateMvMatrix();
        meshCube->draw();
        myEngine.mvMatrixStack.popMatrix();

        // petite lampe au plafond
        myEngine.setFlatColor(0.8f, 0.8f, 0.3f);
        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation(Vector3D(0.f, 1.f, 9.7f));
        myEngine.mvMatrixStack.addHomothety(Vector3D(5.f, 2.f, 0.2f));
        myEngine.setLightPosition(Vector4D(0.f, 1.f, 5.f, 1.f));
        myEngine.setLightIntensity(Vector3D(100.f, 100.f, 100.f));
        myEngine.updateMvMatrix();
        meshCube->draw();
        myEngine.mvMatrixStack.popMatrix();

        //  petit rebord blanc
        myEngine.setFlatColor(0.9f, 0.9f, 0.9f);
        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation(Vector3D(0.f, -4.f, 2.f));
        myEngine.mvMatrixStack.addHomothety(Vector3D(10.f, 2.f, 1.f));
        myEngine.updateMvMatrix();
        meshCube->draw();
        myEngine.mvMatrixStack.popMatrix();

        // mur derriere
        myEngine.activateTexturing(true);
        brickTexture.attachTexture();
        myEngine.setFlatColor(0.5f, 0.5f, 0.5f);
        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation(Vector3D(0.f, 4.5f, 6.25f));
        myEngine.mvMatrixStack.addRotation(M_PI_2, Vector3D(0, 1, 0));
        myEngine.mvMatrixStack.addHomothety(Vector3D(7.5f, 1.f, 10.f));
        myEngine.updateMvMatrix();
        meshCube->draw();
        myEngine.mvMatrixStack.popMatrix();
        brickTexture.detachTexture();
        myEngine.activateTexturing(false);

        myEngine.activateTexturing(true);
        smallBrickTexture.attachTexture();

        myEngine.setFlatColor(1.f, 1.f, 1.f);

        // mur gauche
        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation(Vector3D(4.5f, 3.5f, 6.25f));
        myEngine.mvMatrixStack.addRotation(M_PI_2, Vector3D(0, 1, 0));
        myEngine.mvMatrixStack.addHomothety(Vector3D(7.5f, 2.5f, 1.f));
        myEngine.updateMvMatrix();
        meshCube->draw();
        myEngine.mvMatrixStack.popMatrix();

        // mur droit
        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation(Vector3D(-4.5f, 3.5f, 6.25f));
        myEngine.mvMatrixStack.addRotation(M_PI_2, Vector3D(0, 1, 0));
        myEngine.mvMatrixStack.addHomothety(Vector3D(7.5f, 2.5f, 1.f));
        myEngine.updateMvMatrix();
        meshCube->draw();
        myEngine.mvMatrixStack.popMatrix();

        smallBrickTexture.detachTexture();
        myEngine.activateTexturing(false);

        // rebord sous les sieges

        myEngine.setFlatColor(0.5f, 0.5f, 0.5f);
        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation(Vector3D(0.f, 3.f, 3.f));
        myEngine.mvMatrixStack.addHomothety(Vector3D(10.f, 1.5f, 1.f));
        myEngine.updateMvMatrix();
        meshCube->draw();
        myEngine.mvMatrixStack.popMatrix();

        // panneau bleu
        myEngine.activateTexturing(true);
        signTexture.attachTexture();

        myEngine.setFlatColor(1.f, 1.f, 1.f);

        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation(Vector3D(0.f, 3.5f, 8.f));
        myEngine.mvMatrixStack.addRotation(-M_PI_2, Vector3D(0, 1, 0));

        myEngine.mvMatrixStack.addHomothety(Vector3D(-2.f, .5f, 6.f));
        myEngine.updateMvMatrix();

        meshCube->draw();

        myEngine.mvMatrixStack.popMatrix();

        signTexture.detachTexture();
        myEngine.activateTexturing(false);

        for (float i = -2.5; i < 3; i += 2.5)
        {

            // siege (un seul pour l'instant)
            myEngine.mvMatrixStack.pushMatrix();
            myEngine.mvMatrixStack.addTranslation(Vector3D(i, -1.f, 0.f));
            myEngine.updateMvMatrix();
            drawSiege();
            myEngine.mvMatrixStack.popMatrix();
        }

        // panneau exit gauche
        myEngine.setFlatColor(0.5f, 0.9f, 0.5f);
        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation(Vector3D(4.5f, 2.f, 8.f));
        myEngine.mvMatrixStack.addHomothety(Vector3D(1.f, 0.2f, 0.5f));
        myEngine.setLightPosition(Vector4D(0.f, 1.f, 5.f, 1.f));
        myEngine.setLightIntensity(Vector3D(100.f, 100.f, 100.f));
        myEngine.updateMvMatrix();
        meshCube->draw();
        myEngine.mvMatrixStack.popMatrix();

        // panneau exit droit
        myEngine.setFlatColor(0.8f, 0.8f, 0.3f);
        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation(Vector3D(0.f, 1.f, 9.7f));
        myEngine.mvMatrixStack.addHomothety(Vector3D(5.f, 2.f, 0.2f));
        myEngine.setLightPosition(Vector4D(0.f, 1.f, 5.f, 1.f));
        myEngine.setLightIntensity(Vector3D(100.f, 100.f, 100.f));
        myEngine.updateMvMatrix();
        meshCube->draw();
        myEngine.mvMatrixStack.popMatrix();

        // poubelle 
        myEngine.setFlatColor(0.9f, 0.9f, 0.9f);
        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation(Vector3D(-5.f,-5.f,5.f));
        myEngine.mvMatrixStack.addHomothety(Vector3D(3.f, 3.f, .35f));
        myEngine.mvMatrixStack.addRotation(-M_PI_2, Vector3D(1, 0, 0));
        myEngine.updateMvMatrix();
        meshCylinder->draw();
        myEngine.mvMatrixStack.popMatrix();
    }

    myEngine.mvMatrixStack.popMatrix();
}