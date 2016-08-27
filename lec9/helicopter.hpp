// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _HELICOPTER_HPP_
#define _HELICOPTER_HPP_

/*****************************************************************************/

#include "point3d.hpp"
#include "vector3d.hpp"

/*****************************************************************************/

class Weapon;

/*****************************************************************************/


class Helicopter
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/


	Helicopter (
		int _machineID,
		Vector3D _initialAngle = Vector3D(), 
		Point3D _initialPosition = Point3D()
	);


	Helicopter ( const Helicopter & ) = delete;
	Helicopter & operator = ( const Helicopter & ) = delete;

	~Helicopter ();

	int getMachineID () const;

	bool hasWeapon () const;

	Weapon * getWeapon () const;

	void installWeapon ( Weapon & _weapon );

	void deinstallWeapon ();

	bool tryShootingTargetAt ( Point3D _p );

	Point3D getCurrentPosition () const;

	void moveTo ( Point3D _p );

	Vector3D getCurrentAngle () const;

	void turnTo ( Vector3D _angle );

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	Weapon * m_pWeapon;

	Vector3D m_currentAngle;

	Point3D m_position;

	const int m_machineID;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline int
Helicopter::getMachineID () const
{
	return m_machineID;
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


inline Vector3D
Helicopter::getCurrentAngle () const
{
	return m_currentAngle;
}


/*****************************************************************************/


inline void
Helicopter::turnTo ( Vector3D _angle )
{
	m_currentAngle = _angle;
}


/*****************************************************************************/


inline
bool Helicopter::hasWeapon () const
{
	return m_pWeapon != nullptr;
}


/*****************************************************************************/


inline
Weapon * Helicopter::getWeapon () const
{
	return m_pWeapon;
}


/*****************************************************************************/

#endif // _HELICOPTER_HPP_

