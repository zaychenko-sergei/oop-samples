// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "point3d.hpp"

#include <cmath>

/*****************************************************************************/


Point3D::Point3D ()
	: m_x( 0.0 ), m_y( 0.0 ), m_z( 0.0 )
{}


/*****************************************************************************/


Point3D::Point3D ( double _x, double _y, double _z )
	: m_x( _x ), m_y( _y ), m_z( _z )
{
}


/*****************************************************************************/


double Point3D::distanceTo ( Point3D _p ) const
{
	double xDiff = _p.getX() - getX();
	double yDiff = _p.getY() - getY();
	double zDiff = _p.getZ() - getZ();
	return sqrt( xDiff * xDiff + yDiff * yDiff + zDiff * zDiff );
}


/*****************************************************************************/


bool Point3D::operator == ( Point3D _p ) const
{
	return getX() == _p.getX() && getY() == _p.getY() && getZ() == _p.getZ();
}


/*****************************************************************************/


bool Point3D::operator != ( Point3D _p ) const
{
	return !( *this == _p );
}


/*****************************************************************************/
