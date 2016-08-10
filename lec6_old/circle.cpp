// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "circle.hpp"

#define _USE_MATH_DEFINES // <- необходимо для работы с константой M_PI
#include <cmath>

#include <stdexcept>

/*****************************************************************************/


Circle::Circle ( Point3D _center, double _radius )
	:	m_center( _center ),
		m_radius( _radius )
{
	if ( m_radius <= 0.0 )
		throw std::logic_error( "Circle radius must be positive" );
}


/*****************************************************************************/


double Circle::getPerimeter () const
{
	return 2.0 * M_PI * m_radius;
}


/*****************************************************************************/


double Circle::getArea () const
{
	return M_PI * m_radius * m_radius;
}


/*****************************************************************************/


Point3D Circle::getPointOn ( double _angle ) const
{
	double xOffset = m_radius * cos( _angle );
	double yOffset = m_radius * sin( _angle );

	return Point3D( 
        m_center.getX() + xOffset,
		m_center.getY() + yOffset,
		m_center.getZ()
    );
}


/*****************************************************************************/


