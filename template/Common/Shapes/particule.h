#ifndef PARTICULE_H
#define PARTICULE_H

#include "Object3D.h"

class Particule : public Object3D
{
public:
    Particule();
    virtual ~Particule();
   // double myRand(double min, double max);

protected :
   // void drawShape();
    void drawShape( const char* shader_name );

private :
    bool active; // Active (1=Oui/0=Non)
    GLdouble life; // Durée de vie
    GLdouble fade; // Vitesse de disparition
    GLfloat tabColors[]; // Valeurs RGB pour la couleur
    GLfloat tabVertices[]; // nos vertices
    GLuint tabIndices[];
    GLdouble x, y, z; // Position
    GLdouble xi, yi, zi; // Vecteur de déplacement
    GLdouble xg, yg, zg; // Gravité
};

#endif // PARTICULE_H
