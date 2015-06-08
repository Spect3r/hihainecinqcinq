#ifndef PARTICLEGENERATOR_H
#define PARTICLEGENERATOR_H

#include "Object3D.h"
#include <vector>
using namespace std;
#include "Vectors.h"
#define MAX_PARTICLES 100000


class ParticleGenerator : public Object3D
{

public:
    ParticleGenerator();
    ~ParticleGenerator();

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

};

#endif // PARTICLEGENERATOR_H
