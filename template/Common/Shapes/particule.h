#ifndef PARTICULE_H
#define PARTICULE_H

#include "Object3D.h"
#include "Vectors.h"

class Particule //: public Object3D
{
public:
    Particule();
    virtual ~Particule();
   // double myRand(double min, double max);
    //int FindUnusedParticle();




protected :
   /* void drawShape();
    void drawShape( const char* shader_name );*/

public :
    bool active; // Active (1=Oui/0=Non)
    GLdouble life; // Durée de vie
    GLdouble fade; // Vitesse de disparition
    /*GLfloat tabColors[]; // Valeurs RGB pour la couleur
    GLfloat tabVertices[]; // nos vertices
    GLuint tabIndices[];
    GLuint tabIndices2[];*/
    Vec3 position; // Position
    Vec3 velocity;
    Vec3 gravity;
    //vector<float> color;
    Vec3 color;
};

#endif // PARTICULE_H
