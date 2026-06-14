#include "element.hpp"
#include "draw_scene.hpp"

extern GLBI_Engine myEngine;
extern IndexedMesh* meshCube;


void drawElement()
{
    myEngine.mvMatrixStack.pushMatrix();


    myEngine.mvMatrixStack.addTranslation(Vector3D(15.0f, 0.0f, 0.0f));

    myEngine.setFlatColor(1.0f, 1.0f, 1.0f);

    
    myEngine.mvMatrixStack.pushMatrix(); // corps 
    myEngine.mvMatrixStack.addTranslation(Vector3D(0.0f,0.0f,4.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(12.0f,6.0f,6.0f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

    
    myEngine.mvMatrixStack.pushMatrix(); //tete 
    myEngine.mvMatrixStack.addTranslation(Vector3D(8.0f,0.0f,7.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(5.0f,4.0f,4.0f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

    
    myEngine.mvMatrixStack.pushMatrix(); //museau 
    myEngine.mvMatrixStack.addTranslation(Vector3D(11.0f,0.0f,6.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(2.5f,2.0f,2.0f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

  
    float legs[4][2] = //pattes 
    {
        {-4.0f,-2.0f},
        {-4.0f, 2.0f},
        { 4.0f,-2.0f},
        { 4.0f, 2.0f}
    };

    for(int i=0;i<4;i++)
    {
        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation(
            Vector3D(legs[i][0], legs[i][1], 0.5f));
        myEngine.mvMatrixStack.addHomothety(
            Vector3D(2.0f,2.0f,5.0f));
        myEngine.updateMvMatrix();
        meshCube->draw();
        myEngine.mvMatrixStack.popMatrix();
    }

    
    myEngine.mvMatrixStack.pushMatrix(); //oreilles
    myEngine.mvMatrixStack.addTranslation(Vector3D(7.0f,-1.5f,10.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(1.0f,1.0f,1.0f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(7.0f,1.5f,10.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(1.0f,1.0f,1.0f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

   
    myEngine.setFlatColor(0.05f,0.05f,0.05f); // nez 

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(13.0f,0.0f,6.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.6f,0.8f,0.6f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.popMatrix();
}