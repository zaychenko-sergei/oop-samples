// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "time_v4.hpp"

#include <stdexcept>

/*****************************************************************************/


Time::Time ( int _hours, int _minutes )
	:	m_hours( _hours ), m_minutes( _minutes ), 
		m_pStringRepr( new StringRepr() )
{
	if ( ! IsValid() )
		throw std::logic_error( "Error: time is not valid!" );
}


/*****************************************************************************/


Time::Time ( const Time & t )
	:	m_hours( t.m_hours ), m_minutes( t.m_minutes ),
		m_pStringRepr( new StringRepr() )
{}


/*****************************************************************************/


Time & Time::operator = ( const Time & t )
{
	if ( this == & t )
		return * this;

	m_hours = t.m_hours;
	m_minutes = t.m_minutes;

	m_pStringRepr->m_isUpToDate = false;

	return * this;
}


/*****************************************************************************/


Time::~Time ()
{
	delete m_pStringRepr;
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

	m_pStringRepr->m_isUpToDate = false;
}



/*****************************************************************************/


const char * Time::ToString () const
{
	if ( ! m_pStringRepr->m_isUpToDate )
	{
		sprintf( m_pStringRepr->m_tempBuf, "%d:%d", m_hours, m_minutes );
		m_pStringRepr->m_isUpToDate = true;
	}
	return m_pStringRepr->m_tempBuf;
}


/*****************************************************************************/
