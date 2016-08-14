#include <algorithm>
#include <iostream>

template< typename T >
void print_value ( const T & _value )
{
	std::cout << _value << ' ';
}

int main ()
{
	int arr[ 10 ] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	std::cout << "Original array: ";
	std::for_each( arr, arr + 10, &print_value< int > );
	std::cout << std::endl;

	int arrCopy[ 10 ];
	std::rotate_copy( arr, arr + 5, arr + 10, arrCopy );

	std::cout << "Original array after copy transformation: ";
	std::for_each( arr, arr + 10, &print_value< int > );
	std::cout << std::endl;

	std::cout << "Copy array: ";
	std::for_each( arrCopy, arrCopy + 10, &print_value< int > );
	std::cout << std::endl;

	std::rotate( arr, arr + 5, arr + 10 );

	std::cout << "Original array after in-place transformation: ";
	std::for_each( arr, arr + 10, &print_value< int > );
	std::cout << std::endl;
}