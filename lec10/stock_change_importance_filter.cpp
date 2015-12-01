// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "stock_change_importance_filter.hpp"
#include "stock.hpp"

#include <cmath>

/*****************************************************************************/


StockChangeImportanceFilter::StockChangeImportanceFilter (
		double _minimalChange
	,	StockChangeListener & _childListener
)
	:	m_minimalChange( _minimalChange )
	,	m_childListener( _childListener )
{
}


/*****************************************************************************/


void 
StockChangeImportanceFilter::onPriceChanged ( Stock & _s, double _oldPrice )
{
	double change = fabs( _s.getCurrentPrice() - _oldPrice );
	if ( change >= m_minimalChange )
		m_childListener.onPriceChanged( _s, _oldPrice );
}


/*****************************************************************************/
