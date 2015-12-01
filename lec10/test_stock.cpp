// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "stock.hpp"

#include "stock_logger.hpp"
#include "stock_biggest_change_recorder.hpp"
#include "stock_change_importance_filter.hpp"

#include <iostream>

/*****************************************************************************/


int main ()
{
	Stock st1( "Company A", 5.12 );
	Stock st2( "Company B", 7.13 );
	Stock st3( "Company C", 50.00 );

	StockLogger logger( std::cout );
	st1.addChangeListener( logger );
	st2.addChangeListener( logger );

	BiggestChangeRecorder recorder;
	st1.addChangeListener( recorder );
	st2.addChangeListener( recorder );

	StockChangeImportanceFilter filteredLogger( 10.00, logger );
	StockChangeImportanceFilter filteredRecorder( 20.00, recorder );
	st3.addChangeListener( filteredLogger );
	st3.addChangeListener( filteredRecorder );

	st1.updatePrice( 6.21 );
	st2.updatePrice( 7.09 );
	st1.updatePrice( 6.01 );
	st3.updatePrice( 55.00 );
	st3.updatePrice( 44.00 );

	std::cout << "Biggest positive change : "
		<< recorder.getMaxPositiveChange ()
		<< std::endl;

	std::cout << "Biggest negative change : "
		<< recorder.getMaxNegativeChange ()
		<< std::endl;
}


/*****************************************************************************/
