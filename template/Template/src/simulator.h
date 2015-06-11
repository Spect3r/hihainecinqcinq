#ifndef Simulator_h
#define Simulator_h


#include "GlWindow.h"


class Simulator : public GlWindow
{
	public:
        Simulator();
        ~Simulator();

		/*!
		*\brief Initialization des objets.
		*/
		bool initializeObjects();



		/*!
		*\brief Rendu de la scène.
		*/
		void render();

		void keyPressEvent(QKeyEvent *);
        void mouseMoveEvent(QMouseEvent * event);
        void mousePressEvent(QMouseEvent * event);

};


#endif
