// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "stack.hpp"

#include <string>
#include <cassert>

/*****************************************************************************/


int main ()
{
	Stack< int > s1;
	s1.push( 5 );
	assert( !s1.isEmpty() && s1.top() == 5 );

	Stack< double > s2;
	s2.push( 2.5 );
	assert( !s2.isEmpty() && s2.top() == 2.5 );

	Stack< std::string > s3;
	s3.push( "Hello" );
	assert( !s3.isEmpty() && s3.top() == "Hello" );

	Stack< Stack< int > > s4;
	s4.push( Stack< int >() );
	s4.top().push( 5 );
	assert( !s4.isEmpty() && !s4.top().isEmpty() && s4.top().top() == 5 );
}


/*****************************************************************************/

