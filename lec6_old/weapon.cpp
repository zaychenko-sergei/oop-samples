// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "weapon.hpp"
#include "weapontype.hpp"

/*****************************************************************************/


Weapon::Weapon ( const WeaponType & _type, int _initialAmmo )
	: m_type( _type )
	, m_currentAmmo( _initialAmmo )
{
}


//************************************************************************


bool Weapon::hasFullAmmo () const
{
	return m_currentAmmo == getType().getMaxAmmo();
}


//************************************************************************


bool Weapon::hasNoAmmo () const
{
	return m_currentAmmo == 0;
}


//************************************************************************


int Weapon::loadAmmo ( int _ammo )
{
	int maxAmmo = getType().getMaxAmmo();
	int freeAmmoSpace = maxAmmo - m_currentAmmo;

	if ( _ammo >= freeAmmoSpace )
	{
		m_currentAmmo = maxAmmo;
		return _ammo - freeAmmoSpace;
	}
	else
	{
		m_currentAmmo += _ammo;
		return 0;
	}
}


//************************************************************************


bool Weapon::tryShoot ()
{
	if ( hasNoAmmo() )
		return false;

	--m_currentAmmo;
	return true;
}


//************************************************************************

