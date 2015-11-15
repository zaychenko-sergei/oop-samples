// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "helicopterpad.hpp"
#include "helicopter.hpp"
#include "point3d.hpp"

#include <stdexcept>

/*****************************************************************************/


HelicopterPad::HelicopterPad ( Point3D _location )
    :   m_location( _location ),
        m_pLanded( nullptr )
{
}


/*****************************************************************************/


void HelicopterPad::land ( Helicopter & _helicopter )
{
	if ( m_pLanded )
		throw std::logic_error( "Something has already landed on this pad" );

	_helicopter.moveTo( getLocation() );
	m_pLanded = &_helicopter;

	m_landingHistory.push_back( m_pLanded );
}


/*****************************************************************************/


void HelicopterPad::unland ()
{
	if ( ! m_pLanded )
		throw std::logic_error( "No helicopter is currently landed" );

	m_pLanded->moveTo(
		Point3D(
			getLocation().getX(),
			getLocation().getY(),
			getLocation().getZ() + 7.0
		)
	);

	m_pLanded = nullptr;
}


/*****************************************************************************/


int HelicopterPad::getRegisteredLandingsCount () const
{
	return m_landingHistory.size();
}


//************************************************************************


Helicopter & HelicopterPad::getRegisteredLanded ( int _index ) const
{
	return *m_landingHistory.at( _index );
}


//************************************************************************
