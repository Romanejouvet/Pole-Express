#include "element.hpp"
#include "draw_scene.hpp"

extern GLBI_Engine myEngine;
extern IndexedMesh* meshCube;

void drawElement()
{
    myEngine.mvMatrixStack.pushMatrix();

    
    myEngine.mvMatrixStack.addTranslation(Vector3D(25.0f, 0.0f, 0.0f)); //pour pas qu'il soit sur le train 

    myEngine.setFlatColor(0.95f, 0.95f, 0.95f);

   
    myEngine.mvMatrixStack.pushMatrix(); // le corps
    myEngine.mvMatrixStack.addTranslation(Vector3D(0.0f, 0.0f, 1.8f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(5.5f, 3.0f, 3.0f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

   
    myEngine.mvMatrixStack.pushMatrix(); //la tete
    myEngine.mvMatrixStack.addTranslation(Vector3D(-3.8f, 0.0f, 3.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(2.3f, 2.0f, 2.0f));
    myEngine.updateMvMatrix();
    meshCube->draw();

   
    myEngine.setFlatColor(0.05f, 0.05f, 0.05f); // les yeux 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(-0.2f, -0.6f, 0.3f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.2f, 0.2f, 0.2f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

   
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(-0.2f, 0.6f, 0.3f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.2f, 0.2f, 0.2f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();
    myEngine.setFlatColor(0.95f, 0.95f, 0.95f);
    myEngine.mvMatrixStack.popMatrix();

    
    myEngine.mvMatrixStack.pushMatrix(); // le museau 
    myEngine.mvMatrixStack.addTranslation(Vector3D(-5.3f, 0.0f, 2.6f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(1.0f, 0.9f, 0.9f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

   // les pattes 
    myEngine.mvMatrixStack.pushMatrix(); //avant gauche 
    myEngine.mvMatrixStack.addTranslation(Vector3D(-1.8f, -1.0f, 0.9f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(1.2f, 1.2f, 1.6f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

   
    myEngine.mvMatrixStack.pushMatrix(); // avant droite 
    myEngine.mvMatrixStack.addTranslation(Vector3D(-1.8f, 1.0f, 0.9f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(1.2f, 1.2f, 1.6f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

    
    myEngine.mvMatrixStack.pushMatrix(); //arriere gauche 
    myEngine.mvMatrixStack.addTranslation(Vector3D(1.8f, -1.0f, 0.9f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(1.0f, 1.0f, 1.6f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();


    myEngine.mvMatrixStack.pushMatrix(); //arriere droite 
    myEngine.mvMatrixStack.addTranslation(Vector3D(1.8f, 1.0f, 0.9f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(1.0f, 1.0f, 1.6f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();


    myEngine.mvMatrixStack.pushMatrix(); //oreille gauche 
    myEngine.mvMatrixStack.addTranslation(Vector3D(-3.8f, -0.9f, 4.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.5f, 0.5f, 0.5f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();


    myEngine.mvMatrixStack.pushMatrix(); //droite 
    myEngine.mvMatrixStack.addTranslation(Vector3D(-3.8f, 0.9f, 4.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.5f, 0.5f, 0.5f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();


   
    myEngine.mvMatrixStack.pushMatrix(); //queue 
    myEngine.mvMatrixStack.addTranslation(Vector3D(3.2f, 0.0f, 2.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.5f, 0.5f, 0.5f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

   
    myEngine.setFlatColor(0.05f, 0.05f, 0.05f); //nez 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(-5.85f, 0.0f, 2.6f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.3f, 0.4f, 0.3f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();


//arbre: deuxieme element 
myEngine.setFlatColor(0.60f, 0.35f, 0.15f);
myEngine.mvMatrixStack.pushMatrix(); //tronc 
myEngine.mvMatrixStack.addTranslation(Vector3D(6.0f, 2.5f, 1.5f));
myEngine.mvMatrixStack.addHomothety(Vector3D(0.6f, 0.6f, 2.5f));
myEngine.updateMvMatrix();
meshCube->draw();
myEngine.mvMatrixStack.popMatrix();


myEngine.setFlatColor(0.95f, 0.95f, 0.95f);
myEngine.mvMatrixStack.pushMatrix(); //feuilles basses 
myEngine.mvMatrixStack.addTranslation(Vector3D(6.0f, 2.5f, 3.5f));
myEngine.mvMatrixStack.addHomothety(Vector3D(2.5f, 2.5f, 1.2f));
myEngine.updateMvMatrix();
meshCube->draw();
myEngine.mvMatrixStack.popMatrix();


myEngine.mvMatrixStack.pushMatrix();// feuilles milieu 
myEngine.mvMatrixStack.addTranslation(Vector3D(6.0f, 2.5f, 4.6f));
myEngine.mvMatrixStack.addHomothety(Vector3D(2.0f, 2.0f, 1.0f));
myEngine.updateMvMatrix();
meshCube->draw();
myEngine.mvMatrixStack.popMatrix();


myEngine.mvMatrixStack.pushMatrix(); //feuilles hautes 
myEngine.mvMatrixStack.addTranslation(Vector3D(6.0f, 2.5f, 5.5f));
myEngine.mvMatrixStack.addHomothety(Vector3D(1.2f, 1.2f, 1.0f));
myEngine.updateMvMatrix();
meshCube->draw();
myEngine.mvMatrixStack.popMatrix();



 myEngine.mvMatrixStack.popMatrix();
}