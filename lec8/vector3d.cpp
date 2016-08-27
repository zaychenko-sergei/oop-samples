// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "vector3d.hpp"

/*****************************************************************************/


Vector3D::Vector3D ()
	:    m_x( 0.0 ), m_y( 0.0 ), m_z( 0.0 )
{}


/*****************************************************************************/


Vector3D::Vector3D ( double _x, double _y, double _z )
	:    m_x( _x ), m_y( _y ), m_z( _z )
{}


/*****************************************************************************/


bool Vector3D::operator == ( Vector3D _v ) const
{
	return m_x == _v.GetX() && m_y == _v.GetY() && m_z == _v.GetZ();
}


/*****************************************************************************/


bool Vector3D::operator != ( Vector3D _v ) const
{
	return !( *this == _v );
}


/*****************************************************************************/


Vector3D & Vector3D::operator += ( Vector3D _v )
{
	m_x += _v.GetX();
	m_y += _v.GetY();
	m_z += _v.GetZ();

	return *this;
}

/*****************************************************************************/


Vector3D Vector3D::operator + ( Vector3D _v ) const
{
	Vector3D result = *this;
	result += _v;
	return result;
}


/*****************************************************************************/


Vector3D Vector3D::operator - ( Vector3D _v ) const
{
	return Vector3D( m_x - _v.GetX(), m_y - _v.GetY(), m_z - _v.GetZ() );
}


/*****************************************************************************/


Vector3D & Vector3D::operator -= ( Vector3D _v )
{
	Vector3D temp = *this - _v;
	*this = temp;
	return *this;
}


/*****************************************************************************/


Vector3D & Vector3D::operator *= ( double _multiplier )
{
	m_x *= _multiplier;
	m_y *= _multiplier;
	m_z *= _multiplier;

	return *this;
}


/*****************************************************************************/


Vector3D Vector3D::operator * ( double _multiplier ) const
{
	Vector3D result = *this;
	result *= _multiplier;
	return result;
}


/*****************************************************************************/


double Vector3D::operator * ( Vector3D _v ) const
{
	return m_x * _v.GetX() + m_y * _v.GetY() + m_z * _v.GetZ();
}


/*****************************************************************************/

