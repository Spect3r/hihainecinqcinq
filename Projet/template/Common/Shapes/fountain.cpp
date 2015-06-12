#include "fountain.h"
#include <cstdlib>
#include <iostream>

Fountain::Fountain()
{
}

Fountain::~Fountain()
{

}

double Fountain::myRand(double min, double max)
{
    return (double) (min + ((float) rand() / RAND_MAX * (max - min + 1.0)));
}

int Fountain::initializeParticles()
{

    for(int i=0; i<MAX_PARTICLES; i++)   // Boucle sur toutes les particules
    {
        tabIndices[i] = i;
        tabLife[i] = 1.0; // Maximum de vie

        tabColors[i].x = 0.41;
        tabColors[i].y = 0.5;
        tabColors[i].z = 0.71;

        tabFade[i] = myRand(0.01,0.1);  // Vitesse de disparition aléatoire

        // Initialisation à l'origine
        tabPositions[i].x = 0.0;
        tabPositions[i].y = 0.0;
        tabPositions[i].z = 0.0;

        // Calcul Theta
        theta = myRand(1.0, 360.0);

        // Vitesse aléatoire
        tabVelocities[i].x = myRand(0.1,1.5)*cos(theta);
        tabVelocities[i].y = myRand(15.0,20.0);
        tabVelocities[i].z = myRand(0.1,1.5)*sin(theta);

        tabSize[i] = myRand(0.5,1.5);


    }
    return 0;    // Initialisation OK
}

int Fountain::drawParticles()
{   for(int i=0; i<MAX_PARTICLES; i++) // Pour chaque particule
    {
        if(tabLife[i] > 0)
        {  
            tabLife[i] -= tabFade[i];
        }
        else
        {
            // Calcul Theta
            theta = myRand(1.0, 360.0);

            tabLife[i] = 1.0;
            tabVelocities[i].x = myRand(0.1,1.5)*cos(theta);
            tabVelocities[i].y = myRand(15.0,20.0);
            tabVelocities[i].z = myRand(0.1,1.5)*sin(theta);

            tabSize[i] = myRand(0.5,2);
        }
    }

    return 0; // Dessin OK
}

void
Fountain::drawShape()
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

   glDrawElements( GL_POINTS, MAX_PARTICLES, GL_UNSIGNED_INT, tabIndices ); // trace tous les points
   glDisableVertexAttribArray( var1 );
   glDisableVertexAttribArray( var2 );
   glDisableVertexAttribArray( var3 );
   glDisableVertexAttribArray( var4 );
   glDisableVertexAttribArray( var5 );
   glDisableVertexAttribArray( var6 );
}

void
Fountain::drawShape(const char* shader_name)
{

}
