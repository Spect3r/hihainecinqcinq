#ifndef simulator_h
#define simulator_h


#include "GlWindow.h"


class simulator : public GlWindow
{
	public:
        simulator();
        ~simulator();

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
