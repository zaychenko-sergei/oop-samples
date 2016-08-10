// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _POLYGON_HPP
#define _POLYGON_HPP

/*****************************************************************************/

#include "point3d.hpp"

/*****************************************************************************/


class Polygon
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Polygon ( int _nPoints );

	Polygon ( const Polygon & _p );

	Polygon ( Polygon && _p );

	~Polygon ();

	Polygon & operator = ( const Polygon & _p );

	Polygon & operator = ( Polygon && _p );

	int getNPoints () const;

	const Point3D & getPoint ( int index ) const;
	Point3D & getPoint ( int _index );

	double getPerimeter () const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	Point3D * m_points;

	int m_nPoints;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline int Polygon::getNPoints () const
{
	return m_nPoints;
}


/*****************************************************************************/

#endif // _POLYGON_HPP