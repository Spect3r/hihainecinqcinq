#include "particule.h"
#include <iostream>



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


/*GLuint tabIndices[] =
{
    0 // par un TRIANGLE_STRIP, tracera les deux triangles formant la particule
};*/



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

}

Particule::~Particule()
{

}

/*void
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
}*/


