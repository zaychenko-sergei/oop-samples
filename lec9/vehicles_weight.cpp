// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "bus_v2.hpp"
#include "truck_v2.hpp"

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

        switch ( pVehicle->getType() )
        {
            case Vehicle::Type::Truck:
                {
                     const Truck & t = ( const Truck & )( * pVehicle );
                     totalMaxWeight += t.getMaxCargoWeight();
                }
                break;

            case Vehicle::Type::Bus:
                {
                    const Bus & b = ( const Bus & ) ( * pVehicle );

                    const float HUMAN_WEIGHT = 62.0f;
                    totalMaxWeight += b.getPassengerSeatsCount() * HUMAN_WEIGHT;
                }
                break;

            default:
                assert( ! "Unexpected type of vehicle" );
        }        
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
