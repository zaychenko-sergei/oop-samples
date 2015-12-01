// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "stock_biggest_change_recorder.hpp"
#include "stock.hpp"

/*****************************************************************************/


BiggestChangeRecorder::BiggestChangeRecorder()
	:	m_maxPositiveChange( 0.0 )
	,	m_maxNegativeChange( 0.0 )
{
}


/*****************************************************************************/


void BiggestChangeRecorder::onPriceChanged ( Stock & _s, double _oldPrice )
{
	double priceChange = _s.getCurrentPrice() - _oldPrice;
	if ( priceChange > 0 )
	{
		if ( m_maxPositiveChange < priceChange )
			m_maxPositiveChange = priceChange;
	}
	else
	{
		priceChange = -priceChange;
		if ( m_maxNegativeChange < priceChange )
			m_maxNegativeChange = priceChange;
	}
}


/*****************************************************************************/
