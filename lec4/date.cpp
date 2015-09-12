// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "date.hpp"

#include <ctime>
#include <cassert>
#include <cstdio>
#include <stdexcept>

/*****************************************************************************/


Date::Date ()
{
	time_t currentTime = time( nullptr );

	tm* currentTM = gmtime( &currentTime );

	m_Year = currentTM->tm_year + 1900;
	m_Month = currentTM->tm_mon + 1;
	m_Day = currentTM->tm_mday;

	if ( ! IsValid() )
		throw std::logic_error( "Error: date is not valid!" );
}


/*****************************************************************************/


Date::Date ( int _year, int _month, int _day )
	:	m_Year( _year ), m_Month( _month ), m_Day( _day )
{
	if ( ! IsValid() )
		throw std::logic_error( "Error: date is not valid!" );
}


/*****************************************************************************/


Date::Date ( const char * _yyyyMMDD, char _sep )
{
	char sep1, sep2;
	int nMatched = sscanf( _yyyyMMDD, "%d%c%d%c%d", & m_Year, & sep1, & m_Month, & sep2, & m_Day );
	if ( nMatched != 5 || sep1 != _sep || sep2 != _sep )
		throw std::logic_error( "Error: date format is incorrect!" );

	if ( !IsValid() )
		throw std::logic_error( "Error: date is not valid!" );
}


/*****************************************************************************/


bool Date::IsValid () const
{
	if ( m_Year == 0 )
		return false;

	if ( m_Month < 1 || m_Month > 12 )
		return false;

	if ( m_Day < 1 )
		return false;

	else if ( m_Month == 2 && IsLeapYear() )
		return m_Day <= 29;

	else
	{
		static const int s_daysInMonth[] = {
			31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
		};

		return m_Day <= s_daysInMonth[ m_Month - 1 ];
	}
}


/*****************************************************************************/


bool Date::IsLeapYear () const
{
	if ( m_Year % 4 != 0 )
		return false;

	else if ( m_Year % 100 == 0 )
		return ( m_Year % 400 == 0 );

	return true;
}


/*****************************************************************************/


bool Date::operator == ( Date d ) const
{
	return m_Year == d.GetYear()   && 
           m_Month == d.GetMonth() &&
 		   m_Day == d.GetDay();
}


/*****************************************************************************/


bool Date::operator != ( Date d ) const
{
	return !( *this == d );
}


/*****************************************************************************/


bool Date::operator < ( Date d ) const
{
	if ( m_Year < d.GetYear() )
		return true;

	else if ( m_Year == d.GetYear() )
	{
		if ( m_Month < d.GetMonth() )
			return true;

		else if ( m_Month == d.GetMonth() )
			return m_Day < d.GetDay();
	}

	return false;
}


/*****************************************************************************/


bool Date::operator > ( Date d ) const
{
	return d < *this;
}


/*****************************************************************************/


bool Date::operator <= ( Date d ) const
{
	return ( *this < d ) || ( *this == d );
}


/*****************************************************************************/


bool Date::operator >= ( Date d ) const
{
	return ( d < *this ) || ( *this == d );
}


/*****************************************************************************/


std::ostream & operator << ( std::ostream & o, Date d )
{
	o << d.GetYear() << '/' << d.GetMonth() << '/' << d.GetDay();
	return o;
}


/*****************************************************************************/


std::istream & operator >> ( std::istream & i, Date & d )
{
	char buf[ 100 ];
	i >> buf;

	d = Date( buf );
	return i;
}


/*****************************************************************************/
