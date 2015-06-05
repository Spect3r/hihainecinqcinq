#include "particlegenerator.h"
#include <cstdlib>
#include <iostream>

GLfloat time = 0;

ParticleGenerator::ParticleGenerator()
{
    for( GLuint i = 0; i < MAX_PARTICLES; i++ )
    {
        tabIndices[i] = i;
        tabColors[i].x = myRand(0.0, 1.0);
        tabColors[i].y = myRand(0.0, 1.0);
        tabColors[i].z = myRand(0.0, 1.0);
        tabPositions[i].x = 0.0;
        tabPositions[i].y = 0.0;
        tabPositions[i].z = 0.0;
    }

}

ParticleGenerator::~ParticleGenerator()
{

}

double ParticleGenerator::myRand(double min, double max)
{
    return (double) (min + ((float) rand() / RAND_MAX * (max - min + 1.0)));
}

ParticleGenerator::initializeParticles()
{

    for(int i=0; i<MAX_PARTICLES; i++)   // Boucle sur toutes les particules
    {

        tabLife[i] = 1.0; // Maximum de vie

        tabFade[i] = myRand(0.01,0.05);  // Vitesse de disparition aléatoire

        // Initialisation à l'origine
        tabPositions[i].x = 0.0;
        tabPositions[i].y = 0.0;
        tabPositions[i].z = 0.0;


        // Vitesse aléatoire
        tabVelocities[i].x = myRand(-3.0,3.0);
        tabVelocities[i].y = myRand(10.0,20.0); //myRand(-10.0,10.0);
        tabVelocities[i].z = myRand(-3.0,3.0);


    }
    return 0;    // Initialisation OK
}

ParticleGenerator::drawParticles()
{   for(int i=0; i<MAX_PARTICLES; i++) // Pour chaque particule
    {
        if(tabLife[i] > 0)
        {
            tabLife[i] -= tabFade[i];
        }
        else
        {
            tabLife[i] = 1.0;
            tabVelocities[i].x = myRand(-3.0,3.0);
            tabVelocities[i].y = myRand(10.0,20.0);
            tabVelocities[i].z = myRand(-3.0,3.0);
        }
    }

    return 0; // Dessin OK
}

void
ParticleGenerator::drawShape()
{


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

   glDrawElements( GL_POINTS, MAX_PARTICLES, GL_UNSIGNED_INT, tabIndices ); // trace tous les points
   glDisableVertexAttribArray( var1 );
   glDisableVertexAttribArray( var2 );
   glDisableVertexAttribArray( var3 );
   glDisableVertexAttribArray( var4 );
   glDisableVertexAttribArray( var5 );

}

void
ParticleGenerator::drawShape(const char* shader_name)
{

}
