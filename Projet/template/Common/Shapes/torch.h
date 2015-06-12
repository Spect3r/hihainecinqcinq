#ifndef TORCH_H
#define TORCH_H


#include "Object3D.h"
#include <vector>
using namespace std;
#include "Vectors.h"
#define MAX_PARTICLES 10000


class Torch : public Object3D
{

public:
    Torch();
    ~Torch();

    int initializeParticles();
    int drawParticles();
    void drawStick();
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
    GLfloat tabTransparency[MAX_PARTICLES];

    float theta;

};

#endif // TORCH_H
