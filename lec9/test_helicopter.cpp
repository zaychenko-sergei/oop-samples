// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "helicopter.hpp"
#include "weapontype.hpp"
#include "weapon.hpp"

#include <cassert>

/*****************************************************************************/

int main ()
{
	// ������� ��� �������-���������
	Helicopter * pHelicopter1 = new Helicopter( 1 );
	Helicopter * pHelicopter2 = new Helicopter( 2 );

	// ������� ��� ������
	WeaponType * pWeaponType = new WeaponType( 125.0, 5 );

	// ��������� ������ �������� ������� � ����� ��������� �������
	pHelicopter1->installWeapon( *new Weapon( *pWeaponType, 1 ) );
	assert( pHelicopter1->getWeapon()->getCurrentAmmo() == 1 );

	// ������� ���������� c ������� ���������.
	// ������ ������� �������, � ������ ���������.
	bool result = pHelicopter1->tryShootingTargetAt( Point3D( 2.0, 2.0, 2.0 ) );
	assert( result && pHelicopter1->getWeapon()->hasNoAmmo() );

	// ������� ���������� ��� ��� � ������� ���������.
	// ������ ������� ����������� ��������, ��������� ��� ������� � ������
	result = pHelicopter1->tryShootingTargetAt( Point3D( 3.0, 3.0, 3.0 ) );
	assert( !result );

	// ������� ���������� �� ������� ���������, ������ ������ �������,
	// ��������� �������� ������ �� ��� �� �����������
	result = pHelicopter2->tryShootingTargetAt( Point3D( 4.0, 4.0, 4.0 ) );
	assert( !result );

	// ���� �� ���������� ���� ����� ����������?
	// - ������ �������� ����� ����������, � �������������� ����� �������� ��������,
	// ��������������, ��� ��� ��������� � ������� ���������� ��������� ����
	// - ������ �������� �� ����� �������������� ������, � �� ��������������
	assert( pHelicopter1->getCurrentAngle() == Vector3D( 3.0, 3.0, 3.0 ) );
	assert( pHelicopter2->getCurrentAngle() == Vector3D( 0.0, 0.0, 0.0 ) );

	// ���������� ��� ���������. ������ ������������ ������ � ������ ����������
	delete pHelicopter1;
	delete pHelicopter2;

	// ���������� ��� ������
	delete pWeaponType;
}

/*****************************************************************************/
