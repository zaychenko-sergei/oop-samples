// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "stack_fixed_array.hpp"

#include <string>
#include <cassert>

/*****************************************************************************/


int main ()
{
	Stack< int > s{ 1.5, 2.5, 3.5 };
	assert( ! s.isFull() && s.top() == 3 );

	Stack< double > s1;
	s1.push( 2.5 );

	Stack< int > s2 = s1;
	assert( !s2.isEmpty() && s2.top() == 2 );

	Stack< const char * > s3;
	s3.push( "Hello" );

	Stack< std::string > s4;
	s4 = s3;
	assert( ! s4.isEmpty() && s4.top() == "Hello" );
}


/*****************************************************************************/
