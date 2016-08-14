#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

template< typename T >
void print_value ( const T & _value )
{
	std::cout << _value << ' ';
}

int main ()
{
	int arr[ 10 ] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	std::for_each( arr, arr + 10, &print_value< int > );
	std::cout << std::endl;

	std::vector< std::string > vs;
	vs.push_back( "Hello" );
	vs.push_back( "future" );
	vs.push_back( "C++" );
	vs.push_back( "programmer!" );

	std::for_each( vs.begin(), vs.end(), &print_value< std::string > );
	std::cout << std::endl;
}
