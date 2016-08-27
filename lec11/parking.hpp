// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _PARKING_HPP_
#define _PARKING_HPP_

/*****************************************************************************/

#include <unordered_set>

/*****************************************************************************/

class Vehicle;

/*****************************************************************************/


class Parking
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Parking ( int _nPlaces );

	int getNumTotalPlaces () const;

	int getNumFreePlaces () const;

	int getNumUsedPlaces () const;

	void park ( const Vehicle & _v );

	void leave ( const Vehicle & _v );

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	const int m_nPlaces;

	std::unordered_set< const Vehicle * > m_parkedVehicles;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline
int Parking::getNumTotalPlaces () const
{
	return m_nPlaces;
}


/*****************************************************************************/


inline 
int Parking::getNumUsedPlaces () const
{
	return m_parkedVehicles.size();
}


/*****************************************************************************/


inline
int
Parking::getNumFreePlaces () const
{
	return getNumTotalPlaces() - getNumUsedPlaces();
}


/*****************************************************************************/

#endif // _PARKING_HPP_
