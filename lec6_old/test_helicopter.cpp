// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "helicopter.hpp"
#include "weapontype.hpp"
#include "weapon.hpp"

#include <cassert>

/*****************************************************************************/

int main ()
{
	// —оздаем два объекта-вертолета
	Helicopter * pHelicopter1 = new Helicopter( 1 );
	Helicopter * pHelicopter2 = new Helicopter( 2 );

	// —оздаем тип оруди€
	WeaponType * pWeaponType = new WeaponType( 125.0, 5 );

	// ¬ооружаем первый вертолет орудием с одним начальным зар€дом
	pHelicopter1->installWeapon( *new Weapon( *pWeaponType, 1 ) );
	assert( pHelicopter1->getWeapon()->getCurrentAmmo() == 1 );

	// ѕробуем выстрелить c первого вертолета.
	// ѕервый выстрел успешен, а орудие разр€жено.
	bool result = pHelicopter1->tryShootingTargetAt( Point3D( 2.0, 2.0, 2.0 ) );
	assert( result && pHelicopter1->getWeapon()->hasNoAmmo() );

	// ѕробуем выстрелить еще раз с первого вертолета.
	// ¬торой выстрел завершаетс€ неудачей, поскольку нет зар€дов в орудии
	result = pHelicopter1->tryShootingTargetAt( Point3D( 3.0, 3.0, 3.0 ) );
	assert( !result );

	// ѕробуем выстрелить со второго вертолета, однако терпим неудачу,
	// поскольку никакого оруди€ на нем не установлено
	result = pHelicopter2->tryShootingTargetAt( Point3D( 4.0, 4.0, 4.0 ) );
	assert( !result );

	//  уда же направлены носы наших вертолетов?
	// - первый вертолет имеет вооружение, и поворачиваетс€ перед попыткой выстрела,
	// соответственно, его нос направлен в сторону координаты последней цели
	// - второй вертолет не имеет установленного оруди€, и не поворачиваетс€
	assert( pHelicopter1->getCurrentAngle() == Vector3D( 3.0, 3.0, 3.0 ) );
	assert( pHelicopter2->getCurrentAngle() == Vector3D( 0.0, 0.0, 0.0 ) );

	// ”ничтожаем оба вертолета. ќрудие уничтожаетс€ вместе с первым вертолетом
	delete pHelicopter1;
	delete pHelicopter2;

	// ”ничтожаем тип оруди€
	delete pWeaponType;
}

/*****************************************************************************/
