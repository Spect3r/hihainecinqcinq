#ifndef PARTICLEGENERATOR_H
#define PARTICLEGENERATOR_H

#include "Object3D.h"
#include <vector>
using namespace std;
#include "Vectors.h"

class ParticleGenerator : public Object3D
{


public:
    ParticleGenerator();
    ~ParticleGenerator();

    int initializeParticles();
    int drawParticles();
    //int tabIndices[];
protected :
    void drawShape();
    GLuint tabIndices[MAX_PARTICLES];
    Vec3 tabPositions[MAX_PARTICLES];
    Vec3 tabColors[MAX_PARTICLES];


};

#endif // PARTICLEGENERATOR_H
