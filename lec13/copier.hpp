// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _COPIER_HPP_
#define _COPIER_HPP_

/*****************************************************************************/

#include "scanner.hpp"
#include "printer.hpp"

/*****************************************************************************/


class Copier
    :    public Printer, public Scanner
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Copier ( int _nominalPower, int _scanDPI, int _pagesPerMinute );

	void copy ();

/*-----------------------------------------------------------------*/

};

/*****************************************************************************/

#endif //  _COPIER_HPP_
