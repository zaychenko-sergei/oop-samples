// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _SCHOOLBUS_HPP_
#define _SCHOOLBUS_HPP_

/*****************************************************************************/

#include "bus.hpp"

#include <string>

/*****************************************************************************/


class SchoolBus
	:	public Bus
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	SchoolBus (
			float _engineHorsePower
		,	float _weight
		,	int _nPassengerSeats
		,	const std::string & _schoolName
	);

	const std::string & getSchoolName () const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	const std::string m_schoolName;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline
SchoolBus::SchoolBus (
		float _engineHorsePower
	,	float _weight
	,	int _nPassengerSeats
	,	const std::string & _schoolName
)
	:	Bus( _engineHorsePower, _weight, _nPassengerSeats )
	,	m_schoolName( _schoolName )
{
}


/*****************************************************************************/


inline
const std::string &
SchoolBus::getSchoolName () const
{
	return m_schoolName;
}


/*****************************************************************************/

#endif //  _SCHOOLBUS_HPP_