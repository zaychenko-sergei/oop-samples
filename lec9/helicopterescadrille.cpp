// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "helicopterescadrille.hpp"
#include "helicopter.hpp"

#include <memory.h>
#include <stdexcept>

/*****************************************************************************/


HelicopterEscadrille::~HelicopterEscadrille ()
{
	for ( Helicopter * pHelicopter : m_helicopters )
		delete pHelicopter;
}


/*****************************************************************************/


Helicopter &
HelicopterEscadrille::getHelicopter ( int _index ) const
{
	return * m_helicopters.at( _index );
}


/*****************************************************************************/


int
HelicopterEscadrille::findHelicopter ( const Helicopter & _helicopter ) const
{
	int nHelicopters = m_helicopters.size();
	for ( int i = 0; i < nHelicopters; i++ )
		if ( m_helicopters[ i ] == ( &_helicopter ) )
			return i;

	return -1;
}


/*****************************************************************************/


void HelicopterEscadrille::join ( Helicopter * _pHelicopter )
{
	if ( findHelicopter( *_pHelicopter ) != -1 )
		throw std::logic_error( "Helicopter has already joined the escadrille" );

	m_helicopters.push_back( _pHelicopter );
}


/*****************************************************************************/


void HelicopterEscadrille::leave ( Helicopter & _helicopter )
{
	int position = findHelicopter( _helicopter );
	if ( position == -1 )
		throw std::logic_error( "Helicopter is not a part of this escadrille" );

	m_helicopters.erase( m_helicopters.begin() + position );
}


/*****************************************************************************/


void HelicopterEscadrille::onUnitDestroyed ( Helicopter * _pHelicopter )
{
	leave( *_pHelicopter );
	delete _pHelicopter;
}


/*****************************************************************************/


