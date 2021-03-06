#include "camera.h"

Camera::Camera() : m_phi(0.0), m_theta(0.0), m_orientation(), m_axeVertical(0, 0, 1), m_deplacementLateral(), m_position(), m_pointCible()
{

}

Camera::Camera(Vec3 position, Vec3 pointCible, Vec3 axeVertical) : m_phi(-35.26), m_theta(-135), m_orientation(0,0,0), m_axeVertical(axeVertical),
    m_deplacementLateral(), m_position(position), m_pointCible(pointCible), xrel(0.0), yrel(0.0)
{

}

Camera::Camera(Vec3 position, Vec3 pointCible) : m_phi(-35.26), m_theta(-135), m_orientation(),
    m_deplacementLateral(), m_position(position), m_pointCible(pointCible), firstPress(true)
{

}

Camera::~Camera()
{

}

/*
 * Récupère la position de la caméra.
 */
Vec3 Camera::getPosition()
{
    return this->m_position;
}

/*
 * Récupère le point ciblé par la caméra.
 */
Vec3 Camera::getPointCible()
{
    return this->m_pointCible;
}

/*
 * Récupère l'axe vertical de la caméra.
 */
Vec3 Camera::getAxeVertical()
{
    return this->m_axeVertical;
}

/*
 * Pour orienter la caméra dans l'axe désigné par la souris.
 */
void Camera::orienter(int xRel, int yRel)
{
    // calcul des angles

    m_phi += -yRel * 0.08;
    m_theta += -xRel * 0.08;

    if(m_phi > 89.0)
            m_phi = 89.0;

    else if(m_phi < -89.0)
            m_phi = -89.0;

    // Conversion des angles en radian

    float phiRadian = m_phi * M_PI / 180;
    float thetaRadian = m_theta * M_PI / 180;

    // Calcul des coordonnées sphériques

    m_orientation.x = cos(phiRadian) * sin(thetaRadian);
    m_orientation.y = sin(phiRadian);
    m_orientation.z = cos(phiRadian) * cos(thetaRadian);


    // Calcul de la normale

    m_deplacementLateral = m_axeVertical.crossProduct(m_orientation);
    m_deplacementLateral.normalize();

    // Calcul du point ciblé

    m_pointCible = m_position.operator +(m_orientation);
}

void Camera::deplacerAvant()
{

    // Avancée de la caméra

    m_position = m_position + m_orientation* 0.08f;
    m_pointCible = m_position + m_orientation;

}

void Camera::deplacerArriere()
{

    // Recul de la caméra

    m_position = m_position - m_orientation* 0.08f;
    m_pointCible = m_position + m_orientation;

}

void Camera::deplacerGauche()
{
    // Deplacement gauche

    m_position = m_position + m_deplacementLateral* 0.005f;
    m_pointCible = m_position + m_orientation;
}

void Camera::deplacerDroite()
{
    // Deplacement droite
    m_position = m_position - m_deplacementLateral* 0.005f;
    m_pointCible = m_position + m_orientation;

}

GLuint Camera::getXrel(){
    return this->xrel;
}

void Camera::setXrel(GLuint xrel){
    this->xrel = xrel;
}

GLuint Camera::getYrel(){
    return this->yrel;
}

void Camera::setYrel(GLuint yrel){
    this->yrel = yrel;
}


bool Camera::isFirstPress(){
    return this->firstPress;
}

void Camera::setFirstPress(bool booleen){
    this->firstPress = booleen;
}
