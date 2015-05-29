#include "particlegenerator.h"
#include "particule.h"
#include <cstdlib>
#include <iostream>


Particule particleContainer[MAX_PARTICLES];
//int tabIndices[MAX_PARTICLES];
//GLfloat tabVertices[MAX_PARTICLES];
//GLfloat tabColors[MAX_PARTICLES];

ParticleGenerator::ParticleGenerator()
{
    for( GLuint i = 0; i < MAX_PARTICLES; i++ )
    {
        tabIndices[i] = i;
        tabColors[i].x = (rand() % 100)/100; //static_cast <GLfloat> (rand()) / static_cast <GLfloat> (RAND_MAX);
        tabColors[i].y = (rand() % 100)/100; //static_cast <GLfloat> (rand()) / static_cast <GLfloat> (RAND_MAX);
        tabColors[i].z = (rand() % 100)/100; //static_cast <GLfloat> (rand()) / static_cast <GLfloat> (RAND_MAX);
        tabPositions[i].x = -5 + static_cast <GLfloat> (rand()) / static_cast <GLfloat> (RAND_MAX/10);
        tabPositions[i].y = -5 + static_cast <GLfloat> (rand()) / static_cast <GLfloat> (RAND_MAX/10);
        tabPositions[i].z = -5 + static_cast <GLfloat> (rand()) / static_cast <GLfloat> (RAND_MAX/10);
    }

}

ParticleGenerator::~ParticleGenerator()
{

}

ParticleGenerator::initializeParticles()
{

    for(int i=0; i<MAX_PARTICLES; i++)   // Boucle sur toutes les particules
    {
        cout<<i<<endl;
        particleContainer[i].active = true;       // On rend la particule active

        particleContainer[i].life = 1.0;   // Maximum de vie


        particleContainer[i].fade =  0.02; //myRand(0.01,0.05);   // Vitesse de disparition aléatoire


        /*particle[i].r=myRand(0.0,1.0);  // Quantité aléatoire de Rouge
        particle[i].g=myRand(0.0,1.0);  // Quantité aléatoire de Vert
        particle[i].b=myRand(0.0,1.0);  // Quantité aléatoire de Bleu*/

        particleContainer[i].velocity.x = 2; //myRand(-10.0,10.0);   // Vitesse aléatoire

        particleContainer[i].velocity.y = 50; //myRand(-10.0,10.0);

        particleContainer[i].velocity.z = 12; //myRand(10.0,20.0);


        particleContainer[i].gravity.x = 0.0;       // Gravité dirigée selon l'axe -Z

        particleContainer[i].gravity.y = -1.0;

        particleContainer[i].gravity.z = 0.0;


    }
    return 0;    // Initialisation OK
}

ParticleGenerator::drawParticles()
{   for(int i=0; i<MAX_PARTICLES; i++) // Pour chaque particule
    {   if(particleContainer[i].active)         // Si elle est active
        {
            //std::cout<<" Life : "<<particleContainer[i].life<<endl;
            //particleContainer[i].position.y = particleContainer[i].life;
           // std::cout<<" x : "<< x <<" y : "<< y <<" z : "<< z <<endl;

            /* Couleur de la particule; transparence = vie */
            //glColor4d(particle[i].r, particle[i].g, particle[i].b, particle[i].life);


            /* Déplacement */
            /*particleContainer[i].position.x += particleContainer[i].velocity.x/1000;
            particleContainer[i].position.y += particleContainer[i].velocity.y/1000;
            particleContainer[i].position.z += particleContainer[i].velocity.z/1000;*/

            /* Gravité */
            /*particleContainer[i].velocity.x += particleContainer[i].gravity.x;
            particleContainer[i].velocity.y += particleContainer[i].gravity.y;
            particleContainer[i].velocity.z += particleContainer[i].gravity.z;*/

            /* "Vie" */
            particleContainer[i].life -= particleContainer[i].fade;



            tabColors[i].x = (float) (rand() % 100)/100; //static_cast <GLfloat> (rand()) / static_cast <GLfloat> (RAND_MAX);
            tabColors[i].y = (float) (rand() % 100)/100; //static_cast <GLfloat> (rand()) / static_cast <GLfloat> (RAND_MAX);
            tabColors[i].z = (float) (rand() % 100)/100; //static_cast <GLfloat> (rand()) / static_cast <GLfloat> (RAND_MAX);
            //tabPositions[i].x = -5 + static_cast <GLfloat> (rand()) / static_cast <GLfloat> (RAND_MAX/10);
           // tabPositions[i].y = -5 + static_cast <GLfloat> (rand()) / static_cast <GLfloat> (RAND_MAX/10);
            //tabPositions[i].z = -5 + static_cast <GLfloat> (rand()) / static_cast <GLfloat> (RAND_MAX/10);
            //tabPositions[i].y = particleContainer[i].position.y;


            /* Si la particule est "morte" on la régénère */
           /* if (particleContainer[i].life < 0.0)
            {   particleContainer[i].life = 1.0;    // Maximum de vie
                particleContainer[i].fade = 0.02;//myRand(0.01,0.05);

                particleContainer[i].position.x = 0.0; // On renvoie la particule au centre
                particleContainer[i].position.y = 0.0;
                particleContainer[i].position.z = 0.0;

                particleContainer[i].velocity.x = 2.0;//myRand(-10.0,10.0);   // Vitesse aléatoire
                particleContainer[i].velocity.y = 10.0;//myRand(-10.0,10.0);
                particleContainer[i].velocity.z = 15.0;//myRand(10.0,20.0);

                /*particle[i].r=0.5;//myRand(0.0,1.0);  // Quantité aléatoire de Rouge
                particle[i].g=0.5;//myRand(0.0,1.0);  // Quantité aléatoire de Vert
                particle[i].b=0.5;//myRand(0.0,1.0);  // Quantité aléatoire de Bleu
            }*/
        }
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
   glDrawElements( GL_POINTS, MAX_PARTICLES, GL_UNSIGNED_INT, tabIndices ); // trace tous les points
   glDisableVertexAttribArray( var1 );
   glDisableVertexAttribArray( var2 );
   glDisableVertexAttribArray( var3 );
}

/*void
ParticleGenerator::drawShape(const char* shader_name)
{
    GLint var1 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "position" );
    glEnableVertexAttribArray( var1 );
    glVertexAttribPointer( var1, 3, GL_FLOAT, GL_FALSE, 0, m_TabVertices );
    GLint var2 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "color" );
    glEnableVertexAttribArray( var2 );
    glVertexAttribPointer( var2, 3, GL_FLOAT, GL_FALSE, 0, g_TabColors );
    glDrawArrays( GL_LINES, 0, 6 );
    glDisableVertexAttribArray( var1 );
    glDisableVertexAttribArray( var2 );
}*/
