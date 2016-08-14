#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

int main ()
{
	std::ifstream fInput( "cities.txt", std::ios_base::in );
	if ( ! fInput.is_open() )
	{
		std::cout << "Failed to open 'cities.txt'" << std::endl;
		return -1;
	}

	std::ofstream fOutput( "results.txt", std::ios_base::out );
	if ( !fOutput.is_open() )
	{
		std::cout << "Failed to open 'results.txt'" << std::endl;
		return -1;
	}

	std::vector< std::string > cities;

	std::copy( 
		std::istream_iterator< std::string >( fInput ), 
		std::istream_iterator< std::string >(),
		std::back_inserter( cities )
	);

	std::sort( cities.begin(), cities.end() );

	auto itUniqueEnd = std::unique( cities.begin(), cities.end() );

	std::copy(
		cities.begin(),
		itUniqueEnd,
		std::ostream_iterator< std::string >( fOutput, "\n" )
	);
}
