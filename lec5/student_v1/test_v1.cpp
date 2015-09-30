// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "student_v1.hpp"
#include <iostream>

/*****************************************************************************/


int main ()
{
	Student s1( "Ivanov", 75 );
	Student s2( "Petrov", 80 );
	Student s3( "Sidorov", 60 );

	std::cout << "Maximum mark among students: "
		<< Student::GetMaxMark()
		<< std::endl;

	s1.Dump();
	s2.Dump();
	s3.Dump();
}


/*****************************************************************************/
