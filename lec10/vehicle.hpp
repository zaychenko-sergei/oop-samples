// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _VEHICLE_HPP_
#define _VEHICLE_HPP_

/*****************************************************************************/

#include "engine.hpp"

/*****************************************************************************/


class Vehicle
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	const Engine & getEngine () const;

	float getWeight () const;

	virtual float getMaxExtraWeight () const = 0;

/*-----------------------------------------------------------------*/

protected:

/*-----------------------------------------------------------------*/

	Vehicle ( float _engineHorsePower, float _weight );

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	Engine m_engine;

	const float m_weight;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline
Vehicle::Vehicle ( float _engineHorsePower, float _weight )
	:	m_engine( _engineHorsePower )
	,	m_weight( _weight )
{
}


/*****************************************************************************/


inline
const Engine &
Vehicle::getEngine () const
{
	return m_engine;
}


/*****************************************************************************/


inline float
Vehicle::getWeight () const
{
	return m_weight;
}


/*****************************************************************************/

#endif //  _VEHICLE_HPP_
