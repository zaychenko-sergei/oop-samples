// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "time_v3.hpp"

#include <stdexcept>

/*****************************************************************************/


Time::Time ( int _hours, int _minutes )
	:	m_hours( _hours ), m_minutes( _minutes ), 
        m_bufferUpToDate( false )
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


void Time::NextMinute ()
{
	if ( m_minutes == 59 )
	{
		m_minutes = 0;
		if ( m_hours == 23 )
			m_hours = 0;
		else
			++m_hours;
	}
	else
		++m_minutes;

	m_bufferUpToDate = false;
}



/*****************************************************************************/


const char * Time::ToString () const
{
	if ( ! m_bufferUpToDate )
	{
		sprintf( m_tempBuf, "%d:%d", m_hours, m_minutes );
		m_bufferUpToDate = true;
	}
	return m_tempBuf;
}


/*****************************************************************************/
