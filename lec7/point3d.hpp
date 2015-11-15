// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _POINT3D_HPP
#define _POINT3D_HPP

/*****************************************************************************/


class Point3D
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Point3D ();

	Point3D ( double _x, double _y, double _z );

	double getX () const;
	double getY () const;
	double getZ () const;

	double distanceTo ( Point3D ) const;

	bool operator == ( Point3D _p ) const;
	bool operator != ( Point3D _p ) const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	double m_x, m_y, m_z;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline double 
Point3D::getX () const
{
	return m_x;
}


/*****************************************************************************/


inline double 
Point3D::getY () const
{
	return m_y;
}


/*****************************************************************************/


inline double
Point3D::getZ () const
{
	return m_z;
}


/*****************************************************************************/

#endif //  _POINT3D_HPP