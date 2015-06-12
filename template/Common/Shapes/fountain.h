#ifndef FOUNTAIN_H
#define FOUNTAIN_H

#include "Object3D.h"
#include <vector>
using namespace std;
#include "Vectors.h"
#define MAX_PARTICLES 100000


class Fountain : public Object3D
{

public:
    Fountain();
    ~Fountain();

    int initializeParticles();
    int drawParticles();
    double myRand(double min, double max);
protected :
    void drawShape();
    void drawShape(const char* shader_name);
    GLuint tabIndices[MAX_PARTICLES];
    Vec3 tabPositions[MAX_PARTICLES];
    Vec3 tabVelocities[MAX_PARTICLES];
    Vec3 tabColors[MAX_PARTICLES];
    GLfloat tabLife[MAX_PARTICLES];
    GLfloat tabFade[MAX_PARTICLES];
    GLfloat tabSize[MAX_PARTICLES];
    float theta;

};

#endif // FOUNTAIN_H
