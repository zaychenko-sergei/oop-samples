// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "student_v2.hpp"

#include <stdexcept>

/*****************************************************************************/


Student::Student ( const char * _lastName, int _mark )
	: m_LastName( _lastName ), m_Mark( _mark )
{
}


/*****************************************************************************/


Student * Student::Make ( const char * _lastName, int _mark )
{
	if ( _mark >= 1 && _mark <= 100 )
		return new Student( _lastName, _mark );

	else
		throw std::logic_error( "Invalid student data" );
}


/*****************************************************************************/

