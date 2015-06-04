#include "particlegenerator.h"
#include "particule.h"
#include <cstdlib>
#include <iostream>


Particule particleContainer[MAX_PARTICLES];
//int tabIndices[MAX_PARTICLES];
//GLfloat tabVertices[MAX_PARTICLES];
//GLfloat tabColors[MAX_PARTICLES];
GLfloat time = 0;

ParticleGenerator::ParticleGenerator()
{
    for( GLuint i = 0; i < MAX_PARTICLES; i++ )
    {
        tabIndices[i] = i;
        tabColors[i].x = myRand(0.0, 1.0); //static_cast <GLfloat> (rand()) / static_cast <GLfloat> (RAND_MAX);
        tabColors[i].y = myRand(0.0, 1.0); //static_cast <GLfloat> (rand()) / static_cast <GLfloat> (RAND_MAX);
        tabColors[i].z = myRand(0.0, 1.0); //static_cast <GLfloat> (rand()) / static_cast <GLfloat> (RAND_MAX);
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
        //cout<<i<<endl;
        particleContainer[i].active = true;       // On rend la particule active

        //particleContainer[i].life = 2.0;   // Maximum de vie
        tabLife[i] = 1.0;

        tabFade[i] = myRand(0.01,0.05); //myRand(0.01,0.05);   // Vitesse de disparition aléatoire

        tabPositions[i].x = 0.0;
        tabPositions[i].y = 0.0;
        tabPositions[i].z = 0.0;


        //tabVelocities[i].x = -0.5 + static_cast <GLfloat> (rand()) / static_cast <GLfloat> (RAND_MAX/10); //myRand(-10.0,10.0);   // Vitesse aléatoire
        tabVelocities[i].x = myRand(-10.0,10.0);
        tabVelocities[i].y = myRand(10.0,20.0); //myRand(-10.0,10.0);
        tabVelocities[i].z = myRand(-10.0,10.0);


        tabGravities[i].x = 0.0;       // Gravité dirigée selon l'axe -Z
        tabGravities[i].y = -1.0;
        tabGravities[i].z = 0.0;


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
            tabVelocities[i].x = myRand(-10.0,10.0);
            tabVelocities[i].y = myRand(10.0,20.0); //myRand(-10.0,10.0);
            tabVelocities[i].z = myRand(-10.0,10.0);
        }

        time++;
    }

    return 0; // Dessin OK
}

void
ParticleGenerator::drawShape()
{

   //std::cout<<"debut drawshape";
   GLint var1 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "position" );
   glEnableVertexAttribArray( var1 );
   glVertexAttribPointer( var1, 3, GL_FLOAT, GL_FALSE, 0, tabPositions );

   GLint var2 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "color" );
   glEnableVertexAttribArray( var2 );
   glVertexAttribPointer( var2, 3, GL_FLOAT, GL_FALSE, 0, tabColors );

   GLint var3 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "velocity" );
   glEnableVertexAttribArray( var3 );
   glVertexAttribPointer( var3, 3, GL_FLOAT, GL_FALSE, 0, tabVelocities );

   GLint var4 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "gravity" );
   glEnableVertexAttribArray( var4 );
   glVertexAttribPointer( var4, 3, GL_FLOAT, GL_FALSE, 0, tabGravities );

   GLfloat var5 = glGetUniformLocation( m_Framework->getCurrentShaderId(), "time" );
   glEnableVertexAttribArray( var5 );
   glUniform1f( var5, time);

   GLfloat var6 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "life" );
   glEnableVertexAttribArray( var6 );
   glVertexAttribPointer( var6, 1, GL_FLOAT, GL_FALSE, 0, tabLife );

   GLfloat var7 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "fade" );
   glEnableVertexAttribArray( var7 );
   glVertexAttribPointer( var7, 1, GL_FLOAT, GL_FALSE, 0, tabFade );

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
ParticleGenerator::drawShape(const char* shader_name)
{
    /*GLint var1 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "position" );
    glEnableVertexAttribArray( var1 );
    glVertexAttribPointer( var1, 3, GL_FLOAT, GL_FALSE, 0, m_TabVertices );
    GLint var2 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "color" );
    glEnableVertexAttribArray( var2 );
    glVertexAttribPointer( var2, 3, GL_FLOAT, GL_FALSE, 0, g_TabColors );
    glDrawArrays( GL_LINES, 0, 6 );
    glDisableVertexAttribArray( var1 );
    glDisableVertexAttribArray( var2 );*/
}
