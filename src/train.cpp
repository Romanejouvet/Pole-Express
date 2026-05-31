#include "train.hpp"
#include "draw_scene.hpp"

extern GLBI_Engine myEngine;
extern IndexedMesh* meshCube;

static void drawBox(Vector3D pos, Vector3D size, float r, float g, float b)
{
    myEngine.setFlatColor(r, g, b);
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(pos);
    myEngine.mvMatrixStack.addHomothety(size);
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();
}

void drawTrain()
{
    myEngine.mvMatrixStack.pushMatrix();

  
    myEngine.mvMatrixStack.addTranslation(Vector3D(0.0f, 0.0f, 1.2f)); //position du train 

  

    drawBox(Vector3D(0.0f, 0.0f, 0.2f), Vector3D(8.5f, 3.4f, 0.25f),0.7f, 0.1f, 0.1f); //pour la planche en bas du train 



  drawBox(Vector3D(-1.9f, 0.0f, 2.2f),Vector3D(3.8f, 3.2f, 4.8f),0.12f, 0.12f, 0.12f); // pour le corps du train (la cabine) 

  

  drawBox(Vector3D(-1.9f, 0.0f, 4.7f),Vector3D(4.2f, 3.6f, 0.25f),0.7f, 0.1f, 0.1f); // pour le toit 

  

  drawBox(Vector3D(-1.9f, -1.61f, 2.8f),Vector3D(2.2f, 0.02f, 1.9f),0.9f, 0.85f, 0.6f); //fenetre gauche 

drawBox(Vector3D(-1.9f, 1.61f, 2.8f),Vector3D(2.2f, 0.02f, 1.9f),0.9f, 0.85f, 0.6f);  //fenetre droite 

  

    drawBox( Vector3D(1.6f, 0.0f, 1.5f),Vector3D(4.0f, 2.4f, 2.4f), 0.18f, 0.18f, 0.20f); // la chaudiere 

    

    drawBox( Vector3D(3.0f, 0.0f, 3.0f),Vector3D(0.6f, 0.6f, 1.8f),0.1f, 0.1f, 0.1f); //la cheminée 

 

    drawBox(Vector3D(1.0f, 0.0f, 2.8f), Vector3D(1.0f, 1.0f, 0.6f),0.75f, 0.6f, 0.2f); // le piti dome 

  

    drawBox(Vector3D(4.0f, 0.0f, 1.6f),Vector3D(0.7f, 0.7f, 0.7f),0.95f, 0.95f, 0.3f); // le phare 



    drawBox(Vector3D(-2.2f, -1.7f, -0.2f),Vector3D(0.9f, 0.4f, 0.9f), 0.1f, 0.1f, 0.1f); //roues arriere ! 

    drawBox(Vector3D(-2.2f, 1.7f, -0.2f), Vector3D(0.9f, 0.4f, 0.9f), 0.1f, 0.1f, 0.1f);

   

    drawBox(Vector3D(0.8f, -1.7f, -0.3f), Vector3D(0.7f, 0.35f, 0.7f), 0.1f, 0.1f, 0.1f); // roues du milieu! 

    drawBox(Vector3D(0.8f, 1.7f, -0.3f), Vector3D(0.7f, 0.35f, 0.7f), 0.1f, 0.1f, 0.1f); 

   

    drawBox( Vector3D(3.2f, -1.7f, -0.3f), Vector3D(0.7f, 0.35f, 0.7f), 0.1f, 0.1f, 0.1f); // roues avant 

    drawBox(Vector3D(3.2f, 1.7f, -0.3f), Vector3D(0.7f, 0.35f, 0.7f), 0.1f, 0.1f, 0.1f);

  
    drawBox( Vector3D(4.4f, 0.0f, 0.2f), Vector3D(0.3f, 3.0f, 1.0f), 0.7f, 0.1f, 0.1f); //pour le devant 

    myEngine.mvMatrixStack.popMatrix();
}