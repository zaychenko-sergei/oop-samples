// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _STOCK_LOGGER_HPP__
#define _STOCK_LOGGER_HPP__

/*****************************************************************************/

#include "stock_change_listener.hpp"

#include <iostream>

/*****************************************************************************/


class StockLogger
	:	public StockChangeListener
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	StockLogger ( std::ostream & _stream );

	void onPriceChanged ( Stock & _s, double _oldPrice ) override;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	std::ostream & m_stream;

/*-----------------------------------------------------------------*/

};

/*****************************************************************************/

#endif // _STOCK_LOGGER_HPP__
