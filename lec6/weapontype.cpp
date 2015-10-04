// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "weapontype.hpp"

#include <stdexcept>

/*****************************************************************************/


WeaponType::WeaponType ( double _caliber, int _maxAmmo )
	:   m_caliber( _caliber ),
	    m_maxAmmo( _maxAmmo )
{
	if ( _caliber <= 0.0 )
		throw std::logic_error( "Expecting a positive caliber" );

	if ( _maxAmmo < 1 )
		throw std::logic_error( "Expecting at least 1 as a maximum ammo" );
}


/*****************************************************************************/
