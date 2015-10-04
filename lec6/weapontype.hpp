// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _WEAPONTYPE_HPP
#define _WEAPONTYPE_HPP

/*****************************************************************************/


class WeaponType
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	WeaponType ( double _caliber, int _maxAmmo );

	WeaponType ( const WeaponType & ) = delete;
	WeaponType & operator = ( const WeaponType & ) = delete;

	double getCaliber () const;

	int getMaxAmmo () const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	const double m_caliber;

	const int m_maxAmmo;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline double
WeaponType::getCaliber () const
{
	return m_caliber;
}


/*****************************************************************************/


inline int 
WeaponType::getMaxAmmo () const
{
	return m_maxAmmo;
}


/*****************************************************************************/

#endif // _WEAPONTYPE_HPP