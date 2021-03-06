// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _STOCK_CHANGE_LISTENER_HPP_
#define _STOCK_CHANGE_LISTENER_HPP_

/*****************************************************************************/

class Stock;

/*****************************************************************************/

class StockChangeListener
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	virtual void onPriceChanged ( Stock & _s, double _oldPrice ) = 0;

/*-----------------------------------------------------------------*/

};

/*****************************************************************************/

#endif // _STOCK_CHANGE_LISTENER_HPP_

