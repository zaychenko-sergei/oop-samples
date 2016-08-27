// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _SCANNER_HPP_
#define _SCANNER_HPP_

/*****************************************************************************/

#include "powereddevice.hpp"

#include <string>

/*****************************************************************************/


class Scanner
	:	virtual public PoweredDevice
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Scanner ( int _nominalPower, int _scanDPI );

	int getScanDPI () const;

	virtual void scanDocument ( std::string const & _saveToFile );

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	const int m_scanDPI;

/*-----------------------------------------------------------------*/

};

/*****************************************************************************/


inline int
Scanner::getScanDPI () const
{
	return m_scanDPI;
}


/*****************************************************************************/

#endif // _SCANNER_HPP_


