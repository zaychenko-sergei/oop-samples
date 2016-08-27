// (C) 2013-2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _HELICOPTERPAD_V2_HPP_
#define _HELICOPTERPAD_V2_HPP_

/*****************************************************************************/

#include "point3d.hpp"

#include <vector>

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

	int getRegisteredLandingsCount () const;

	Helicopter & getRegisteredLanded ( int _index ) const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	const Point3D m_location;

	Helicopter * m_pLanded;

	std::vector< Helicopter * > m_landingHistory;

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

#endif // _HELICOPTERPAD_V2_HPP_


