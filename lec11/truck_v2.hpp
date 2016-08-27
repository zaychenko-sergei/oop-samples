// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _TRUCK_V2_HPP_
#define _TRUCK_V2_HPP_

/*****************************************************************************/

#include "vehicle_v2.hpp"

/*****************************************************************************/


class Truck
	:    public Vehicle
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Truck ( float _engineHorsePower, float _weight, float _maxCargoWeight );

	float getMaxCargoWeight () const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	const float m_maxCargoWeight;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline
Truck::Truck ( float _engineHorsePower, float _weight, float _maxCargoWeight )
	:	Vehicle( Type::Truck, _engineHorsePower, _weight )
	,	m_maxCargoWeight ( _maxCargoWeight )
{
}


/*****************************************************************************/


inline float
Truck::getMaxCargoWeight () const
{
	return m_maxCargoWeight;
}


/*****************************************************************************/

#endif // _TRUCK_V2_HPP_
