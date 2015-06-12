//*****************************************************************************
//
// Main Program
// Author: Fabrice LAURI (fabrice.lauri@utbm.fr)
//          (Associate Professor at the
//          "Université de Technologie de Belfort-Montbéliard", France)
// Version: 1.0
// Last update: 2012-05-01
//
//*****************************************************************************
//
// Particle System
// Author : Thomas BOY
//          Julien DHENIN
//          Nicolas FARINE
//
// This project has been done as part of the IN55 course
// UTBM - Spring 2015
//
//*****************************************************************************

#include "simulator.h"

#include <QApplication>


int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
    Simulator win;
	win.show();
	return app.exec();
}
