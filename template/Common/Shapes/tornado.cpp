#include "Tornado.h"
#include <cstdlib>
#include <iostream>

Tornado::Tornado()
{

}

Tornado::~Tornado()
{

}

/*
 * Fonction permettant d'obtenir une valeur comprise entre deux valeurs passées en paramètre
*/
double Tornado::myRand(double min, double max)
{
    return (double) (min + ((float) rand() / RAND_MAX * (max - min + 1.0)));
}

/*
 * fonction d'initailisation des particules
*/
Tornado::initializeParticles()
{

    for(int i=0; i<MAX_PARTICLES; i++)   // Boucle sur toutes les particules
    {
        tabIndices[i] = i;
        tabLife[i] = 1.0; // Maximum de vie

        tabColors[i].x = 0.2;
        tabColors[i].y = 0.2;
        tabColors[i].z = 0.2;

        tabFade[i] = myRand(0.01,0.1);  // Vitesse de disparition aléatoire

        // Initialisation à l'origine
        tabPositions[i].x = 0.0;
        tabPositions[i].y = 0.0;
        tabPositions[i].z = 0.0;

        // Calcul Theta
        if(i <= 360)
        {
            tabTheta[i] = i;
        }
        else
        {
            tabTheta[i] = i%360;
        }

        // Vitesse aléatoire
        tabVelocities[i].x = cos(tabTheta[i]);
        tabVelocities[i].y = myRand(15.0,20.0);
        tabVelocities[i].z = sin(tabTheta[i]);

        tabSize[i] = myRand(0.5,1.5);
    }
    return 0;    // Initialisation OK
}

/*
 * Fonction de mise à jour des particules
*/
Tornado::drawParticles()
{   for(int i=0; i<MAX_PARTICLES; i++) // Pour chaque particule
    {
        if(tabLife[i] > 0)
        {
            tabLife[i] -= tabFade[i];
        }
        if (tabTheta[i] > 360) {
            tabTheta[i]=0;


        }
        else
        {
            tabTheta[i]+=1;
        }

            tabLife[i] = 1.0;
            tabVelocities[i].x = cos(tabTheta[i]);
            tabVelocities[i].z = sin(tabTheta[i]);
            tabSize[i] = myRand(0.5,2);

            tabPositions[i].x += cos(tabTheta[i])/100;
            tabPositions[i].z += sin(tabTheta[i])/100;

            tabPositions[i].x += 0.01;
            tabPositions[i].z += 0.01;

    }

    return 0; // Dessin OK
}

void
Tornado::drawShape()
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
Tornado::drawShape(const char* shader_name)
{

}


