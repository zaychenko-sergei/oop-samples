// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "bus.hpp"
#include "truck.hpp"

#include <vector>
#include <cassert>
#include <iostream>

/*****************************************************************************/


float getTotalMaxWeight ( std::vector< Vehicle * > const & _vehicles )
{
    float totalMaxWeight = 0.0;

    for ( Vehicle const * pVehicle : _vehicles )
    {
        totalMaxWeight += pVehicle->getWeight();
		totalMaxWeight += pVehicle->getMaxExtraWeight();
    }

    return totalMaxWeight;
}


/*****************************************************************************/


int main ()
{
	std::vector< Vehicle * > vehicles;
	vehicles.push_back( new Bus( 200, 3000, 20 ) );
	vehicles.push_back( new Truck( 500, 12000, 8000 ) );

	std::cout << "Total maximum weight is: " << getTotalMaxWeight( vehicles ) << std::endl;
}


/*****************************************************************************/
