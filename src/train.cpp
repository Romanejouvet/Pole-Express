#include "train.hpp"
#include "draw_scene.hpp"

extern GLBI_Engine myEngine;
extern IndexedMesh* meshCube;
extern IndexedMesh* meshCylinder; 

void drawTrain()
{
    
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(0.0f, 0.0f, 1.2f)); //position du train pour etre sur les rails

   
    myEngine.setFlatColor(0.7f, 0.1f, 0.1f); // le plancher rouge 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(0.0f, 0.0f, 0.2f)); 
    myEngine.mvMatrixStack.addHomothety(Vector3D(8.5f, 3.4f, 0.25f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();


 
    myEngine.setFlatColor(0.12f, 0.12f, 0.12f); // la cabine 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(-2.2f, 0.0f, 1.8f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(3.4f, 3.2f, 3.0f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();


    myEngine.setFlatColor(0.7f, 0.1f, 0.1f); // le toit de la cabine 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(-2.2f, 0.0f, 3.35f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(3.8f, 3.5f, 0.25f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();


    myEngine.setFlatColor(0.9f, 0.85f, 0.6f); // la fenetre du toit a gauche 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(-2.2f, -1.61f, 2.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(1.8f, 0.02f, 1.2f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

    
    myEngine.mvMatrixStack.pushMatrix(); // la fenetre a droite 
    myEngine.mvMatrixStack.addTranslation(Vector3D(-2.2f, 1.61f, 2.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(1.8f, 0.02f, 1.2f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();


   
    myEngine.setFlatColor(0.18f, 0.18f, 0.2f); // la chaudiere lol 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(1.6f, 0.0f, 1.4f));
    myEngine.mvMatrixStack.addRotation(90.0f, Vector3D(0.0f, 1.0f, 0.0f)); 
    myEngine.updateMvMatrix();
    meshCylinder->draw();
    myEngine.mvMatrixStack.popMatrix();


 
    

    myEngine.setFlatColor(0.1f, 0.1f, 0.1f); // cheminée 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(3.2f, 0.0f, 2.5f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.45f, 0.45f, 0.12f)); 
    myEngine.updateMvMatrix();
    meshCylinder->draw();
    myEngine.mvMatrixStack.popMatrix();

  
    myEngine.setFlatColor(0.75f, 0.6f, 0.2f); // dome a l'avant 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(1.1f, 0.0f, 2.4f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.55f, 0.55f, 0.08f)); 
    myEngine.updateMvMatrix();
    meshCylinder->draw();
    myEngine.mvMatrixStack.popMatrix();

  
    myEngine.setFlatColor(0.7f, 0.1f, 0.1f); // le phare a l'avant 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(4.0f, 0.0f, 1.6f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.6f, 0.6f, 0.6f));
    myEngine.updateMvMatrix(); 
    meshCube->draw(); 
    myEngine.mvMatrixStack.popMatrix();

// les roues ! 
  
    myEngine.setFlatColor(0.1f, 0.1f, 0.1f); // roue arriere gauche 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(-2.2f, -1.75f, -0.2f)); 
    myEngine.mvMatrixStack.addRotation(90.0f, Vector3D(1.0f, 0.0f, 0.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(1.1f, 1.1f, 0.03f)); 
    myEngine.updateMvMatrix(); meshCylinder->draw(); myEngine.mvMatrixStack.popMatrix();

    myEngine.setFlatColor(0.7f, 0.1f, 0.1f); // centre roue 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(-2.2f, -1.78f, -0.2f));
    myEngine.mvMatrixStack.addRotation(90.0f, Vector3D(1.0f, 0.0f, 0.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.6f, 0.6f, 0.04f));
    myEngine.updateMvMatrix(); meshCylinder->draw(); myEngine.mvMatrixStack.popMatrix();


    myEngine.setFlatColor(0.1f, 0.1f, 0.1f); // roue arriere droite 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(-2.2f, 1.75f, -0.2f));
    myEngine.mvMatrixStack.addRotation(90.0f, Vector3D(1.0f, 0.0f, 0.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(1.1f, 1.1f, 0.03f));
    myEngine.updateMvMatrix(); meshCylinder->draw(); myEngine.mvMatrixStack.popMatrix();

    myEngine.setFlatColor(0.7f, 0.1f, 0.1f); // centre roue 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(-2.2f, 1.78f, -0.2f));
    myEngine.mvMatrixStack.addRotation(90.0f, Vector3D(1.0f, 0.0f, 0.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.6f, 0.6f, 0.04f));
    myEngine.updateMvMatrix(); meshCylinder->draw(); myEngine.mvMatrixStack.popMatrix();


   
    myEngine.setFlatColor(0.1f, 0.1f, 0.1f); // roue milieu gauche 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(0.8f, -1.75f, -0.4f));
    myEngine.mvMatrixStack.addRotation(90.0f, Vector3D(1.0f, 0.0f, 0.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.8f, 0.8f, 0.03f));
    myEngine.updateMvMatrix(); meshCylinder->draw(); myEngine.mvMatrixStack.popMatrix();

    myEngine.setFlatColor(0.7f, 0.1f, 0.1f); // centre roue 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(0.8f, -1.78f, -0.4f));
    myEngine.mvMatrixStack.addRotation(90.0f, Vector3D(1.0f, 0.0f, 0.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.4f, 0.4f, 0.04f));
    myEngine.updateMvMatrix(); meshCylinder->draw(); myEngine.mvMatrixStack.popMatrix();


    myEngine.setFlatColor(0.1f, 0.1f, 0.1f); //roue milieu droite 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(0.8f, 1.75f, -0.4f));
    myEngine.mvMatrixStack.addRotation(90.0f, Vector3D(1.0f, 0.0f, 0.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.8f, 0.8f, 0.03f));
    myEngine.updateMvMatrix(); meshCylinder->draw(); myEngine.mvMatrixStack.popMatrix();

    myEngine.setFlatColor(0.7f, 0.1f, 0.1f); // centre roue 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(0.8f, 1.78f, -0.4f));
    myEngine.mvMatrixStack.addRotation(90.0f, Vector3D(1.0f, 0.0f, 0.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.4f, 0.4f, 0.04f));
    myEngine.updateMvMatrix(); meshCylinder->draw(); myEngine.mvMatrixStack.popMatrix();


   
    myEngine.setFlatColor(0.1f, 0.1f, 0.1f); //roue zvant gauche 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(3.2f, -1.75f, -0.4f));
    myEngine.mvMatrixStack.addRotation(90.0f, Vector3D(1.0f, 0.0f, 0.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.8f, 0.8f, 0.03f));
    myEngine.updateMvMatrix(); meshCylinder->draw(); myEngine.mvMatrixStack.popMatrix();

    myEngine.setFlatColor(0.7f, 0.1f, 0.1f); // centre roue 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(3.2f, -1.78f, -0.4f));
    myEngine.mvMatrixStack.addRotation(90.0f, Vector3D(1.0f, 0.0f, 0.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.4f, 0.4f, 0.04f));
    myEngine.updateMvMatrix(); meshCylinder->draw(); myEngine.mvMatrixStack.popMatrix();


    myEngine.setFlatColor(0.1f, 0.1f, 0.1f); //roue avant droite 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(3.2f, 1.75f, -0.4f));
    myEngine.mvMatrixStack.addRotation(90.0f, Vector3D(1.0f, 0.0f, 0.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.8f, 0.8f, 0.03f));
    myEngine.updateMvMatrix(); meshCylinder->draw(); myEngine.mvMatrixStack.popMatrix();

    myEngine.setFlatColor(0.7f, 0.1f, 0.1f); //centre roue 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(3.2f, 1.78f, -0.4f));
    myEngine.mvMatrixStack.addRotation(90.0f, Vector3D(1.0f, 0.0f, 0.0f));
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.4f, 0.4f, 0.04f));
    myEngine.updateMvMatrix(); meshCylinder->draw(); myEngine.mvMatrixStack.popMatrix();


    myEngine.setFlatColor(0.7f, 0.1f, 0.1f); // truc tout a l'avant 
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(4.4f, 0.0f, -0.1f)); 
    myEngine.mvMatrixStack.addRotation(-25.0f, Vector3D(0.0f, 1.0f, 0.0f)); 
    myEngine.mvMatrixStack.addHomothety(Vector3D(0.2f, 3.2f, 1.0f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.popMatrix();
}