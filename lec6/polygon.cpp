// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "polygon.hpp"

#include <stdexcept>

/*****************************************************************************/


Polygon::Polygon ( int _nPoints )
	:    m_nPoints( _nPoints )
{
	if ( _nPoints < 3 )
		throw std::logic_error( "Expecting at least 3 points in polygon" );

	m_points = new Point3D[ m_nPoints ];
}


/*****************************************************************************/


Polygon::Polygon ( const Polygon & _p )
{
	m_nPoints = _p.m_nPoints;
	m_points = new Point3D[ m_nPoints ];

	for ( int i = 0; i < m_nPoints; i++ )
		m_points[ i ] = _p.m_points[ i ];
}


/*****************************************************************************/


Polygon::Polygon ( Polygon && _p )
{
	m_nPoints   = _p.m_nPoints;
	m_points    = _p.m_points;
	_p.m_points = nullptr;
}


/*****************************************************************************/


Polygon::~Polygon ()
{
	delete[] m_points;
}


/*****************************************************************************/


Polygon & Polygon::operator = ( Polygon const & _p )
{
	if ( this == &_p )
		return *this;

	delete[] m_points;

	m_nPoints = _p.m_nPoints;
	m_points  = new Point3D[ m_nPoints ];

	for ( int i = 0; i < m_nPoints; i++ )
		m_points[ i ] = _p.m_points[ i ];

	return *this;
}


/*****************************************************************************/


Polygon & Polygon::operator = ( Polygon && _p )
{
	if ( this == &_p )
		return *this;

	std::swap( m_points, _p.m_points );
	std::swap( m_nPoints, _p.m_nPoints );

	return *this;
}


/*****************************************************************************/


const Point3D & Polygon::getPoint ( int _index ) const
{
	if ( _index >= 0 && _index < getNPoints() )
		return m_points[ _index ];
	else
		throw std::logic_error( "Point index is out of range" );
}


/*****************************************************************************/


Point3D & Polygon::getPoint ( int _index )
{
	if ( _index >= 0 && _index < getNPoints() )
		return m_points[ _index ];
	else
		throw std::logic_error( "Point index is out of range" );
}


/*****************************************************************************/


double Polygon::getPerimeter () const
{
	double total = 0.0;
	for ( int i = 0; i < m_nPoints - 1; i++ )
		total += m_points[ i ].distanceTo( m_points[ i + 1 ] );
	return total;
}


/*****************************************************************************/
