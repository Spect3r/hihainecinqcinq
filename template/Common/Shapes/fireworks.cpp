#include "fireworks.h"
#include <cstdlib>
#include <iostream>

Fireworks::Fireworks()
{
}

Fireworks::~Fireworks()
{

}

/*
 * Tracer du baton de la torche
*/
void Fireworks::drawStick()
{

        glBegin(GL_QUADS);

        glColor3ub(255,0,0);
        glVertex3d(-0.1,0,0);
        glVertex3d(-0.1,-4,0);
        glVertex3d(0.1,-4,0);
        glVertex3d(0.1,0,0);
        glEnd();

        glFlush();
}

/*
 * Fonction permettant d'obtenir une valeur comprise entre deux valeurs passées en paramètre
*/
double Fireworks::myRand(double min, double max)
{
    return (double) (min + ((float) rand() / RAND_MAX * (max - min + 1.0)));
}

int Fireworks::initializeParticles()
{

    for(int i=0; i<MAX_PARTICLES; i++)   // Boucle sur toutes les particules
    {
        tabIndices[i] = i; //initialisation du tableau d'indices
        tabLife[i] = 1.0; // Maximum de vie



        tabFade[i] = myRand(0.03,0.04);  // Vitesse de disparition aléatoire

        // Initialisation des particules à l'origine
        tabPositions[i].x = 0.0;
        tabPositions[i].y = 0.0;
        tabPositions[i].z = 0.0;

        // Calcul de Theta
        theta = myRand(1.0, 360.0);

        // Vitesse aléatoire
        tabVelocities[i].x = myRand(0.1,4)*cos(theta);
        tabVelocities[i].y = myRand(15.0,20.0);
        tabVelocities[i].z = myRand(0.1,4)*sin(theta);

        tabSize[i] = myRand(5,10); // taille aléatoire pour chaque particule

        tabTransparency[i] = 1.0;


    }
    return 0;    // Initialisation OK
}

/*
 * Fonction de mise à jour des particules
*/
int Fireworks::drawParticles()
{   for(int i=0; i<MAX_PARTICLES; i++) // Pour chaque particule
    {
        if(tabLife[i] > 0)
        {
            tabLife[i] -= tabFade[i];

             if(tabColors[i].x < 1.0)
                 tabColors[i].x += 0.05;

             else
                 tabColors[i].x = 1.0;

             if(tabColors[i].y > 0.0)
                 tabColors[i].y -= 0.05;

             else
                 tabColors[i].y = 0.0;



        }
        else
        {
            // Calcul Theta
            theta = myRand(1.0, 360.0);

            tabLife[i] = 1.0;
            tabVelocities[i].x = myRand(5.0,6.0)*cos(theta);
            tabVelocities[i].y = myRand(20.0, 40.0);
            tabVelocities[i].z = myRand(5.0,6.0)*sin(theta);
            tabSize[i] = myRand(5,10);

            tabColors[i].x = 1.0;
            tabColors[i].y = 1.0;
        }
    }

    return 0; // Dessin OK
}

void
Fireworks::drawShape()
{
    glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);

   GLint var1 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "position" );
   glEnableVertexAttribArray( var1 );
   glVertexAttribPointer( var1, 3, GL_FLOAT, GL_FALSE, 0, tabPositions );

   GLint var2 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "color" );
   glEnableVertexAttribArray( var2 );
   glVertexAttribPointer( var2, 3, GL_FLOAT, GL_FALSE, 0, tabColors );

   GLint var3 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "velocity" );
   glEnableVertexAttribArray( var3 );
   glVertexAttribPointer( var3, 3, GL_FLOAT, GL_FALSE, 0, tabVelocities );

   GLfloat var4 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "life" );
   glEnableVertexAttribArray( var4 );
   glVertexAttribPointer( var4, 1, GL_FLOAT, GL_FALSE, 0, tabLife );

   GLfloat var5 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "fade" );
   glEnableVertexAttribArray( var5 );
   glVertexAttribPointer( var5, 1, GL_FLOAT, GL_FALSE, 0, tabFade );

   GLfloat var6 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "size" );
   glEnableVertexAttribArray( var6 );
   glVertexAttribPointer( var6, 1, GL_FLOAT, GL_FALSE, 0, tabSize );

   GLfloat var7 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "transparency" );
   glEnableVertexAttribArray( var7 );
   glVertexAttribPointer( var7, 1, GL_FLOAT, GL_FALSE, 0, tabTransparency );

   glDrawElements( GL_POINTS, MAX_PARTICLES, GL_UNSIGNED_INT, tabIndices ); // trace tous les points

   glDisableVertexAttribArray( var1 );
   glDisableVertexAttribArray( var2 );
   glDisableVertexAttribArray( var3 );
   glDisableVertexAttribArray( var4 );
   glDisableVertexAttribArray( var5 );
   glDisableVertexAttribArray( var6 );
   glDisableVertexAttribArray( var7 );
}

void
Fireworks::drawShape(const char* shader_name)
{

}
