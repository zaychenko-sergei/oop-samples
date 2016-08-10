// (C) 2013-2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "list.hpp"

#include <iostream>
#include <string>

/*****************************************************************************/

template class List< int >;
template class List< double >;
template class List< std::string >;


/*****************************************************************************/

template< typename T >
void printRange ( const List< T > & _l )
{
	std::cout << "List(" << _l.Size() << "): ";

	for ( const T & val : _l )
		std::cout << val << ' ';

	std::cout << std::endl;
}

/*****************************************************************************/

int main ()
{
	List< int > l1{ 1, 2, 3, 4, 5 };
	List< double > l2{ 1.0, 2.0, 3.0, 4.0 };
	List< std::string > l3{ "A", "B", "C" };

	printRange( l1 );
	printRange( l2 );
	printRange( l3 );

}

/*****************************************************************************/
