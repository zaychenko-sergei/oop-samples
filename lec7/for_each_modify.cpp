#include <algorithm>
#include <iostream>

template< typename T >
void print_value ( const T & _value )
{
	std::cout << _value << ' ';
}

template< typename T >
void add_one ( T & _ref )
{
	_ref += 1;
}

int main ()
{
	int arr[ 10 ] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	std::for_each( arr, arr + 10, &print_value< int > );
	std::cout << std::endl;

	std::for_each( arr, arr + 10, &add_one< int > );

	std::for_each( arr, arr + 10, &print_value< int > );
	std::cout << std::endl;
}