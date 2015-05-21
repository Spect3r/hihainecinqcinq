#include "particlegenerator.h"
#include "particule.h"

const int MAX_PARTICLES = 10;
Particule* particleContainer[MAX_PARTICLES];
int tabIndices[MAX_PARTICLES];
GLfloat tabVertices[MAX_PARTICLES];
GLfloat tabColors[MAX_PARTICLES];

ParticleGenerator::ParticleGenerator()
{
    for( GLuint i = 0; i < MAX_PARTICLES; ++i )
    {
        tabIndices[i] = i;
    }

}

ParticleGenerator::~ParticleGenerator()
{

}

ParticleGenerator::initializeParticles()
{

    for(int i=0; i<MAX_PARTICLES; i++)   // Boucle sur toutes les particules
    {
        particleContainer[i]->active = true;       // On rend la particule active
        particleContainer[i]->life = 1.0;   // Maximum de vie

        particleContainer[i]->fade =  0.02; //myRand(0.01,0.05);   // Vitesse de disparition aléatoire

        /*particle[i].r=myRand(0.0,1.0);  // Quantité aléatoire de Rouge
        particle[i].g=myRand(0.0,1.0);  // Quantité aléatoire de Vert
        particle[i].b=myRand(0.0,1.0);  // Quantité aléatoire de Bleu*/

        particleContainer[i]->xi = 2; //myRand(-10.0,10.0);   // Vitesse aléatoire
        particleContainer[i]->yi = 5; //myRand(-10.0,10.0);
        particleContainer[i]->zi = 12; //myRand(10.0,20.0);

        particleContainer[i]->xg = 0.0;       // Gravité dirigée selon l'axe -Z
        particleContainer[i]->yg = 0.0;
        particleContainer[i]->zg = -1.0;
    }
    return 0;    // Initialisation OK
}

int drawParticles()
{   for(int i=0; i<MAX_PARTICLES; i++) // Pour chaque particule
    {   if(particleContainer[i]->active)         // Si elle est active
        {   float x = particleContainer[i]->x;   // On récupère sa position
            float y = particleContainer[i]->y;
            float z = particleContainer[i]->z;

            /* Couleur de la particule; transparence = vie */
            //glColor4d(particle[i].r, particle[i].g, particle[i].b, particle[i].life);

            /* Dessin de carrés à partir de deux triangles (plus rapide pour la carte video */
            /*glBegin(GL_TRIANGLE_STRIP);
              glVertex3d(x+0.1,y,z+0.1); // Nord-Ouest
              glVertex3d(x-0.1,y,z+0.1); // Nord-Est
              glVertex3d(x+0.1,y,z-0.1); // Sud-Ouest
              glVertex3d(x-0.1,y,z-0.1); // Sud-Est
            glEnd();*/
            particleContainer[i]->draw();


            /* Déplacement */
            particleContainer[i]->x += particleContainer[i]->xi/1000;
            particleContainer[i]->y += particleContainer[i]->yi/1000;
            particleContainer[i]->z += particleContainer[i]->zi/1000;

            /* Gravité */
            particleContainer[i]->xi += particleContainer[i]->xg;
            particleContainer[i]->yi += particleContainer[i]->yg;
            particleContainer[i]->zi += particleContainer[i]->zg;

            /* "Vie" */
            particleContainer[i]->life -= particleContainer[i]->fade;

            /* Si la particule est "morte" on la régénère */
            if (particleContainer[i]->life < 0.0)
            {   particleContainer[i]->life = 1.0;    // Maximum de vie
                particleContainer[i]->fade = 0.02;//myRand(0.01,0.05);

                particleContainer[i]->x = 0.0; // On renvoie la particule au centre
                particleContainer[i]->y = 0.0;
                particleContainer[i]->z = 0.0;

                particleContainer[i]->xi = 2.0;//myRand(-10.0,10.0);   // Vitesse aléatoire
                particleContainer[i]->yi = 2.0;//myRand(-10.0,10.0);
                particleContainer[i]->zi = 15.0;//myRand(10.0,20.0);

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
   GLint var1 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "position" );
   //std::cout<<"1";
   glEnableVertexAttribArray( var1 );
   //std::cout<<"2";
   glVertexAttribPointer( var1, 4, GL_FLOAT, GL_FALSE, 0, tabVertices );
   //std::cout<<"3";
   GLint var2 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "color" );
   //std::cout<<"4";
   glEnableVertexAttribArray( var2 );
   //std::cout<<"5";
   glVertexAttribPointer( var2, 4, GL_FLOAT, GL_FALSE, 0, tabColors );
   //std::cout<<"6";
   glDrawElements( GL_POINTS, MAX_PARTICLES, GL_UNSIGNED_INT, tabIndices ); // trace tout les points
   //std::cout<<"7";
   glDisableVertexAttribArray( var1 );
   //std::cout<<"8";
   glDisableVertexAttribArray( var2 );
   //std::cout<<"9";
}
