// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "student_v2.hpp"

#include <cassert>
#include <stdexcept>

/*****************************************************************************/


int main ()
{
	Student * pStudent = Student::Make( "Ivanov", 75 );
	delete pStudent;

	try
	{
		pStudent = Student::Make( "Petrov", 101 );
		assert( ! "Exception must have been thrown!" );
	}
	catch ( std::exception & )
	{
	}

	try
	{
		pStudent = Student::Make( "Sidorov", 0 );
		assert( !"Exception must have been thrown!" );
	}
	catch ( std::exception & )
	{
	}
}


/*****************************************************************************/
