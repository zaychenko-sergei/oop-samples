// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "student_v1.hpp"

/*****************************************************************************/

int Student::ms_MaxMark;

std::fstream Student::ms_DumpFile;


/*****************************************************************************/


Student::Student ( const char * _lastName, int _mark )
	:	m_LastName( _lastName ), m_Mark( _mark )
{
	if ( m_Mark > ms_MaxMark )
		ms_MaxMark = m_Mark;
}



/*****************************************************************************/


void Student::Dump ()
{
	if ( ! ms_DumpFile.is_open() )
		ms_DumpFile.open( "students.txt", std::ios_base::out );

	ms_DumpFile << "Student " << m_LastName << " - " << m_Mark << std::endl;
}


/*****************************************************************************/
