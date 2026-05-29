#include "rails.hpp"

extern IndexedMesh* meshCube;
extern IndexedMesh *meshCylinder;

std::vector<Rail> CreateRailPath(GridParam par)
{
    std::vector<Rail> rail_path;

    std::vector<Position> &p = par.path;
    size_t size = p.size();

    for (size_t i = 0; i < size; i++)
    {
        Rail r;

        r.pos = p[i];
        r.type = DROIT;
        r.angle = 0;
        // parametres de base pour éviter les soucis

        size_t i_prev = (i == 0) ? size - 1 : i - 1;
        size_t i_next = (i == size - 1) ? 0 : i + 1;

        Position prev = p[i_prev];
        Position cur = p[i];
        Position next = p[i_next];

        int dx1 = cur.x - prev.x;
        int dy1 = cur.y - prev.y;

        int dx2 = next.x - cur.x;
        int dy2 = next.y - cur.y;
        // pour rendre la suite plus propre

        if (dy1 == 0 && dy2 == 0) r.angle = M_PI_2;

        else if (dx1 == 0 && dx2 == 0) r.angle = 0; // utile pour pas avoir des rails courbes de partout

        else
        {
            r.type = COURBE;

            if ((dx1 == 1 && dy2 == -1) || (dy1 == 1 && dx2 == -1)) r.angle = M_PI_2;
            else if ((dy1 == -1 && dx2 == 1) || (dx1 == -1 && dy2 == 1)) r.angle = -M_PI_2; 
            else if ((dx1 == -1 && dy2 == -1) || (dy1 == 1 && dx2 == 1)) r.angle = M_PI;
            // sinon angle a 0 
        }

        rail_path.push_back(r);
    }

    return rail_path;
}

void drawStraightRail(GLBI_Engine myEngine)
{

    float center = taille_case / 2;
    myEngine.setFlatColor(0.6f, 0.6f, 0.6f); // gris
    myEngine.mvMatrixStack.addRotation(0, Vector3D(0, 0, 1));
    myEngine.mvMatrixStack.addTranslation(Vector3D(0, 0, 0));

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({center - posx_rail1, 0.0f, 2 * rr + sr / 2});
    myEngine.mvMatrixStack.addHomothety(Vector3D(sr, taille_case, sr));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({center - posx_rail2, 0.0f, 2 * rr + sr / 2});
    myEngine.mvMatrixStack.addHomothety(Vector3D(sr, taille_case, sr));
    myEngine.updateMvMatrix();
    meshCube->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.setFlatColor(0.4f, 0.25f, 0.15f); // marron

    float positionsY[5] = {-2.0f, -1.0f, 0.0f, 1.0f, 2.0f};

    for (int i = 0; i < 5; ++i)
    {
        myEngine.mvMatrixStack.pushMatrix();

        myEngine.mvMatrixStack.addRotation(M_PI_2, Vector3D(0, 0, 1));                            // on rotationne le bois pour etre perpendiculaire au rail
        myEngine.mvMatrixStack.addTranslation({positionsY[i] * rr * 10, -longueur_bois / 2, rr}); // on le place bien (j'espere)

        myEngine.updateMvMatrix();
        meshCylinder->draw();
        myEngine.mvMatrixStack.popMatrix();
    }
}

void drawCurvedRail(GLBI_Engine myEngine)
{

    int nb_segments = 15;
    float rayon_rail1 = 10.0f - posx_rail1;
    float rayon_rail2 = 10.0f - posx_rail2;

    float longueur_micro_cube1 = (M_PI * rayon_rail1 / 2.0f) / nb_segments;
    float longueur_micro_cube2 = (M_PI * rayon_rail2 / 2.0f) / nb_segments;

    myEngine.mvMatrixStack.pushMatrix();

    myEngine.mvMatrixStack.addRotation(M_PI_2, Vector3D(0, 0, 1));
    myEngine.mvMatrixStack.addTranslation(Vector3D(5.0f, 5.0f, 0.f)); // pour bien centrer le bloc, on y touche pas

    myEngine.setFlatColor(0.6f, 0.6f, 0.6f);

    for (int i = 0; i < nb_segments; ++i)
    {
        float alpha = (float)i / (float)(nb_segments - 1) * M_PI_2;

        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addRotation(alpha, Vector3D(0, 0, 1));
        myEngine.mvMatrixStack.addTranslation({-rayon_rail1, longueur_micro_cube1 / 2.0f, 2 * rr + sr / 2});
        myEngine.mvMatrixStack.addHomothety(Vector3D(sr, longueur_micro_cube1, sr));
        myEngine.updateMvMatrix();
        meshCube->draw();
        myEngine.mvMatrixStack.popMatrix();

        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addRotation(alpha, Vector3D(0, 0, 1));
        myEngine.mvMatrixStack.addTranslation({-rayon_rail2, longueur_micro_cube2 / 2.0f, 2 * rr + sr / 2});
        myEngine.mvMatrixStack.addHomothety(Vector3D(sr, longueur_micro_cube2, sr));
        myEngine.updateMvMatrix();
        meshCube->draw();
        myEngine.mvMatrixStack.popMatrix();
    }

    myEngine.setFlatColor(0.4f, 0.25f, 0.15f);
    float rayon_moyen_ballast = (rayon_rail1 + rayon_rail2) / 2.0f;

    for (int i = 0; i < 3; ++i)
    {
        float alpha = (float)(i + 1) * (M_PI_2 / 4.0f);

        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addRotation(alpha, Vector3D(0, 0, 1));
        myEngine.mvMatrixStack.addTranslation({-rayon_moyen_ballast, 0.0f, 0.0f});

        myEngine.mvMatrixStack.addRotation(M_PI_2, Vector3D(0, 0, 1));
        myEngine.mvMatrixStack.addTranslation({0.0f, -longueur_bois / 2.0f, rr});

        myEngine.updateMvMatrix();
        meshCylinder->draw();
        myEngine.mvMatrixStack.popMatrix();
    }

    myEngine.mvMatrixStack.popMatrix();
}

void drawRail(Rail r, GLBI_Engine myEngine)
{

    myEngine.mvMatrixStack.pushMatrix();

    Vector3D pos = Vector3D(r.pos.x*10, r.pos.y*10, 0);
    myEngine.mvMatrixStack.addTranslation(pos); // pour le placer sur la grille
    myEngine.mvMatrixStack.addRotation(r.angle, Vector3D(0, 0, 1));

    if (r.type == DROIT)
        drawStraightRail(myEngine);
    if (r.type == COURBE)
        drawCurvedRail(myEngine);

    myEngine.mvMatrixStack.popMatrix();
}