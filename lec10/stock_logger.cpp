// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "stock_logger.hpp"
#include "stock.hpp"

/*****************************************************************************/


StockLogger::StockLogger ( std::ostream & _stream )
	:	m_stream( _stream )
{}


/*****************************************************************************/


void 
StockLogger::onPriceChanged ( Stock & _s, double _oldPrice )
{
	m_stream 
		<< "\"" << _s.getTitle() << "\":"
		<< ( ( _oldPrice < _s.getCurrentPrice() ) ? "raising" : "falling" )
		<< ", old - " << _oldPrice
		<< ", new - " << _s.getCurrentPrice()
		<< std::endl;
}


/*****************************************************************************/
