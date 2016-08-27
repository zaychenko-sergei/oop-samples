// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _FLIGHTJOURNAL_HPP_
#define _FLIGHTJOURNAL_HPP_

/*****************************************************************************/

#include "point3d.hpp"

/*****************************************************************************/

class Helicopter;

/*****************************************************************************/

class FlightJournal
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	FlightJournal ( const Helicopter & _helicopter, int _nMaxLocations );

	FlightJournal ( const FlightJournal & ) = delete;
	FlightJournal & operator = ( const FlightJournal & ) = delete;

	~FlightJournal ();

	const Helicopter & getHelicopter () const;

	int getMaxPositionsCount () const;

	int getPositionsCount () const;

	Point3D getPosition ( int _index ) const;

	void track ();

	double totalDistance () const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	const Helicopter & m_helicopter;

	const int m_nMaxPositions;
	Point3D * m_pPositions;

	int m_nUsedPositions;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


// ����� ������� � ���������� � �������� ���������
inline const Helicopter &
FlightJournal::getHelicopter () const
{
	return m_helicopter;
}


/*****************************************************************************/


// ����� ��� ���������� ������������� ���������� ����� ��� ��������
inline int
FlightJournal::getMaxPositionsCount () const
{
	return m_nMaxPositions;
}


/*****************************************************************************/


// ����� ��� ���������� ���������� ��� ��������������� �����
inline int
FlightJournal::getPositionsCount () const
{
	return m_nUsedPositions;
}


/*****************************************************************************/

#endif // _FLIGHTJOURNAL_HPP_
