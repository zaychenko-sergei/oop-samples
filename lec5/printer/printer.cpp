// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "printer.hpp"

#include <iostream>

/*****************************************************************************/

Printer * Printer::ms_Instance;

/*****************************************************************************/


Printer * Printer::GetInstance ()
{
	if ( !ms_Instance )
	{
		ms_Instance = new Printer();

		struct Destroyer
		{
			~ Destroyer () { delete ms_Instance; }
		};

		static Destroyer s_Destroyer;
	}

	return ms_Instance;
}


/*****************************************************************************/


Printer::Printer ()
{
	std::cout << "Printer created..." << std::endl;
}


/*****************************************************************************/


Printer::~Printer ()
{
	std::cout << "Printer destroyed..." << std::endl;
}


/*****************************************************************************/


void Printer::Print ( const char * _filePath )
{
	std::cout << "I'm printing..." << std::endl;
}


/*****************************************************************************/
