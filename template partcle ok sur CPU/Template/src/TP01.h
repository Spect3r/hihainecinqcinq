﻿#ifndef TP01_h
#define TP01_h


#include "GlWindow.h"


class TP01 : public GlWindow
{
	public:
		TP01();
        ~TP01();

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
        void mousePressEvent(QMouseEvent *event);

};


#endif
