// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "helicopterpad.hpp"
#include "helicopter.hpp"

#include <cassert>

/*****************************************************************************/

int main ()
{
	HelicopterPad * pHeliPad = new HelicopterPad( Point3D( 1.0, 2.0, 0.0 ) );

	assert( !pHeliPad->hasLanded() );

	Helicopter * pHelicopter = new Helicopter( 1 );
	pHeliPad->land( *pHelicopter );

	assert( pHeliPad->hasLanded() && pHeliPad->getLanded() == pHelicopter );

	Point3D location = pHelicopter->getCurrentPosition();
	assert( location == pHeliPad->getLocation() );

	pHeliPad->unland();

	assert( ! pHeliPad->hasLanded() );

	Point3D newLocation = pHelicopter->getCurrentPosition();
	assert( newLocation.getX() == location.getX() &&
            newLocation.getY() == location.getY() &&
            newLocation.getZ() > location.getZ() );

	delete pHeliPad;
	delete pHelicopter;
}


/*****************************************************************************/
