#include "train.hpp"
#include "draw_scene.hpp"

extern GLBI_Engine myEngine;
extern IndexedMesh* meshCube;

void drawTrain()
{
    myEngine.mvMatrixStack.pushMatrix();

    myEngine.mvMatrixStack.addTranslation(
        Vector3D(20.0f, 20.0f, 3.0f));

    
    myEngine.setFlatColor(0.8f, 0.1f, 0.1f); // pour le corps du train 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addHomothety(Vector3D(8.0f, 4.0f, 4.0f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

    
    myEngine.setFlatColor(0.4f, 0.1f, 0.6f); // la partie cabine 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(-3.0f, 0.0f, 3.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(3.0f, 3.0f, 3.0f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

   
    myEngine.setFlatColor(0.1f, 0.1f, 0.1f); // pour le truc en haut du train
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation( Vector3D(3.0f, 0.0f, 4.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(1.0f, 1.0f, 3.0f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.popMatrix();
}