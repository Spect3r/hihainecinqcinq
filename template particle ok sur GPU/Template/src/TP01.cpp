#include "TP01.h"


#include "Shapes/Basis.h"
#include "Shapes/particlegenerator.h"
#include "Shapes/camera.h"

#include <QDesktopWidget>
#include <QMainWindow>

#include <iostream>

using namespace std;


GLfloat angle1 = 30.0f;
GLfloat angle2 = 20.0f;

const GLfloat g_AngleSpeed = 10.0f;


Basis* g_Basis;
ParticleGenerator* g_ParticleGenerator;
Camera* g_Camera;


TP01::TP01()
{
	setWindowTitle(trUtf8("IN55-TP01"));
    setFixedSize(1200,800);
    g_Basis = new Basis( 10.0 );
    g_ParticleGenerator = new ParticleGenerator();
    g_Camera = new Camera(Vec3(0,5,5),Vec3(0,0,0),Vec3(0,1,0));
}


TP01::~TP01()
{
    delete g_Basis;
    delete g_ParticleGenerator;
}


bool
TP01::initializeObjects()
{
	// Fond gris
	glClearColor( 0.2f, 0.2f, 0.2f, 1.0f );
	glEnable( GL_DEPTH_TEST );

    // Initialisation des particules
    g_ParticleGenerator->initializeParticles();

	// Chargement des shaders
    createShader( "/Users/Julien/Documents/UTBM/IN55/Projet/template/color/color" );

    cout << "Shader color: ";
    if (useShader( "color" ))
    {
        cout << "Loaded!" << endl;
    }
    else
    {
        cout << "NOT Loaded!" << endl;
    }


	return true;
}



void
TP01::render()
{
    // Rendu des objets
	pushMatrix();
		rotate( angle1, 0, 1, 0 );
		rotate( angle2, 1, 0, 0 );

        g_Basis->draw();
        g_ParticleGenerator->drawParticles();
        g_ParticleGenerator->draw();
	popMatrix();

    // Initialisation de la caméra
    lookAt( g_Camera->getPosition().x, g_Camera->getPosition().y, g_Camera->getPosition().z, g_Camera->getPointCible().x, g_Camera->getPointCible().y, g_Camera->getPointCible().z, 0,1,0);
}


void
TP01::keyPressEvent( QKeyEvent* event )
{
	switch( event->key())
	{
		case Qt::Key_Escape:
			close();
			break;

		case Qt::Key_Left:
            g_Camera->deplacerGauche();
			break;

		case Qt::Key_Right:
            g_Camera->deplacerDroite();
			break;

		case Qt::Key_Up:
            g_Camera->deplacerAvant();
			break;

		case Qt::Key_Down:
            g_Camera->deplacerArriere();
            break;

		case Qt::Key_R:
			angle1 = angle2 = 0.0f;
			break;
	}
}

void
TP01::mouseMoveEvent(QMouseEvent *event)
{
    g_Camera->xrel = event->x() - g_Camera->xrel;
    g_Camera->yrel = event->y() - g_Camera->yrel;

    g_Camera->orienter(g_Camera->xrel,g_Camera->yrel);
    g_Camera->xrel = event->x();
    g_Camera->yrel = event->y();
    //cout<<"xrel : "<<g_Camera->xrel<<"yrel : "<< g_Camera->yrel<<endl;
}

void
TP01::mousePressEvent(QMouseEvent *event)
{
    if (g_Camera->firstPress == false)
    {
        g_Camera->xrel = event->x();
        g_Camera->yrel = event->y();
    }
    else
    {
        g_Camera->xrel = 600;
        g_Camera->yrel = 400;
        g_Camera->firstPress = false;
    }
}



