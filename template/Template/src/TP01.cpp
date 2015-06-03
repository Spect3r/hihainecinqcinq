#include "TP01.h"


#include "Shapes/Basis.h"
#include "Shapes/particule.h"
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
Particule* g_Particule;
ParticleGenerator* g_ParticleGenerator;
Camera* g_Camera;


TP01::TP01()
{
	setWindowTitle(trUtf8("IN55-TP01"));
    setFixedSize(1200,800);
    g_Basis = new Basis( 10.0 );
   // g_Particule = new Particule();
    g_ParticleGenerator = new ParticleGenerator();
    g_Camera = new Camera(Vec3(0,50,30),Vec3(0,0,0),Vec3(0,0,1));
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
    //lookAt( g_Camera->getPosition().x, g_Camera->getPosition().y, g_Camera->getPosition().z, g_Camera->getPointCible().x, g_Camera->getPointCible().y, g_Camera->getPointCible().z, g_Camera->getAxeVertical().x, g_Camera->getAxeVertical().y, g_Camera->getAxeVertical().z );

    //cout << "position : " << endl << "x : " <<  g_Camera->getPosition().x << endl << "y : " <<  g_Camera->getPosition().x << endl << "z : " << g_Camera->getPosition().z << endl;
    //cout << "cible : " << endl << "x : " <<  g_Camera->getPointCible().x << endl << "y : " <<  g_Camera->getPointCible().x << endl << "z : " << g_Camera->getPointCible().z << endl;
    //cout << "Axe vertical : " << endl << "x : " <<  g_Camera->getAxeVertical().x << endl << "y : " <<  g_Camera->getAxeVertical().x << endl << "z : " << g_Camera->getAxeVertical().z << endl;
    // Rendu des objets
	pushMatrix();
		rotate( angle1, 0, 1, 0 );
		rotate( angle2, 1, 0, 0 );

        g_Basis->draw();
        //g_Particule->draw();
        //std::cout<<"Essai draw particule";
        g_ParticleGenerator->drawParticles();
        //std::cout<<" end Essai draw particule";
        g_ParticleGenerator->draw();
	popMatrix();

   // lookAt( g_Camera->getPosition().x, g_Camera->getPosition().y, g_Camera->getPosition().z, g_Camera->getPointCible().x, g_Camera->getPointCible().y, g_Camera->getPointCible().z, g_Camera->getAxeVertical().x, g_Camera->getAxeVertical().y, g_Camera->getAxeVertical().z);
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
           // g_Camera->deplacerGauche();
			break;

		case Qt::Key_Right:
            angle1 += g_AngleSpeed;
            //g_Camera->deplacerDroite();
			break;

		case Qt::Key_Up:
            angle2 -= g_AngleSpeed;
            //g_Camera->deplacerAvant();
			break;

		case Qt::Key_Down:
            angle2 += g_AngleSpeed;
            //lookAt( 0, 5, 30, 0, 0, 0 );
            //g_Camera->deplacerArriere();
            //lookAt( g_Camera->getPosition().x, g_Camera->getPosition().y, g_Camera->getPosition().z, g_Camera->getPointCible().x, g_Camera->getPointCible().y, g_Camera->getPointCible().z, g_Camera->getAxeVertical().x, g_Camera->getAxeVertical().y, g_Camera->getAxeVertical().z);
			break;

		case Qt::Key_R:
			angle1 = angle2 = 0.0f;
			break;
	}
}

void
TP01::mouseMoveEvent(QMouseEvent *event)
{


   // cout<<"Mouse position : x : "<<event->pos().x<<"y : "<<event->pos().y<<endl;
    int x = (int) event->x();
    int y = (int) event->y();
    int xrel = x - 600;
    int yrel = y - 400;
    //g_Camera->orienter(event->pos().x, event->pos().y);
    //g_Camera->orienter(xrel,yrel);
    //cout<<"xinit : "<<xinit<<"yinit : "<< yinit<<endl;
    cout<<"xrel : "<<xrel<<"yrel : "<< yrel<<endl;
}

void
TP01::mousePressEvent(QMouseEvent *event)
{
    int xinit = (int) event->x();
    int yinit = (int) event->y();
    cout<<"hehe"<<endl;
}




