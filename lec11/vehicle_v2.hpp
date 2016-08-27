// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _VEHICLE_V2_HPP_
#define _VEHICLE_V2_HPP_

/*****************************************************************************/

#include "engine.hpp"

/*****************************************************************************/


class Vehicle
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	enum class Type { Bus, Truck };

/*-----------------------------------------------------------------*/

	Type getType () const;

	const Engine & getEngine () const;

	float getWeight () const;

/*-----------------------------------------------------------------*/

protected:

/*-----------------------------------------------------------------*/

	Vehicle ( Type _type, float _engineHorsePower, float _weight );

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	const Type m_type;

	Engine m_engine;

	const float m_weight;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline
Vehicle::Vehicle ( Type _type, float _engineHorsePower, float _weight )
	:	m_type( _type )
	,	m_engine( _engineHorsePower )
	,	m_weight( _weight )
{
}


/*****************************************************************************/


inline
Vehicle::Type
Vehicle::getType () const
{
	return m_type;
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

#endif //  _VEHICLE_V2_HPP_
