#include "particlegenerator.h"
#include "particule.h"

const int MAX_PARTICLES = 10;
Particule* particle[MAX_PARTICLES];

ParticleGenerator::ParticleGenerator()
{

}

ParticleGenerator::~ParticleGenerator()
{

}

ParticleGenerator::initializeParticles()
{

    for(int i=0; i<MAX_PARTICLES; i++)   // Boucle sur toutes les particules
    {   particle[i]->active = true;       // On rend la particule active
        particle[i]->life = 1.0;   // Maximum de vie

        particle[i]->fade =  0.02; //myRand(0.01,0.05);   // Vitesse de disparition aléatoire

        /*particle[i].r=myRand(0.0,1.0);  // Quantité aléatoire de Rouge
        particle[i].g=myRand(0.0,1.0);  // Quantité aléatoire de Vert
        particle[i].b=myRand(0.0,1.0);  // Quantité aléatoire de Bleu*/

        particle[i]->xi = 2; //myRand(-10.0,10.0);   // Vitesse aléatoire
        particle[i]->yi = 5; //myRand(-10.0,10.0);
        particle[i]->zi = 12; //myRand(10.0,20.0);

        particle[i]->xg = 0.0;       // Gravité dirigée selon l'axe -Z
        particle[i]->yg = 0.0;
        particle[i]->zg = -1.0;
    }
    return 0;    // Initialisation OK
}

int drawParticles()
{   for(int i=0; i<MAX_PARTICLES; i++) // Pour chaque particule
    {   if(particle[i]->active)         // Si elle est active
        {   float x = particle[i]->x;   // On récupère sa position
            float y = particle[i]->y;
            float z = particle[i]->z;

            /* Couleur de la particule; transparence = vie */
            //glColor4d(particle[i].r, particle[i].g, particle[i].b, particle[i].life);

            /* Dessin de carrés à partir de deux triangles (plus rapide pour la carte video */
            /*glBegin(GL_TRIANGLE_STRIP);
              glVertex3d(x+0.1,y,z+0.1); // Nord-Ouest
              glVertex3d(x-0.1,y,z+0.1); // Nord-Est
              glVertex3d(x+0.1,y,z-0.1); // Sud-Ouest
              glVertex3d(x-0.1,y,z-0.1); // Sud-Est
            glEnd();*/
            particle[i]->draw();


            /* Déplacement */
            particle[i]->x += particle[i]->xi/1000;
            particle[i]->y += particle[i]->yi/1000;
            particle[i]->z += particle[i]->zi/1000;

            /* Gravité */
            particle[i]->xi += particle[i]->xg;
            particle[i]->yi += particle[i]->yg;
            particle[i]->zi += particle[i]->zg;

            /* "Vie" */
            particle[i]->life -= particle[i]->fade;

            /* Si la particule est "morte" on la régénère */
            if (particle[i]->life < 0.0)
            {   particle[i]->life = 1.0;    // Maximum de vie
                particle[i]->fade = 0.02;//myRand(0.01,0.05);

                particle[i]->x = 0.0; // On renvoie la particule au centre
                particle[i]->y = 0.0;
                particle[i]->z = 0.0;

                particle[i]->xi = 2.0;//myRand(-10.0,10.0);   // Vitesse aléatoire
                particle[i]->yi = 2.0;//myRand(-10.0,10.0);
                particle[i]->zi = 15.0;//myRand(10.0,20.0);

                /*particle[i].r=0.5;//myRand(0.0,1.0);  // Quantité aléatoire de Rouge
                particle[i].g=0.5;//myRand(0.0,1.0);  // Quantité aléatoire de Vert
                particle[i].b=0.5;//myRand(0.0,1.0);  // Quantité aléatoire de Bleu*/
            }
        }
    }
    return 0; // Dessin OK
}
