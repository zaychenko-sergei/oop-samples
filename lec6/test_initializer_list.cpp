// (C) 2013-2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "initializer_list.hpp"

#include <string>
#include <iostream>

/*****************************************************************************/


template< typename L >
void printList ( L _l )
{
	std::cout << "List(" << _l.size() << "): ";

	for ( L::value_type y : _l )
		std::cout << y << ' ';

	std::cout << std::endl;
}


/*****************************************************************************/


int main ()
{
	int data1[] = { 1, 2, 3, 4, 5 };
	int size1 = sizeof ( data1 ) / sizeof( int );

	double data2[] = { 1.0, 2.0, 3.0, 4.0 };
	int size2 = sizeof( data2 ) / sizeof( double );

	std::string data3[] = { "A", "B", "C" };
	int size3 = sizeof( data3 ) / sizeof( std::string );

	InitializerList< int > list1( data1, data1 + size1  );
	InitializerList< double > list2( data2, data2 + size2 );
	InitializerList< std::string > list3( data3, data3 + size3 );

	printList( list1 );
	printList( list2 );
	printList( list3 );
}


/*****************************************************************************/
