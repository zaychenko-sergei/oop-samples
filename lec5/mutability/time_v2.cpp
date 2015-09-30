// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "time_v2.hpp"

#include <stdexcept>

/*****************************************************************************/


Time::Time ( int _hours, int _minutes )
	:	m_hours( _hours ), m_minutes( _minutes )
{
	if ( ! IsValid() )
		throw std::logic_error( "Error: time is not valid!" );
}


/*****************************************************************************/


bool Time::IsValid () const
{
	if ( m_hours < 0 || m_hours > 23 )
		return false;

	return m_minutes >= 0 && m_minutes <= 59;
}


/*****************************************************************************/


const char * Time::ToString () const
{
	sprintf( m_tempBuf, "%d:%d", m_hours, m_minutes );
	return m_tempBuf;
}


/*****************************************************************************/
