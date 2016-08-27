// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _TRUCK_HPP_
#define _TRUCK_HPP_

/*****************************************************************************/

#include "vehicle.hpp"

/*****************************************************************************/


class Truck
	:	public Vehicle
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Truck ( float _engineHorsePower, float _weight, float _maxCargoWeight );

	float getMaxCargoWeight () const;

	virtual float getMaxExtraWeight () const
	{
		return getMaxCargoWeight();
	}

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	const float m_maxCargoWeight;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline
Truck::Truck ( float _engineHorsePower, float _weight, float _maxCargoWeight )
	:	Vehicle( _engineHorsePower, _weight )
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

#endif // _TRUCK_HPP_
