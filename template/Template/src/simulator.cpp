﻿#include "simulator.h"


#include "Shapes/Basis.h"
#include "Shapes/particlegenerator.h"
#include "Shapes/camera.h"

#include <QDesktopWidget>
#include <QMainWindow>

#include <iostream>

using namespace std;


GLfloat angle1 = 30.0f;
GLfloat angle2 = 20.0f;

GLint fontaineShader;
GLint artificeShader;
GLint currentShader = fontaineShader;

const GLfloat g_AngleSpeed = 10.0f;


Basis* g_Basis;
ParticleGenerator* g_ParticleGenerator;
Camera* g_Camera;


simulator::simulator()
{
    setWindowTitle(trUtf8("Simulateur de particules - IN55"));
    setFixedSize(1200,800);
    g_Basis = new Basis( 10.0 );
    g_ParticleGenerator = new ParticleGenerator();
    g_Camera = new Camera(Vec3(0,5,5),Vec3(0,0,0),Vec3(0,1,0));
}


simulator::~simulator()
{
    delete g_Basis;
    delete g_ParticleGenerator;
}


bool
simulator::initializeObjects()
{
	// Fond gris
	glClearColor( 0.2f, 0.2f, 0.2f, 1.0f );
	glEnable( GL_DEPTH_TEST );

    // Initialisation des particules
    g_ParticleGenerator->initializeParticles();

	// Chargement des shaders
    fontaineShader = createShader( "/Users/Julien/Documents/UTBM/IN55/Projet/template/color/color" );
    artificeShader = createShader( "/Users/Julien/Documents/UTBM/IN55/Projet/template/color/artifice" );

    cout << "Shader fontaine: ";
    if (useShader( "color" ))
    {
        cout << "Loaded!" << endl;
    }
    else
    {
        cout << "NOT Loaded!" << endl;
    }

    cout << "Shader artifice : ";
    if (useShader( "artifice" ))
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
simulator::render()
{
    // Rendu des objets
	pushMatrix();
		rotate( angle1, 0, 1, 0 );
		rotate( angle2, 1, 0, 0 );

        //g_Basis->draw();
        g_ParticleGenerator->drawParticles();
        g_ParticleGenerator->draw(currentShader);
	popMatrix();

    // Initialisation de la caméra
    lookAt( g_Camera->getPosition().x, g_Camera->getPosition().y, g_Camera->getPosition().z, g_Camera->getPointCible().x, g_Camera->getPointCible().y, g_Camera->getPointCible().z, 0,1,0);
}


void
simulator::keyPressEvent( QKeyEvent* event )
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
        case Qt::Key_F1:
            currentShader = fontaineShader;
            break;
        case Qt::Key_F2:
            currentShader = artificeShader;
            break;
	}
}

void
simulator::mouseMoveEvent(QMouseEvent *event)
{
    g_Camera->setXrel(event->x() - g_Camera->getXrel());
    g_Camera->setYrel(event->y() - g_Camera->getYrel());

    g_Camera->orienter(g_Camera->getXrel(),g_Camera->getYrel());
    g_Camera->setXrel(event->x());
    g_Camera->setYrel(event->y());
}

void
simulator::mousePressEvent(QMouseEvent *event)
{
    if (g_Camera->isFirstPress() == false)
    {
        g_Camera->setXrel(event->x());
        g_Camera->setYrel(event->y());
    }
    else
    {
        g_Camera->setXrel(600);
        g_Camera->setYrel(400);
        g_Camera->setFirstPress(false);
    }
}


