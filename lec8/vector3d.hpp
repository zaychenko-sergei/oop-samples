// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _VECTOR3D_HPP_
#define _VECTOR3D_HPP_

/*****************************************************************************/

class Vector3D
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Vector3D ();

	Vector3D ( double _x, double _y, double _z );

	double GetX () const;
	double GetY () const;
	double GetZ () const;

	bool operator == ( Vector3D _v ) const;
	bool operator != ( Vector3D _v ) const;

	Vector3D operator + ( Vector3D _v ) const;

	Vector3D & operator += ( Vector3D _v );

	Vector3D operator - ( Vector3D _v ) const;

	Vector3D & operator -= ( Vector3D _v );

	Vector3D operator * ( double _multiplier ) const;

	Vector3D & operator *= ( double _multiplier );

	double operator * ( Vector3D _v ) const;

/*-----------------------------------------------------------------*/

private:
	
/*-----------------------------------------------------------------*/

	double m_x, m_y, m_z;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline double Vector3D::GetX () const
{
	return m_x;
}


/*****************************************************************************/


inline double Vector3D::GetY () const
{
	return m_y;
}


/*****************************************************************************/


inline double Vector3D::GetZ () const
{
	return m_z;
}


/*****************************************************************************/


inline Vector3D operator * ( double _multiplier, Vector3D _v )
{
	return _v * _multiplier;
}


/*****************************************************************************/

#endif // _VECTOR3D_HPP_
