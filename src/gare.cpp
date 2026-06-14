#include "gare.hpp"

extern IndexedMesh *meshCube;
extern IndexedMesh *meshCylinder;
extern StandardMesh *meshCone;

extern GLBI_Texture signTexture;
extern GLBI_Texture brickTexture;
extern GLBI_Texture smallBrickTexture;

// -----------------------------------------------------
// UTILITAIRE PROPRE
// -----------------------------------------------------
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

static void drawCylinder(Vector3D pos, Vector3D size, float r, float g, float b, float rotationAngle = 0, Vector3D rotationPlan = Vector3D(0, 0, 1))
{
    myEngine.setFlatColor(r, g, b);

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(pos);
    myEngine.mvMatrixStack.addHomothety(size);
    myEngine.mvMatrixStack.addRotation(rotationAngle, rotationPlan);
    myEngine.updateMvMatrix();
    meshCylinder->draw();
    myEngine.mvMatrixStack.popMatrix();
}

static void drawCone(Vector3D pos, Vector3D size, float r, float g, float b, float rotationAngle = 0, Vector3D rotationPlan = Vector3D(0, 0, 1))
{
    myEngine.setFlatColor(r, g, b);

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(pos);
    myEngine.mvMatrixStack.addHomothety(size);
    myEngine.mvMatrixStack.addRotation(rotationAngle, rotationPlan);
    myEngine.updateMvMatrix();
    meshCone->draw();
    myEngine.mvMatrixStack.popMatrix();
}

void drawSiege()
{
    myEngine.setFlatColor(0.95f, 0.80f, 0.30f);

    // dossier
    drawBox(Vector3D(0.f, 4.4f, 4.5f),
            Vector3D(1.8f, 0.2f, 2.f),
            0.95f, 0.80f, 0.30f);

    // assise
    drawBox(Vector3D(0.f, 3.5f, 3.5f),
            Vector3D(1.8f, 2.f, 0.2f),
            0.95f, 0.80f, 0.30f);
}

void drawPoubelle(Vector3D pos)
{
    // CORPS
    drawCylinder(
        pos,
        Vector3D(5.f, 5.f, 0.3f),
        0.8f, 0.8f, 0.8f,
        M_PI_2, Vector3D(1, 0, 0)

    );

    // REBORD (cône inversé)
    drawCone(
        pos + Vector3D(0.f, 0.f, 1.8f),
        Vector3D(1.0f, 1.f, .6f),
        0.9f, 0.9f, 0.9f,
        -M_PI_2,
        Vector3D(1, 0, 0) // cône retourné
    );
}

void drawGare()
{
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(0, 10, 0.f));

    // sol gris
    drawBox(Vector3D(0.f, 1.f, 1.25f),
            Vector3D(10.f, 8.f, 2.5f),
            0.3f, 0.3f, 0.3f);

    // plafond
    drawBox(Vector3D(0.f, 1.f, 10.f),
            Vector3D(10.f, 8.f, 0.5f),
            0.3f, 0.3f, 0.3f);

    // lampe
    drawBox(Vector3D(0.f, 1.f, 9.7f),
            Vector3D(5.f, 2.f, 0.2f),
            0.8f, 0.8f, 0.3f);

    if (!flatLighting)
    {
        myEngine.setLightPosition(Vector4D(0.f, 1.f, 5.f, 1.f));
        myEngine.setLightIntensity(Vector3D(100.f, 100.f, 100.f));
    }

    // petit rebord blanc
    drawBox(Vector3D(0.f, -4.f, 2.f),
            Vector3D(10.f, 2.f, 1.f),
            0.9f, 0.9f, 0.9f);

    drawBox(Vector3D(0.f, 3.f, 3.f),
            Vector3D(10.f, 1.5f, 1.f),
            0.5f, 0.5f, 0.5f);

    // mur arrière (je peux pas utiliser la fonction a cause des textures)
    myEngine.activateTexturing(true);
    brickTexture.attachTexture();

    myEngine.setFlatColor(1.f, 1.f, 1.f);

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(0.f, 4.5f, 6.25f));
    myEngine.mvMatrixStack.addRotation(M_PI_2, Vector3D(0, 1, 0));
    myEngine.mvMatrixStack.addHomothety(Vector3D(7.5f, 1.f, 10.f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

    brickTexture.detachTexture();
    myEngine.activateTexturing(false);

    // petits murs sur le coté (la même)
    myEngine.activateTexturing(true);
    smallBrickTexture.attachTexture();

    myEngine.setFlatColor(1.f, 1.f, 1.f);

    // gauche
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(4.5f, 3.5f, 6.25f));
    myEngine.mvMatrixStack.addRotation(M_PI_2, Vector3D(0, 1, 0));
    myEngine.mvMatrixStack.addHomothety(Vector3D(7.5f, 2.5f, 1.f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

    // droite
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation(Vector3D(-4.5f, 3.5f, 6.25f));
    myEngine.mvMatrixStack.addRotation(M_PI_2, Vector3D(0, 1, 0));
    myEngine.mvMatrixStack.addHomothety(Vector3D(7.5f, 2.5f, 1.f));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

    smallBrickTexture.detachTexture();
    myEngine.activateTexturing(false);

    // panneau Chatelet les Halles
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

    // Siège
    for (float i = -2.5f; i < 3.f; i += 2.5f)
    {
        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation(Vector3D(i, -1.f, 0.f));
        myEngine.updateMvMatrix();

        drawSiege();

        myEngine.mvMatrixStack.popMatrix();
    }

    // panneaux exit
    drawBox(Vector3D(4.5f, 2.f, 8.f),
            Vector3D(1.f, 0.2f, 0.5f),
            0.5f, 0.9f, 0.5f);

    drawBox(Vector3D(-4.5f, 2.f, 8.f),
            Vector3D(1.f, 0.2f, 0.5f),
            0.5f, 0.9f, 0.5f);

    // ---------------- POUBELLE ----------------

    drawPoubelle(Vector3D(-3.5f, -0.5f, 2.f));

    myEngine.mvMatrixStack.popMatrix();
}