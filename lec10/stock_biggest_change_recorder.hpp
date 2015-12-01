// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _STOCK_BIGGEST_CHANGE_RECORDER_HPP__
#define _STOCK_BIGGEST_CHANGE_RECORDER_HPP__

/*****************************************************************************/

#include "stock_change_listener.hpp"

/*****************************************************************************/


class BiggestChangeRecorder
	:	public StockChangeListener
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	BiggestChangeRecorder();

	double getMaxPositiveChange () const;

	double getMaxNegativeChange () const;

	void onPriceChanged ( Stock & _s, double _oldPrice ) override;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	double m_maxPositiveChange, m_maxNegativeChange;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline double
BiggestChangeRecorder::getMaxPositiveChange () const 
{ 
	return m_maxPositiveChange; 
}


/*****************************************************************************/


inline double 
BiggestChangeRecorder::getMaxNegativeChange () const
{
	return m_maxNegativeChange;
}


/*****************************************************************************/

#endif // _STOCK_BIGGEST_CHANGE_RECORDER_HPP__

