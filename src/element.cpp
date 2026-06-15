#include "element.hpp"
#include "draw_scene.hpp"

extern GLBI_Engine myEngine;
extern IndexedMesh* meshCube;



void drawElement()
{
    myEngine.mvMatrixStack.pushMatrix();
    
    float ours[3][2] ={{25.0f, 14.0f},{-15.0f, 20.0f},{-5.0f, -18.0f}};

    for(int i = 0; i < 3; i++)
    {
        float x = ours[i][0];
        float y = ours[i][1];

        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation(Vector3D(x, y, 0.0f));

        myEngine.setFlatColor(0.95f, 0.95f, 0.95f);
        myEngine.mvMatrixStack.pushMatrix(); //le corps 
        myEngine.mvMatrixStack.addTranslation(Vector3D(0.0f, 0.0f, 1.8f));
        myEngine.mvMatrixStack.addHomothety(Vector3D(5.5f, 3.0f, 3.0f));
        myEngine.updateMvMatrix();
        meshCube->draw();
        myEngine.mvMatrixStack.popMatrix();

   
        myEngine.mvMatrixStack.pushMatrix();// la tete 
        myEngine.mvMatrixStack.addTranslation(Vector3D(-3.8f, 0.0f, 3.0f));
        myEngine.mvMatrixStack.addHomothety(Vector3D(2.3f, 2.0f, 2.0f));
        myEngine.updateMvMatrix();
        meshCube->draw();

     
        myEngine.setFlatColor(0.05f, 0.05f, 0.05f); //les yeux 
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

       
        myEngine.mvMatrixStack.pushMatrix(); // le nez 
        myEngine.mvMatrixStack.addTranslation(Vector3D(-5.3f, 0.0f, 2.6f));
        myEngine.mvMatrixStack.addHomothety(Vector3D(1.0f, 0.9f, 0.9f));
        myEngine.updateMvMatrix();
        meshCube->draw();
        myEngine.mvMatrixStack.popMatrix();

        
        myEngine.mvMatrixStack.pushMatrix(); //pattes a l'avant 
        myEngine.mvMatrixStack.addTranslation(Vector3D(-1.8f, -1.0f, 0.9f));
        myEngine.mvMatrixStack.addHomothety(Vector3D(1.2f, 1.2f, 1.6f));
        myEngine.updateMvMatrix();
        meshCube->draw();
        myEngine.mvMatrixStack.popMatrix();

        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation(Vector3D(-1.8f, 1.0f, 0.9f));
        myEngine.mvMatrixStack.addHomothety(Vector3D(1.2f, 1.2f, 1.6f));
        myEngine.updateMvMatrix();
        meshCube->draw();
        myEngine.mvMatrixStack.popMatrix();

     
        myEngine.mvMatrixStack.pushMatrix(); //pattes a l'arriere 
        myEngine.mvMatrixStack.addTranslation(Vector3D(1.8f, -1.0f, 0.9f));
        myEngine.mvMatrixStack.addHomothety(Vector3D(1.0f, 1.0f, 1.6f));
        myEngine.updateMvMatrix();
        meshCube->draw();
        myEngine.mvMatrixStack.popMatrix();

        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation(Vector3D(1.8f, 1.0f, 0.9f));
        myEngine.mvMatrixStack.addHomothety(Vector3D(1.0f, 1.0f, 1.6f));
        myEngine.updateMvMatrix();
        meshCube->draw();
        myEngine.mvMatrixStack.popMatrix();


        myEngine.mvMatrixStack.pushMatrix(); //oreilles
        myEngine.mvMatrixStack.addTranslation(Vector3D(-3.8f, -0.9f, 4.0f));
        myEngine.mvMatrixStack.addHomothety(Vector3D(0.5f, 0.5f, 0.5f));
        myEngine.updateMvMatrix();
        meshCube->draw();
        myEngine.mvMatrixStack.popMatrix();

        myEngine.mvMatrixStack.pushMatrix();
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

    
        myEngine.setFlatColor(0.05f, 0.05f, 0.05f); //queue
        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation(Vector3D(-5.85f, 0.0f, 2.6f));
        myEngine.mvMatrixStack.addHomothety(Vector3D(0.3f, 0.4f, 0.3f));
        myEngine.updateMvMatrix();
        meshCube->draw();
        myEngine.mvMatrixStack.popMatrix();

        myEngine.mvMatrixStack.popMatrix();
    }



    float arbre[10][2] ={ //les arbres enneigés 
        {8.0f, 12.0f},
        {18.0f, -15.0f},
        {18.0f, 20.0f},
        {-10.0f, 14.0f},
        {-15.0f, -16.0f},
        {-25.0f, 10.0f},
        {30.0f, -14.0f},
        {26.0f, -30.0f},
        {-30.0f, 16.0f},
        {5.0f, -20.0f}
    };

    for(int i = 0; i < 10; i++)
    {
        float x = arbre[i][0];
        float y = arbre[i][1];

        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation(Vector3D(x, y, 0.0f));

        
        myEngine.setFlatColor(0.60f, 0.35f, 0.15f); //ttronc 
        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation(Vector3D(0.0f, 0.0f, 3.0f));
        myEngine.mvMatrixStack.addHomothety(Vector3D(1.0f, 1.0f, 5.0f));
        myEngine.updateMvMatrix();
        meshCube->draw();
        myEngine.mvMatrixStack.popMatrix();

        
        myEngine.setFlatColor(0.95f, 0.95f, 0.95f); //feuilles bas
        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation(Vector3D(0.0f, 0.0f, 7.0f));
        myEngine.mvMatrixStack.addHomothety(Vector3D(5.0f, 5.0f, 2.5f));
        myEngine.updateMvMatrix();
        meshCube->draw();
        myEngine.mvMatrixStack.popMatrix();

    
        myEngine.mvMatrixStack.pushMatrix(); //feuilles milieu
        myEngine.mvMatrixStack.addTranslation(Vector3D(0.0f, 0.0f, 9.5f));
        myEngine.mvMatrixStack.addHomothety(Vector3D(4.0f, 4.0f, 2.0f));
        myEngine.updateMvMatrix();
        meshCube->draw();
        myEngine.mvMatrixStack.popMatrix();

        
        myEngine.mvMatrixStack.pushMatrix();//feulles haut
        myEngine.mvMatrixStack.addTranslation(Vector3D(0.0f, 0.0f, 11.5f));
        myEngine.mvMatrixStack.addHomothety(Vector3D(2.5f, 2.5f, 2.0f));
        myEngine.updateMvMatrix();
        meshCube->draw();
        myEngine.mvMatrixStack.popMatrix();

        myEngine.mvMatrixStack.popMatrix();
    }

    myEngine.mvMatrixStack.popMatrix();
}