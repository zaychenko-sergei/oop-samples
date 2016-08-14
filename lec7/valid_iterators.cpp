#include <vector>
#include <iostream>

int main ()
{
	std::vector< int > v{ 1, 2, 2, 3, 4, 5 };
	auto it = v.end();
	do
	{
		-- it;
		if ( ( *it % 2 ) == 0 )
		{
			auto itTemp = it;
			--itTemp;
			v.erase( it );
			it = itTemp;
			++ it;
		}

	} while ( it != v.begin() );

	for ( int x : v )
		std::cout << x << ' ';

	std::cout << std::endl;
}