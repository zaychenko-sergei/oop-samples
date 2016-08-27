// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "printer.hpp"

#include <iostream>

/*****************************************************************************/


Printer::Printer ( int _nominalPower, int _pagesPerMinute )
    :    PoweredDevice( _nominalPower )
    ,    m_pagesPerMinute( _pagesPerMinute )
{
}


/*****************************************************************************/


void
Printer::printDocument ( std::string const & _fromFile )
{
	std::cout << "Printing document from file " << _fromFile << std::endl;
}


/*****************************************************************************/

