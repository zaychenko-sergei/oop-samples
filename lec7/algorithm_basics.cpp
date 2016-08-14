#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

int main ()
{
	std::vector< int > v;

	std::copy(
		std::istream_iterator< int >( std::cin ),
		std::istream_iterator< int >(),
		std::back_inserter( v )
	);

	auto it = std::find( v.begin(), v.end(), 17 );
	if ( it != v.end() )
		std::cout << "Value 17 was met at position : " << ( it - v.begin() ) << std::endl;
	else
		std::cout << "Value 17 was not found" << std::endl;
}