// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "queue.hpp"

#include <cassert>

/*****************************************************************************/


int main ()
{
	Queue< int > q1;
	q1.push( 5 );
	assert( ! q1.empty() && ( q1.top() == 5 ) );
	q1.pop();
	assert( q1.empty() );

	Queue< int, Deque > q2;
	q2.push( 5 );
	assert( ! q2.empty() && ( q2.top() == 5 ) );
	q2.pop();
	assert( q2.empty() );
}


/*****************************************************************************/
