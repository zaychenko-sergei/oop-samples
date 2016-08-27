#include <vector>
#include <set>
#include <unordered_set>
#include <iostream>

int main ()
{
	std::vector< int > v( { 17, 2, 13, 15, 2, 11, 13, 6, 10, 2 } );

	std::set< int > s1( v.begin(), v.end() );
	for ( int x : s1 )
		std::cout << x << ' ';

	std::cout << std::endl;

	std::unordered_set< int > s2( v.begin(), v.end() );
	for ( int x : s2 )
		std::cout << x << ' ';

	std::cout << std::endl;
}
