﻿#include "TP01.h"


#include "Shapes/Basis.h"
#include "Shapes/particule.h"
#include "Shapes/particlegenerator.h"

#include <iostream>

using namespace std;


GLfloat angle1 = 30.0f;
GLfloat angle2 = 20.0f;

const GLfloat g_AngleSpeed = 10.0f;


Basis* g_Basis;
Particule* g_Particule;
ParticleGenerator* g_ParticleGenerator;


TP01::TP01()
{
	setWindowTitle(trUtf8("IN55-TP01"));

    //g_Basis = new Basis( 10.0 );
   // g_Particule = new Particule();
    g_ParticleGenerator = new ParticleGenerator();
}


TP01::~TP01()
{
    delete g_Basis;
   // delete g_Particule;
    delete g_ParticleGenerator;
}


bool
TP01::initializeObjects()
{
	// Fond gris
	glClearColor( 0.2f, 0.2f, 0.2f, 1.0f );
	glEnable( GL_DEPTH_TEST );

    //ParticleGenerator particleGenerator;
    //cout << "initialise particule";
    g_ParticleGenerator->initializeParticles();
    //cout << "end initialise particule";

	// Chargement des shaders
    createShader( "/Users/Julien/Documents/UTBM/IN55/Projet/template/color/color" );
    //createShader( "/Users/Julien/Documents/UTBM/IN55/Projet/template/Template/release/Shaders/test" );

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


    //std::cout<<"debut render";
	// Initialisation de la caméra
	lookAt( 0, 5, 30, 0, 0, 0 );


	// Rendu des objets
	pushMatrix();
		rotate( angle1, 0, 1, 0 );
		rotate( angle2, 1, 0, 0 );

       // g_Basis->draw();
        //g_Particule->draw();
        //std::cout<<"Essai draw particule";
        g_ParticleGenerator->drawParticles();
        //std::cout<<" end Essai draw particule";
        g_ParticleGenerator->draw();
	popMatrix();
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
			angle1 -= g_AngleSpeed;
			break;

		case Qt::Key_Right:
			angle1 += g_AngleSpeed;
			break;

		case Qt::Key_Up:
			angle2 -= g_AngleSpeed;
			break;

		case Qt::Key_Down:
			angle2 += g_AngleSpeed;
			break;

		case Qt::Key_R:
			angle1 = angle2 = 0.0f;
			break;
	}
}
