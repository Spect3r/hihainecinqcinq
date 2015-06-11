#include "fireworks.h"
#include <cstdlib>
#include <iostream>

Fireworks::Fireworks()
{

}

Fireworks::~Fireworks()
{

}

double Fireworks::myRand(double min, double max)
{
    return (double) (min + ((float) rand() / RAND_MAX * (max - min + 1.0)));
}

Fireworks::initializeParticles()
{

    /*for(int i=0; i<MAX_PARTICLES; i = i+12)   // Boucle sur toutes les particules
    {
        cout<<i<<endl;
        //cout<<"debut boucle"<<endl;

       /* tabVertices[i].x = -1.0;
        tabVertices[i].y = -1.0;
        tabVertices[i].z = 0.0;
        tabVertices[i+1].x = 1.0;
        tabVertices[i+1].y = -1.0;
        tabVertices[i+1].z = 0.0;
        tabVertices[i+2].x = -1.0;
        tabVertices[i+2].y = 1.0;
        tabVertices[i+2].z = 0.0;
        tabVertices[i+3].x = 1.0;
        tabVertices[i+3].y = 1.0;
        tabVertices[i+3].z = 0.0;

        tabVertices[i] = -1.0;
        cout << tabVertices[i] << endl;
        tabVertices[i+1] = -1.0;
        cout << tabVertices[i+1] << endl;
        tabVertices[i+2] = 0.0;
        cout << tabVertices[i+2] << endl;
        tabVertices[i+3] = 1.0;
        cout << tabVertices[i+3] << endl;
        tabVertices[i+4] = -1.0;
        cout << tabVertices[i+4] << endl;
        tabVertices[i+5] = 0.0;
        cout << tabVertices[i+5] << endl;
        tabVertices[i+6] = -1.0;
        cout << tabVertices[i+6] << endl;
        tabVertices[i+7] = 1.0;
        cout << tabVertices[i+7] << endl;
        tabVertices[i+8] = 0.0;
        cout << tabVertices[i+8] << endl;
        tabVertices[i+9] = 1.0;
        cout << tabVertices[i+9] << endl;
        tabVertices[i+10] = 1.0;
        cout << tabVertices[i+10] << endl;
        tabVertices[i+11] = 0.0;
        cout << tabVertices[i+11] << endl;



        //cout<<"fin boucle"<<endl;

        tabUv[i].x = 0.0;
        tabUv[i].y = 1.0;
        tabUv[i+1].x = 1.0;
        tabUv[i+1].y = 1.0;
        tabUv[i+2].x = 0.0;
        tabUv[i+2].y = 0.0;
        tabUv[i+3].x = 1.0;
        tabUv[i+3].y = 0.0;

        tabIndices[i] = 0;
        tabIndices[i+1] = 1;
        tabIndices[i+2] = 2;
        tabIndices[i+3] = 3;

         cout<<i<<endl;
    }*/

    int j =0;
    int k =0;
    int l=0;
    for(int i=0; i <MAX_PARTICLES; i++)
    {
        cout<<i<<endl;
        tabVertices[0] = -1.0;
        cout<<tabVertices[0]<<endl;
        tabVertices[1] = -1.0;
        cout<<tabVertices[1]<<endl;
        tabVertices[2] = 0.0;
        cout<<tabVertices[2]<<endl;
        tabVertices[3] = 1.0;
        cout<<tabVertices[3]<<endl;
        tabVertices[4] = -1.0;
        cout<<tabVertices[4]<<endl;
        tabVertices[5] = 0.0;
        cout<<tabVertices[5]<<endl;
        tabVertices[6] = -1.0;
        cout<<tabVertices[6]<<endl;
        tabVertices[7] = 1.0;
        cout<<tabVertices[7]<<endl;
        tabVertices[8] = 0.0;
        cout<<tabVertices[8]<<endl;
        tabVertices[9] = 1.0;
        cout<<tabVertices[9]<<endl;
        tabVertices[10] = 1.0;
        cout<<tabVertices[10]<<endl;
        tabVertices[11] = 0.0;
        cout<<tabVertices[11]<<endl;

        tabUv[0] = 0.0;
        tabUv[1] = 1.0;
        tabUv[2] = 1.0;
        tabUv[3] = 1.0;
        tabUv[4] = 0.0;
        tabUv[5] = 0.0;
        tabUv[6] = 1.0;
        tabUv[7] = 0.0;

        tabIndices[0] = 0;
        tabIndices[1] = 1;
        tabIndices[2] = 2;
        tabIndices[3] = 3;

        j+=12;
        k+=8;
        l+=4;
    }

    for(int i=0; i<MAX_PARTICLES; i++)   // Boucle sur toutes les particules
    {

        tabLife[i] = 1.0; // Maximum de vie

        tabFade[i] = myRand(0.01,0.1);  // Vitesse de disparition aléatoire

        // Calcul Theta
        theta = myRand(1.0, 360.0);

        // Vitesse aléatoire
        tabVelocities[i].y = myRand(15.0,20.0);
    }
    return 0;    // Initialisation OK
}

Fireworks::drawParticles()
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
            tabVelocities[i].y = myRand(15.0,20.0);
        }
    }

    return 0; // Dessin OK
}

void
Fireworks::drawShape()
{
    glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
    //cout<<"1"<<endl;
    GLint var0 = glGetUniformLocation( m_Framework->getCurrentShaderId(), "texId" );
    glUniform1i( var0, 0 );
    //cout<<"2"<<endl;
    GLint var1 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "position" );
    glVertexAttribPointer( var1, 3, GL_FLOAT, GL_FALSE, 0, tabVertices );
    //cout<<"3"<<endl;
   GLint var3 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "velocity" );
   glEnableVertexAttribArray( var3 );
   glVertexAttribPointer( var3, 3, GL_FLOAT, GL_FALSE, 0, tabVelocities );
      // cout<<"4"<<endl;
   GLfloat var4 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "life" );
   glEnableVertexAttribArray( var4 );
   glVertexAttribPointer( var4, 1, GL_FLOAT, GL_FALSE, 0, tabLife );
    //cout<<"5"<<endl;
   GLfloat var5 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "fade" );
   glEnableVertexAttribArray( var5 );
   glVertexAttribPointer( var5, 1, GL_FLOAT, GL_FALSE, 0, tabFade );  
//cout<<"7"<<endl;
   GLint var7 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "uv" );
   glVertexAttribPointer( var7, 2, GL_FLOAT, GL_FALSE, 0, tabUv );
//cout<<"8"<<endl;
   glDrawElements( GL_TRIANGLE_STRIP, 4*MAX_PARTICLES, GL_UNSIGNED_INT, tabIndices );
  // cout<<"9"<<endl;
   glDisableVertexAttribArray( var1 );
   glDisableVertexAttribArray( var3 );
   glDisableVertexAttribArray( var4 );
   glDisableVertexAttribArray( var5 );
   glDisableVertexAttribArray( var7 );
}

void
Fireworks::drawShape(const char* shader_name)
{

}
