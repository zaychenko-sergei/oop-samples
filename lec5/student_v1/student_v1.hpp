// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _STUDENT_V1_HPP_
#define _STUDENT_V1_HPP_

/*****************************************************************************/

#include <fstream>

/*****************************************************************************/


class Student
{

/*-----------------------------------------------------------------*/

	const char * m_LastName;
	const int m_Mark;
	
/*-----------------------------------------------------------------*/

	static int ms_MaxMark;

	static std::fstream ms_DumpFile;

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Student ( const char * _lastName, int _mark );

	const char * GetLastName () const;

	int GetMark () const;
	
	void Dump ();

	static int GetMaxMark ();

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


inline int Student::GetMaxMark ()
{
	return ms_MaxMark;
}


/*****************************************************************************/

#endif // _STUDENT_V1_HPP_