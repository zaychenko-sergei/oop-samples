// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _CYLINDER_HPP
#define _CYLINDER_HPP

/*****************************************************************************/

#include "circle.hpp"

/*****************************************************************************/


class Cylinder
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Cylinder ( Circle _base, double _height );

	Circle getBase () const;

	double getHeight () const;

	double getVolume () const;

	double getSideSurfaceArea () const;

	double getFullSurfaceArea () const;

	Point3D getPointOnSurface ( double _angle, double _height ) const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/
	
	Circle m_base;

	double m_height;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline Circle
Cylinder::getBase () const
{
	return m_base;
}


/*****************************************************************************/


inline double
Cylinder::getHeight () const
{
	return m_height;
}


/*****************************************************************************/

#endif // _CYLINDER_HPP