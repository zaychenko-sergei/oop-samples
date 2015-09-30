// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _TIME_V4_HPP_
#define _TIME_V4_HPP_

/*****************************************************************************/


class Time
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Time ( int _hours, int _minutes );

	Time ( const Time & t );
	Time & operator = ( const Time & t );

	~Time ();

	int GetHours () const;
	int GetMinutes () const;

	void NextMinute ();

	const char * ToString () const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	bool IsValid () const;

/*-----------------------------------------------------------------*/

	int m_hours, m_minutes;

	struct StringRepr
	{
		char m_tempBuf[ 6 ];
		bool m_isUpToDate = false;

	} * m_pStringRepr;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline int Time::GetHours () const
{
	return m_hours;
}


/*****************************************************************************/


inline int Time::GetMinutes () const
{
	return m_minutes;
}


/*****************************************************************************/

#endif //  _TIME_V4_HPP_
