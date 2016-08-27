// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _BUS_V2_HPP_
#define _BUS_V2_HPP_

/*****************************************************************************/

#include "vehicle_v2.hpp"

/*****************************************************************************/


class Bus
	:	public Vehicle
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Bus ( float _engineHorsePower, float _weight, int _nPassengerSeats );

	int getPassengerSeatsCount() const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	const int m_nPassengerSeats;

/*-----------------------------------------------------------------*/

};

//************************************************************************


inline
Bus::Bus ( float _engineHorsePower, float _weight, int _nPassengerSeats )
	:	Vehicle( Type::Bus, _engineHorsePower, _weight )
	,	m_nPassengerSeats( _nPassengerSeats )
{
}


/*****************************************************************************/


inline int
Bus::getPassengerSeatsCount () const
{
	return m_nPassengerSeats;
}


/*****************************************************************************/

#endif // _BUS_V2_HPP_
