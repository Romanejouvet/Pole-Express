#include "train.hpp"
#include "draw_scene.hpp"

extern GLBI_Engine myEngine;
extern IndexedMesh* meshCube;

void drawTrain()
{
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(0.0f, 0.0f, 1.2f));

   

    myEngine.setFlatColor(0.7f, 0.1f, 0.1f); // la partie haute 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(0.0f, 0.0f, 0.2f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(8.5f, 3.4f, 0.25f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

  

    myEngine.setFlatColor(0.12f, 0.12f, 0.12f); // pour la cabine 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(-1.9f, 0.0f, 2.2f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(3.8f, 3.2f, 4.8f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

  

    myEngine.setFlatColor(0.7f, 0.1f, 0.1f); // le toit 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(-1.9f, 0.0f, 4.7f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(4.2f, 3.6f, 0.25f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

 

    myEngine.setFlatColor(0.9f, 0.85f, 0.6f); // la fenetrr a gauche 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(-1.9f, -1.61f, 2.8f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(2.2f, 0.02f, 1.9f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();


    myEngine.mvMatrixStack.pushMatrix(); // la fenetre a droite 
    myEngine.mvMatrixStack.addTranslation(Vector3D(-1.9f, 1.61f, 2.8f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(2.2f, 0.02f, 1.9f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

  

    myEngine.setFlatColor(0.18f, 0.18f, 0.20f); // la chaudiere 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(1.6f, 0.0f, 1.5f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(4.0f, 2.4f, 2.4f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();



    myEngine.setFlatColor(0.1f, 0.1f, 0.1f); //la cheminée 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(3.0f, 0.0f, 3.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.6f, 0.6f, 1.8f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();



myEngine.setFlatColor(0.92f, 0.92f, 0.92f); // la fuméeeee

for(int n = 0; n < 4; n++)
{
    float z = 5.0f + n * 1.2f;
    float x = 3.0f + n * 0.4f;

    
    myEngine.mvMatrixStack.pushMatrix();// fumée au centre 
    myEngine.mvMatrixStack.addTranslation(Vector3D(x, 0.0f, z));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.8f,0.8f,0.8f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();


    myEngine.mvMatrixStack.pushMatrix();// a gauhe 
    myEngine.mvMatrixStack.addTranslation(Vector3D(x-0.6f,0.0f,z));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.7f,0.7f,0.7f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

    
    myEngine.mvMatrixStack.pushMatrix(); // a droite 
    myEngine.mvMatrixStack.addTranslation(Vector3D(x+0.6f,0.0f,z));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.7f,0.7f,0.7f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

  
    myEngine.mvMatrixStack.pushMatrix();// en haut 
    myEngine.mvMatrixStack.addTranslation(Vector3D(x,0.0f,z+0.6f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.7f,0.7f,0.7f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

   
    myEngine.mvMatrixStack.pushMatrix(); //en bas 
    myEngine.mvMatrixStack.addTranslation(Vector3D(x,0.0f,z-0.6f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.7f,0.7f,0.7f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();
}

    myEngine.setFlatColor(0.75f, 0.6f, 0.2f); // le dome
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(1.0f, 0.0f, 2.8f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(1.0f, 1.0f, 0.6f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();



    myEngine.setFlatColor(0.95f, 0.95f, 0.3f); // le phare 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(4.0f, 0.0f, 1.6f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.7f, 0.7f, 0.7f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();



    myEngine.setFlatColor(0.1f, 0.1f, 0.1f); //pour les roues arrieres 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(-2.2f, -1.7f, -0.2f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.9f, 0.4f, 0.9f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(-2.2f, 1.7f, -0.2f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.9f, 0.4f, 0.9f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

 

    myEngine.mvMatrixStack.pushMatrix(); //celles au milieu 
    myEngine.mvMatrixStack.addTranslation(Vector3D(0.8f, -1.7f, -0.3f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.7f, 0.35f, 0.7f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(0.8f, 1.7f, -0.3f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.7f, 0.35f, 0.7f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

  
    myEngine.mvMatrixStack.pushMatrix();//les roues avant 
    myEngine.mvMatrixStack.addTranslation(Vector3D(3.2f, -1.7f, -0.3f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.7f, 0.35f, 0.7f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(3.2f, 1.7f, -0.3f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.7f, 0.35f, 0.7f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();


    myEngine.setFlatColor(0.7f, 0.1f, 0.1f); //le pare choc 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(4.4f, 0.0f, 0.2f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.3f, 3.0f, 1.0f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

    

    myEngine.mvMatrixStack.popMatrix();
}