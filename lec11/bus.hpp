// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _BUS_HPP_
#define _BUS_HPP_

/*****************************************************************************/

#include "vehicle.hpp"

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
	:	Vehicle( _engineHorsePower, _weight )
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

#endif // _BUS_HPP_
