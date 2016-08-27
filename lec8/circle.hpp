// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _CIRCLE_HPP
#define _CIRCLE_HPP

/*****************************************************************************/

#include "point3d.hpp"

/*****************************************************************************/


class Circle
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Circle ( Point3D _center, double _radius );

	Point3D getCenter () const;

	double getRadius () const;

	double getPerimeter () const;

	double getArea () const;

	Point3D getPointOn ( double _angle ) const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	Point3D m_center;

	double m_radius;

/*-----------------------------------------------------------------*/

};

/*****************************************************************************/


inline Point3D
Circle::getCenter () const
{
	return m_center;
}


/*****************************************************************************/


inline double
Circle::getRadius () const
{
	return m_radius;
}


/*****************************************************************************/

#endif // _CIRCLE_HPP