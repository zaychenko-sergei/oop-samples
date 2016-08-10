// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "helicopterescadrille.hpp"
#include "helicopter.hpp"

#include <memory.h>
#include <stdexcept>

/*****************************************************************************/


HelicopterEscadrille::HelicopterEscadrille ( int _nMaxUnits )
	: m_nMaxUnits( _nMaxUnits )
{
	if ( m_nMaxUnits < 1 )
		throw std::logic_error( "Number of units in escadrille must be positive" );

	m_pUnits = new Helicopter * [ m_nMaxUnits ];
	memset( m_pUnits, 0, sizeof( Helicopter * ) * m_nMaxUnits );
}


/*****************************************************************************/


HelicopterEscadrille::~HelicopterEscadrille ()
{
	for ( int i = 0; i < m_nMaxUnits; i++ )
		delete m_pUnits[ i ];

	delete[] m_pUnits;
}


/*****************************************************************************/


Helicopter *
HelicopterEscadrille::getHelicopter ( int _index ) const
{
	if ( _index >= 0 && _index < getMaxUnitsCount() )
		return m_pUnits[ _index ];
	else
		throw std::logic_error( "Helicopter index is out of range" );
}


/*****************************************************************************/


int
HelicopterEscadrille::findHelicopter ( const Helicopter & _helicopter ) const
{
	const Helicopter * pHelicopter = &_helicopter;
	for ( int i = 0; i < m_nMaxUnits; i++ )
		if ( m_pUnits[ i ] == pHelicopter )
			return i;

	return -1;
}

/*****************************************************************************/


int HelicopterEscadrille::findFreeUnitPosition () const
{
	for ( int i = 0; i < m_nMaxUnits; i++ )
		if ( !m_pUnits[ i ] )
			return i;

	return -1;
}

/*****************************************************************************/


int HelicopterEscadrille::getJoinedUnitsCount () const
{
	int nUnits = 0;
	for ( int i = 0; i < m_nMaxUnits; i++ )
		if ( m_pUnits[ i ] )
			++nUnits;

	return nUnits;
}


/*****************************************************************************/


void HelicopterEscadrille::join ( Helicopter & _helicopter )
{
	if ( findHelicopter( _helicopter ) != -1 )
		throw std::logic_error( "Helicopter has already joined the escadrille" );

	int freePosition = findFreeUnitPosition();
	if ( freePosition == -1 )
		throw std::logic_error( "No free unit places left in the escadrille" );

	m_pUnits[ freePosition ] = &_helicopter;
}


/*****************************************************************************/


void HelicopterEscadrille::leave ( Helicopter & _helicopter )
{
	int position = findHelicopter( _helicopter );
	if ( position == -1 )
		throw std::logic_error( "Helicopter is not a part of this escadrille" );

	m_pUnits[ position ] = nullptr;
}


/*****************************************************************************/


void HelicopterEscadrille::onUnitDestroyed ( Helicopter * _pHelicopter )
{
	leave( *_pHelicopter );
	delete _pHelicopter;
}


/*****************************************************************************/


