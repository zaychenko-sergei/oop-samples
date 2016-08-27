// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _STOCK_HPP_
#define _STOCK_HPP_

/*****************************************************************************/

#include <vector>
#include <string>

/*****************************************************************************/

class StockChangeListener;

/*****************************************************************************/

class Stock
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Stock ( std::string const & _title, double _initialPrice );

	Stock ( const Stock & _s ) = delete;

	Stock & operator = ( const Stock & _s ) = delete;

	std::string const & getTitle () const;

	double getCurrentPrice () const;

	void updatePrice ( double _newPrice );

	void addChangeListener ( StockChangeListener & _listener );

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	std::vector< StockChangeListener * > m_listeners;

	std::string const m_title;

	double m_currentPrice;

/*-----------------------------------------------------------------*/

};

/*****************************************************************************/


inline std::string const &
Stock::getTitle () const
{
	return m_title;
}


/*****************************************************************************/


inline double
Stock::getCurrentPrice () const
{
	return m_currentPrice;
}


/*****************************************************************************/

#endif // _STOCK_HPP_
