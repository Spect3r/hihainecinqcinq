#include "particlegenerator.h"
#include "particule.h"
#include <cstdlib>
#include <iostream>

const GLuint MAX_PARTICLES = 100;

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
        particleContainer[i].active = true;       // On rend la particule active

        particleContainer[i].life = 1.0;   // Maximum de vie


        particleContainer[i].fade =  0.02; //myRand(0.01,0.05);   // Vitesse de disparition aléatoire


        /*particle[i].r=myRand(0.0,1.0);  // Quantité aléatoire de Rouge
        particle[i].g=myRand(0.0,1.0);  // Quantité aléatoire de Vert
        particle[i].b=myRand(0.0,1.0);  // Quantité aléatoire de Bleu*/

        particleContainer[i].xi = 2; //myRand(-10.0,10.0);   // Vitesse aléatoire

        particleContainer[i].yi = 50; //myRand(-10.0,10.0);

        particleContainer[i].zi = 12; //myRand(10.0,20.0);


        particleContainer[i].xg = 0.0;       // Gravité dirigée selon l'axe -Z

        particleContainer[i].yg = -1.0;

        particleContainer[i].zg = -1.0;


    }
    return 0;    // Initialisation OK
}

ParticleGenerator::drawParticles()
{   for(int i=0; i<MAX_PARTICLES; i++) // Pour chaque particule
    {   if(particleContainer[i].active)         // Si elle est active
        {   float x = particleContainer[i].position.x;   // On récupère sa position
            float y = particleContainer[i].position.y;
            float z = particleContainer[i].position.z;
            std::cout<<" Life : "<<particleContainer[i].life<<endl;
            particleContainer[i].position.y = particleContainer[i].life;
            std::cout<<" x : "<< x <<" y : "<< y <<" z : "<< z <<endl;

            /* Couleur de la particule; transparence = vie */
            //glColor4d(particle[i].r, particle[i].g, particle[i].b, particle[i].life);


            /* Déplacement */
            particleContainer[i].position.x += particleContainer[i].xi/1000;
            particleContainer[i].position.y += particleContainer[i].yi/1000;
            particleContainer[i].position.z += particleContainer[i].zi/1000;

            /* Gravité */
            particleContainer[i].xi += particleContainer[i].xg;
            particleContainer[i].yi += particleContainer[i].yg;
            particleContainer[i].zi += particleContainer[i].zg;

            /* "Vie" */
            particleContainer[i].life -= particleContainer[i].fade;



            tabColors[i].x = (float) (rand() % 100)/100; //static_cast <GLfloat> (rand()) / static_cast <GLfloat> (RAND_MAX);
            tabColors[i].y = (float) (rand() % 100)/100; //static_cast <GLfloat> (rand()) / static_cast <GLfloat> (RAND_MAX);
            tabColors[i].z = (float) (rand() % 100)/100; //static_cast <GLfloat> (rand()) / static_cast <GLfloat> (RAND_MAX);
            //tabPositions[i].x = -5 + static_cast <GLfloat> (rand()) / static_cast <GLfloat> (RAND_MAX/10);
           // tabPositions[i].y = -5 + static_cast <GLfloat> (rand()) / static_cast <GLfloat> (RAND_MAX/10);
            //tabPositions[i].z = -5 + static_cast <GLfloat> (rand()) / static_cast <GLfloat> (RAND_MAX/10);
            tabPositions[i].y = particleContainer[i].position.y;


            /* Si la particule est "morte" on la régénère */
            if (particleContainer[i].life < 0.0)
            {   particleContainer[i].life = 1.0;    // Maximum de vie
                particleContainer[i].fade = 0.02;//myRand(0.01,0.05);

                particleContainer[i].position.x = 0.0; // On renvoie la particule au centre
                particleContainer[i].position.y = 0.0;
                particleContainer[i].position.z = 0.0;

                particleContainer[i].xi = 2.0;//myRand(-10.0,10.0);   // Vitesse aléatoire
                particleContainer[i].yi = 10.0;//myRand(-10.0,10.0);
                particleContainer[i].zi = 15.0;//myRand(10.0,20.0);

                /*particle[i].r=0.5;//myRand(0.0,1.0);  // Quantité aléatoire de Rouge
                particle[i].g=0.5;//myRand(0.0,1.0);  // Quantité aléatoire de Vert
                particle[i].b=0.5;//myRand(0.0,1.0);  // Quantité aléatoire de Bleu*/
            }
        }
    }
    return 0; // Dessin OK
}

void
ParticleGenerator::drawShape()
{
   std::cout<<"debut drawshape";
   GLint var1 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "position" );
   std::cout<<"1";
   glEnableVertexAttribArray( var1 );
   std::cout<<"2";
   glVertexAttribPointer( var1, 3, GL_FLOAT, GL_FALSE, 0, tabPositions );
   std::cout<<"3";
   GLint var2 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "color" );
   std::cout<<"4";
   glEnableVertexAttribArray( var2 );
   std::cout<<"5";
   glVertexAttribPointer( var2, 3, GL_FLOAT, GL_FALSE, 0, tabColors );
   std::cout<<"6";
   glDrawElements( GL_POINTS, 10, GL_UNSIGNED_INT, tabIndices ); // trace tous les points
   std::cout<<"7";
   glDisableVertexAttribArray( var1 );
   std::cout<<"8";
   glDisableVertexAttribArray( var2 );
   std::cout<<"9";
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
