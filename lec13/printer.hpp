// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _PRINTER_HPP_
#define _PRINTER_HPP_

/*****************************************************************************/

#include "powereddevice.hpp"

#include <string>

/*****************************************************************************/


class Printer
    :    virtual public PoweredDevice
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Printer ( int _nominalPower, int _pagesPerMinute );
    
	int getPagesPerMinute () const;
    
	virtual void printDocument ( std::string const & _document );

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	const int m_pagesPerMinute;

/*-----------------------------------------------------------------*/

};

/*****************************************************************************/


inline int
Printer::getPagesPerMinute () const
{
	return m_pagesPerMinute;
}


/*****************************************************************************/

#endif //  _PRINTER_HPP_

