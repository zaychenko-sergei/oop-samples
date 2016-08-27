// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "parking.hpp"

#include <stdexcept>

/*****************************************************************************/


Parking::Parking ( int _nPlaces )
	:    m_nPlaces( _nPlaces )
{
}


/*****************************************************************************/


void Parking::park ( const Vehicle & _v )
{
	if ( ! getNumFreePlaces() )
		throw std::logic_error( "No free spaces left on the parking!" );

	if ( m_parkedVehicles.count( &_v ) )
		throw std::logic_error( "This vehicle is already parked" );

	m_parkedVehicles.insert( &_v );
}


/*****************************************************************************/


void Parking::leave ( const Vehicle & _v )
{
	auto it = m_parkedVehicles.find( &_v );
	if ( it == m_parkedVehicles.end() )
		throw std::logic_error( "The vehicle is not parked here" );

	m_parkedVehicles.erase( it );
}


/*****************************************************************************/

