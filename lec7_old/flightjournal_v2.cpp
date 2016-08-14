// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "flightjournal_v2.hpp"
#include "helicopter.hpp"

//************************************************************************


FlightJournalV2::FlightJournalV2 ( const Helicopter & _helicopter )
	:    m_helicopter( _helicopter )
{
}


//************************************************************************


Point3D FlightJournalV2::getPosition ( int _index ) const
{
	return m_positions.at( _index );
}


//************************************************************************


void FlightJournalV2::trackPosition ()
{
	Point3D currentPosition = m_helicopter.getCurrentPosition();
	m_positions.push_back( currentPosition );
}


//************************************************************************


double FlightJournalV2::totalDistance () const
{
	double result = 0.0;
	int nPositions = m_positions.size();
	for ( int i = 0; i <nPositions - 1; i++ )
		result += m_positions[ i ].distanceTo( m_positions[ i + 1 ] );
	return result;
}


//************************************************************************

