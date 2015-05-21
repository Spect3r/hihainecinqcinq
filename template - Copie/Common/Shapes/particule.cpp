#include "particule.h"
#include <iostream>

const GLfloat size = 0.5f;


int LastUsedParticle = 0;

// Trouve une Particle dans ParticlesContainer qui n'est actuellement pas utilisée.
// (i.e. life < 0);
/*Particule::FindUnusedParticle(){

    for(int i=LastUsedParticle; i<MaxParticles; i++){
        if (ParticlesContainer[i].life < 0){
            LastUsedParticle = i;
            return i;
        }
    }

    for(int i=0; i<LastUsedParticle; i++){
        if (ParticlesContainer[i].life < 0){
            LastUsedParticle = i;
            return i;
        }
    }

    return 0; // Toutes les particules sont prises, écrase la première
}*/

GLfloat tabColors[] =
{
   //myRand(0.0,1.0),myRand(0.0,1.0),myRand(0.0,1.0),	// Red
    1,0,0,
};



GLuint tabIndices[] =
{
    0 // par un TRIANGLE_STRIP, tracera les deux triangles formant la particule
};



//double myRand(double min, double max)
//{
    //return (double) (min + ((float) rand() / 1 * (max - min + 1.0)));// attention
//}

Particule::Particule()
{
    this->active = true;
    this->life = 1.0;	 // Maximum de vie
    //this->fade = myRand(0.01,0.05);   // Vitesse de disparition aléatoire (my rand est une fonction à créer pour la génération de nombres aléatoires….
    this->fade = 0.03;

    //this->r=myRand(0.0,1.0);  // Quantité aléatoire de Rouge
    //this->g=myRand(0.0,1.0);  // Quantité aléatoire de Vert
    //this->b=myRand(0.0,1.0);  // Quantité aléatoire de Bleu

    //this->xi = myRand(-10.0,10.0);   // Vitesse aléatoire
    //this->yi = myRand(-10.0,10.0);
    //this->zi = myRand(10.0,20.0);

    this->xi = 5;   // Vitesse aléatoire
    this->yi = 2;
    this->zi = -8;

    this->xg = 0.0;       // Gravité dirigée selon l"axe -Z
    this->yg = 0.0;
    this->zg = -1.0;
}

Particule::~Particule()
{

}

void
Particule::drawShape()
{
   GLint var1 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "position" );
   std::cout<<"1";
   glEnableVertexAttribArray( var1 );
   std::cout<<"2";
   glVertexAttribPointer( var1, 4, GL_FLOAT, GL_FALSE, 0, tabVertices );
   std::cout<<"3";
   GLint var2 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "color" );
   std::cout<<"4";
   glEnableVertexAttribArray( var2 );
   std::cout<<"5";
   glVertexAttribPointer( var2, 4, GL_FLOAT, GL_FALSE, 0, tabColors );
   std::cout<<"6";
   glDrawElements( GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, tabIndices );//gl draw elements triangles
   std::cout<<"7";
   glDisableVertexAttribArray( var1 );
   std::cout<<"8";
   glDisableVertexAttribArray( var2 );
   std::cout<<"9";
}

void Particule::drawShape( const char* shader_name )
{
    glEnableVertexAttribArray( 0 );
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, tabVertices );
    glEnableVertexAttribArray( 1 );
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 0, tabColors );
    //glDrawElements( GL_TRIANGLE_STRIP, 6, GL_UNSIGNED_INT, tabIndices );
    glDrawElements( GL_POINTS, 1, GL_UNSIGNED_INT, tabIndices );
    glDisableVertexAttribArray( 0 );
    glDisableVertexAttribArray( 1 );
}


