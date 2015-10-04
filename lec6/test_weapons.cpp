// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "weapon.hpp"
#include "weapontype.hpp"

#include <cassert>

/*****************************************************************************/


int main ()
{
	WeaponType * pType = new WeaponType( 125.0, 5 );

	Weapon * pWeapon1 = new Weapon( *pType );
	Weapon * pWeapon2 = new Weapon( *pType );

	int totalAmmo = 100;
	totalAmmo = pWeapon1->loadAmmo( totalAmmo );
	assert( totalAmmo == ( 100 - pType->getMaxAmmo() ) );

	pWeapon2->loadAmmo( 1 );

	assert( pWeapon1->getCurrentAmmo() == pType->getMaxAmmo() );
	bool success = pWeapon1->tryShoot();
	assert( success && pWeapon1->getCurrentAmmo() == ( pType->getMaxAmmo() - 1 ) );

	assert( pWeapon2->getCurrentAmmo() == 1 );
	success = pWeapon2->tryShoot();
	assert( success && pWeapon2->hasNoAmmo() );

	success = pWeapon2->tryShoot();
	assert( !success );

	delete pWeapon1;
	delete pWeapon2;
	delete pType;
}


/*****************************************************************************/
