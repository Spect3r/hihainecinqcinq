#ifndef PARTICLEGENERATOR_H
#define PARTICLEGENERATOR_H

#include "Object3D.h"

class ParticleGenerator : public Object3D
{

public:
    ParticleGenerator();
    ~ParticleGenerator();

    int initializeParticles();
    int drawParticles();
    int tabIndices[];
protected :
    void drawShape();

};

#endif // PARTICLEGENERATOR_H
