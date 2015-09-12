// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _DATE_HPP_
#define _DATE_HPP_

/*****************************************************************************/

#include <iostream>

/*****************************************************************************/


class Date
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Date ();
	Date ( int _year, int _month, int _day );
	Date ( const char* _yyyyMMDD, char _sep = '/' );

	int GetYear () const;
	int GetMonth () const;
	int GetDay () const;

	bool IsLeapYear () const;

	void Print ( char _sep = '/' );

	bool operator == ( Date d ) const;
	bool operator != ( Date d ) const;
	bool operator < ( Date d ) const;
	bool operator <= ( Date d ) const;
	bool operator > ( Date d ) const;
	bool operator >= ( Date d ) const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	bool IsValid () const;

/*-----------------------------------------------------------------*/

	int m_Year, m_Month, m_Day;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline int Date::GetYear () const
{
	return m_Year;
}


/*****************************************************************************/


inline int Date::GetMonth () const
{
	return m_Month;
}


/*****************************************************************************/


inline int Date::GetDay () const
{
	return m_Day;
}


/*****************************************************************************/

std::ostream & operator << ( std::ostream & o, Date d );

std::istream & operator >> ( std::istream & i, Date & d );

/*****************************************************************************/

#endif //  _DATE_HPP_
