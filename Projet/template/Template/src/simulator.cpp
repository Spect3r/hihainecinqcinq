﻿#include "simulator.h"


#include "Shapes/Basis.h"
#include "Shapes/fountain.h"
#include "Shapes/camera.h"
#include "Shapes/torch.h"
#include "Shapes/tornado.h"

#include <QDesktopWidget>
#include <QMainWindow>

#include <iostream>

using namespace std;


GLfloat angle1 = 30.0f;
GLfloat angle2 = 20.0f;

GLint fountainShader;
GLint torchShader;
GLint tornadoShader;
GLint currentShader = fountainShader;

const GLfloat g_AngleSpeed = 10.0f;


Basis* g_Basis;
Fountain* g_Fountain;
Torch* g_Torch;
Tornado* g_Tornado;
Camera* g_Camera;


Simulator::Simulator()
{
    setWindowTitle(trUtf8("Simulateur de particules - IN55"));
    setFixedSize(1200,800);
    g_Basis = new Basis( 10.0 );
    g_Fountain = new Fountain();
    g_Torch = new Torch();
    g_Tornado = new Tornado();
    g_Camera = new Camera(Vec3(1,0.5,1.5),Vec3(0,0.6,0),Vec3(0,1,0));
}


Simulator::~Simulator()
{
    delete g_Basis;
    delete g_Fountain;
    delete g_Torch;
    delete g_Tornado;
}


bool
Simulator::initializeObjects()
{
	// Fond gris
	glClearColor( 0.2f, 0.2f, 0.2f, 1.0f );
	glEnable( GL_DEPTH_TEST );

    // Initialisation des particules
    g_Fountain->initializeParticles();
    g_Torch->initializeParticles();
    g_Tornado->initializeParticles();

	// Chargement des shaders
    fountainShader = createShader("/Users/Julien/Documents/UTBM/IN55/Projet/Projet/template/Template/release/Shaders/fountain");
    torchShader = createShader("/Users/Julien/Documents/UTBM/IN55/Projet/Projet/template/Template/release/Shaders/torch");
    tornadoShader = createShader("/Users/Julien/Documents/UTBM/IN55/Projet/Projet/template/Template/release/Shaders/tornado");

    cout << "Shader fountain: ";
    if (useShader( "fountain" ))
    {
        cout << "Loaded!" << endl;
    }
    else
    {
        cout << "NOT Loaded!" << endl;
    }

    cout << "Shader torch : ";
    if (useShader( "torch" ))
    {
        cout << "Loaded!" << endl;
    }
    else
    {
        cout << "NOT Loaded!" << endl;
    }

    cout << "Shader tornado : ";
    if (useShader( "tornado" ))
    {
        cout << "Loaded!" << endl;
    }
    else
    {
        cout << "NOT Loaded!" << endl;
    }

    QPixmap pixmap( "/Users/Julien/Documents/UTBM/IN55/Projet/template/Template/release/yes.png" );

    const int NBR_TEXTURES = MAX_PARTICLES;
    GLuint texId[NBR_TEXTURES];
    glGenTextures( NBR_TEXTURES, texId );
    // Initialisation de la première texture stockée dans l'unité de texture #0
    // glActiveTexture( GL_TEXTURE0 );
    glBindTexture( GL_TEXTURE_2D, texId[0] );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexImage2D( GL_TEXTURE_2D,   0,   GL_RGBA, pixmap.width(), pixmap.height(), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixmap.toImage().bits() );


	return true;
}



void
Simulator::render()
{
    // Rendu des objets
	pushMatrix();
		rotate( angle1, 0, 1, 0 );
		rotate( angle2, 1, 0, 0 );

        //g_Basis->draw();
        if(currentShader == fountainShader){
            g_Fountain->drawParticles();
            g_Fountain->draw(currentShader);
        }
        else if(currentShader == torchShader)
        {
            g_Torch->drawParticles();
            g_Torch->draw(currentShader);
            g_Torch->drawStick();
        }
        else if(currentShader == tornadoShader)
        {
            g_Tornado->drawParticles();
            g_Tornado->draw(currentShader);
        }
	popMatrix();

    // Mise à jour de la position de la caméra
    lookAt( g_Camera->getPosition().x, g_Camera->getPosition().y, g_Camera->getPosition().z, g_Camera->getPointCible().x, g_Camera->getPointCible().y, g_Camera->getPointCible().z, 0,1,0);
}


void
Simulator::keyPressEvent( QKeyEvent* event )
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
            currentShader = fountainShader;
            break;
        case Qt::Key_F2:
            currentShader = torchShader;
            break;
        case Qt::Key_F3:
            currentShader = tornadoShader;
        break;
	}
}

void
Simulator::mouseMoveEvent(QMouseEvent *event)
{
    g_Camera->setXrel(event->x() - g_Camera->getXrel());
    g_Camera->setYrel(event->y() - g_Camera->getYrel());

    g_Camera->orienter(g_Camera->getXrel(),g_Camera->getYrel());
    g_Camera->setXrel(event->x());
    g_Camera->setYrel(event->y());
}

void
Simulator::mousePressEvent(QMouseEvent *event)
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



