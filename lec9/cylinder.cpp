// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "cylinder.hpp"

#include <cmath>
#include <stdexcept>

/*****************************************************************************/


Cylinder::Cylinder ( Circle _base, double _height )
	:    m_base( _base ), 
	    m_height( _height )
{
	if ( m_height <= 0.0 )
		throw std::logic_error( "Cylinder height must be positive" );
}


/*****************************************************************************/


double Cylinder::getVolume () const
{
	return m_base.getArea() * m_height;
}


/*****************************************************************************/


double Cylinder::getSideSurfaceArea () const
{
	return m_base.getPerimeter() * m_height;
}


/*****************************************************************************/


double Cylinder::getFullSurfaceArea () const
{
	return getSideSurfaceArea() + 2.0 * m_base.getArea();
}


/*****************************************************************************/


Point3D Cylinder::getPointOnSurface ( double _angle, double _height ) const
{
	Point3D circlePoint = m_base.getPointOn( _angle );
	return Point3D( circlePoint.getX(), circlePoint.getY(), circlePoint.getZ() + _height );
}


/*****************************************************************************/
