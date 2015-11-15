// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _HELICOPTER_HPP_
#define _HELICOPTER_HPP_

/*****************************************************************************/

#include "point3d.hpp"

/*****************************************************************************/


// Simplified version ...
class Helicopter
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Helicopter ( Point3D _initialPosition = Point3D() );

	Helicopter ( const Helicopter & ) = delete;
	Helicopter & operator = ( const Helicopter & ) = delete;

	Point3D getCurrentPosition () const;

	void moveTo ( Point3D _p );

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	Point3D m_position;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline 
Helicopter::Helicopter ( Point3D _initialPosition )
	:	m_position( _initialPosition )
{
}


/*****************************************************************************/


inline Point3D
Helicopter::getCurrentPosition () const
{
	return m_position;
}


/*****************************************************************************/


inline void
Helicopter::moveTo ( Point3D _p )
{
	m_position = _p;
}


/*****************************************************************************/

#endif // _HELICOPTER_HPP_

