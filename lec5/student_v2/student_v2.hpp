// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _STUDENT_V2_HPP_
#define _STUDENT_V2_HPP_

/*****************************************************************************/


class Student
{

/*-----------------------------------------------------------------*/

	const char * m_LastName;
	const int m_Mark;

/*-----------------------------------------------------------------*/

	Student ( const char * _lastName, int _mark );

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	static Student * Make ( const char * _lastName, int _mark );

	const char * GetLastName () const;

	int GetMark () const;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline const char *
Student::GetLastName () const
{
	return m_LastName;
}


/*****************************************************************************/


inline int
Student::GetMark () const
{
	return m_Mark;
}


/*****************************************************************************/

#endif // _STUDENT_V2_HPP_