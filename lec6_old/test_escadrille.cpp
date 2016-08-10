// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "helicopterescadrille.hpp"
#include "helicopter.hpp"

#include <cassert>

/*****************************************************************************/


int main ()
{
	HelicopterEscadrille * pEscadrille = new HelicopterEscadrille( 3 );

	Helicopter * pHelicopter1 = new Helicopter( 1 );
	Helicopter * pHelicopter2 = new Helicopter( 2 );
	Helicopter * pHelicopter3 = new Helicopter( 3 );

	pEscadrille->join( *pHelicopter1 );
	pEscadrille->join( *pHelicopter2 );
	pEscadrille->join( *pHelicopter3 );

	assert( pEscadrille->getJoinedUnitsCount() == 3 );

	pEscadrille->leave( *pHelicopter2 );

	assert( pEscadrille->getJoinedUnitsCount() == 2 );

	pEscadrille->onUnitDestroyed( pHelicopter1 );

	assert( pEscadrille->getJoinedUnitsCount() == 1 );

	Helicopter * pHelicopter4 = new Helicopter( 4 );
	pEscadrille->join( *pHelicopter4 );

	assert( pEscadrille->getJoinedUnitsCount() == 2 );

	assert( pEscadrille->findHelicopter( *pHelicopter4 ) == 0 );

	delete pEscadrille;
	delete pHelicopter2;
}


pEscadrille->onUnitDestroyed( pHelicopter1 );

