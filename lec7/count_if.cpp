#include <iostream>
#include <vector>
#include <algorithm>

bool dividesOnTwo ( int x )
{
	return x % 2 == 0;
}

int main ()
{
	std::vector< int > v;
	for ( int i = 0; i < 10; i++ )
		v.push_back( i );

	int nOdd = std::count_if( v.begin(), v.end(), &dividesOnTwo );
	std::cout << "Number of elements that divide on 2 is: " << nOdd << std::endl;
}