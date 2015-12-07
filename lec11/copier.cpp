// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "copier.hpp"

/*****************************************************************************/


Copier::Copier ( int _nominalPower, int _scanDPI, int _pagesPerMinute )
	:	PoweredDevice( _nominalPower )
	,	Scanner( _nominalPower, _scanDPI )
	,	Printer( _nominalPower, _pagesPerMinute )
{
}


/*****************************************************************************/


void
Copier::copy ()
{
	const char * tmpFile = "temp.dat";
	scanDocument( tmpFile );
	printDocument( tmpFile );
}


/*****************************************************************************/

