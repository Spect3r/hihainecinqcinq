#ifndef CAMERA_H
#define CAMERA_H

#include "Vectors.h"
#include <GL/gl.h>

class Camera
{
public:
    Camera();
    Camera(Vec3 position, Vec3 pointCible, Vec3 axeVertical);
    Camera(Vec3 position, Vec3 pointCible);
    ~Camera();
    void orienter(int xRel, int yRel);
    void deplacerAvant();
    void deplacerArriere();
    void deplacerGauche();
    void deplacerDroite();
    Vec3 getPosition();
    Vec3 getPointCible();
    Vec3 getAxeVertical();
    GLuint xrel;
    GLuint yrel;
    bool firstPress;

private:
    // Attributs d'orientation
    float m_phi;
    float m_theta;
    Vec3 m_orientation;

    // Attributs de déplacement
    Vec3 m_axeVertical;
    Vec3 m_deplacementLateral;

    //Pour fonction lookAt
    Vec3 m_position;
    Vec3 m_pointCible;

};

#endif // CAMERA_H
