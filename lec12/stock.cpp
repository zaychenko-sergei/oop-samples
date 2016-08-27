// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "stock.hpp"
#include "stock_change_listener.hpp"

/*****************************************************************************/


Stock::Stock ( std::string const & _title, double _initialPrice )
	:	m_title( _title )
	,	m_currentPrice( _initialPrice )
{
}


/*****************************************************************************/


void Stock::addChangeListener ( StockChangeListener & _listener )
{
	m_listeners.push_back( &_listener );
}


/*****************************************************************************/


void Stock::updatePrice ( double _newPrice )
{
	if ( m_currentPrice == _newPrice )
		return;

	double oldPrice = m_currentPrice;
	m_currentPrice = _newPrice;

	for ( StockChangeListener * pListener : m_listeners )
		pListener->onPriceChanged( * this, oldPrice );
}


/*****************************************************************************/

