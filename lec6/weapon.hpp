// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _WEAPON_HPP_
#define _WEAPON_HPP_

/*****************************************************************************/

class WeaponType;

/*****************************************************************************/


class Weapon
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Weapon ( const WeaponType & _type, int _initialAmmo = 0 );

	Weapon ( const Weapon & ) = delete;
	Weapon & operator = ( const Weapon & ) = delete;

	const WeaponType & getType () const;

	int getCurrentAmmo () const;

	int loadAmmo ( int _ammo );

	bool hasFullAmmo () const;
	bool hasNoAmmo () const;

	bool tryShoot ();

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	const WeaponType & m_type;

	int m_currentAmmo;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline const WeaponType &
Weapon::getType () const
{
	return m_type;
}


/*****************************************************************************/


inline int
Weapon::getCurrentAmmo () const
{
	return m_currentAmmo;
}


/*****************************************************************************/

#endif // _WEAPON_HPP_