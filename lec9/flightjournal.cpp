// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "flightjournal.hpp"
#include "helicopter.hpp"

#include <stdexcept>

/*****************************************************************************/


FlightJournal::FlightJournal ( const Helicopter & _helicopter, int _nMaxPositions )
	:	m_helicopter( _helicopter )
	,	m_nMaxPositions( _nMaxPositions )
	,	m_nUsedPositions( 0 )
{
	if ( m_nMaxPositions < 1 )
		throw std::logic_error( "Number of positions must be positive" );

	m_pPositions = new Point3D[ m_nMaxPositions ];
}


/*****************************************************************************/


FlightJournal::~FlightJournal ()
{
	delete[] m_pPositions;
}


/*****************************************************************************/


Point3D FlightJournal::getPosition ( int _index ) const
{
	if ( _index >= 0 && _index < m_nUsedPositions )
		return m_pPositions[ _index ];

	else
		throw std::logic_error( "Position index is out of range" );
}


/*****************************************************************************/


void FlightJournal::track ()
{
	if ( m_nUsedPositions == m_nMaxPositions )
		throw std::logic_error( "No space left in the journal" );

	Point3D currentPosition = m_helicopter.getCurrentPosition();
	m_pPositions[ m_nUsedPositions++ ] = currentPosition;
}


/*****************************************************************************/


double FlightJournal::totalDistance () const
{
	double result = 0.0;
	for ( int i = 0; i < m_nUsedPositions - 1; i++ )
		result += m_pPositions[ i ].distanceTo( m_pPositions[ i + 1 ] );
	return result;
}


/*****************************************************************************/
