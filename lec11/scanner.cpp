// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "scanner.hpp"

#include <iostream>

/*****************************************************************************/


Scanner::Scanner ( int _nominalPower, int _scanDPI )
    :    PoweredDevice( _nominalPower )
    ,    m_scanDPI( _scanDPI )
{
}


/*****************************************************************************/


void 
Scanner::scanDocument ( std::string const & _saveToFile )
{
	std::cout << "Scanning document and saving resulting file " << _saveToFile << std::endl;
}


/*****************************************************************************/

