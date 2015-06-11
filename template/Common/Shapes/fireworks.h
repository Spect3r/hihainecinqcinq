#ifndef FIREWORKS_H
#define FIREWORKS_H


#include "Object3D.h"
#include <vector>
using namespace std;
#include "Vectors.h"
#define MAX_PARTICLES 5


class Fireworks : public Object3D
{

public:
    Fireworks();
    ~Fireworks();

    int initializeParticles();
    int drawParticles();
    double myRand(double min, double max);
protected :
    void drawShape();
    void drawShape(const char* shader_name);
    GLuint tabIndices[4*MAX_PARTICLES];
    GLfloat tabVertices[12*MAX_PARTICLES];
    Vec3 tabVelocities[MAX_PARTICLES];
    GLfloat tabLife[MAX_PARTICLES];
    GLfloat tabFade[MAX_PARTICLES];
    GLfloat tabUv[8*MAX_PARTICLES];
    float theta;

};

#endif // FIREWORKS_H
