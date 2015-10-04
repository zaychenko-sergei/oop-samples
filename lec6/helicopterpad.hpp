// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _HELICOPTERPAD_HPP_
#define _HELICOPTERPAD_HPP_

/*****************************************************************************/

#include "point3d.hpp"

/*****************************************************************************/

class Helicopter;

/*****************************************************************************/


class HelicopterPad
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	HelicopterPad ( Point3D _location );

	HelicopterPad ( const HelicopterPad & ) = delete;
	HelicopterPad & operator = ( const HelicopterPad & ) = delete;

	Point3D getLocation () const;

	bool hasLanded () const;

	Helicopter * getLanded () const;

	void land ( Helicopter & _helicopter );

	void unland ();

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	const Point3D m_location;

	Helicopter * m_pLanded;

/*-----------------------------------------------------------------*/

};

/*****************************************************************************/


inline Point3D
HelicopterPad::getLocation () const
{
	return m_location;
}


/*****************************************************************************/


inline bool HelicopterPad::hasLanded () const
{
	return m_pLanded != nullptr;
}


/*****************************************************************************/


inline Helicopter *
HelicopterPad::getLanded () const
{
	return m_pLanded;
}


/*****************************************************************************/

#endif // _HELICOPTERPAD_HPP_


