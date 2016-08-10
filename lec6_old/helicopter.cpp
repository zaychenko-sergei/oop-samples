// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "helicopter.hpp"
#include "weapon.hpp"

#include <stdexcept>

/*****************************************************************************/


Helicopter::Helicopter (
    int _machineID, 
    Vector3D _initialAngle, 
    Point3D _initialPosition
)
	:    m_machineID( _machineID )
	,    m_currentAngle( _initialAngle )
	,    m_position( _initialPosition )
	,    m_pWeapon( nullptr )
{
}


/*****************************************************************************/


Helicopter::~Helicopter ()
{
	delete m_pWeapon;
}


/*****************************************************************************/


void Helicopter::installWeapon ( Weapon & _weapon )
{
	if ( hasWeapon() )
		throw std::logic_error( "Weapon is already installed on the helicopter" );

	m_pWeapon = &_weapon;
}


/*****************************************************************************/


void Helicopter::deinstallWeapon ()
{
	if ( ! hasWeapon() )
		throw std::logic_error( "Weapon was not installed on the helicopter" );

	m_pWeapon = nullptr;
}


/*****************************************************************************/


bool Helicopter::tryShootingTargetAt ( Point3D _p )
{
	if ( !hasWeapon() )
		return false;

	turnTo(
		Vector3D(
			_p.getX() - m_position.getX(),
			_p.getY() - m_position.getY(),
			_p.getZ() - m_position.getZ()
			)
		);

	return m_pWeapon->tryShoot();
}


/*****************************************************************************/
