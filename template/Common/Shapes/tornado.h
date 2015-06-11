#ifndef TORNADO_H
#define TORNADO_H

#include "Object3D.h"
#include <vector>
using namespace std;
#include "Vectors.h"
#define MAX_PARTICLES 350000


class Tornado : public Object3D
{

public:
    Tornado();
    ~Tornado();

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
    GLfloat tabTheta[MAX_PARTICLES];

};

#endif // TORNADO_H
