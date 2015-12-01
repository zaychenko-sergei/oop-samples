// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _STOCK_CHANGE_IMPORTANCE_FILTER_HPP__
#define _STOCK_CHANGE_IMPORTANCE_FILTER_HPP__

/*****************************************************************************/

#include "stock_change_listener.hpp"

/*****************************************************************************/


class StockChangeImportanceFilter
	:	public StockChangeListener
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	StockChangeImportanceFilter ( double _minimalChange, StockChangeListener & _childListener );

	void onPriceChanged ( Stock & _s, double _oldPrice ) override;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	const double m_minimalChange;

	StockChangeListener & m_childListener;

/*-----------------------------------------------------------------*/

};

/*****************************************************************************/

#endif // _STOCK_CHANGE_IMPORTANCE_FILTER_HPP__