#include <map>
#include <string>
#include <iostream>
#include <algorithm>

int main ()
{
	typedef std::map< std::string, double > Prices;
	Prices prices;
	prices[ "Apple" ] = 9.50;
	prices[ "Orange" ] = 8.30;
	prices[ "Banana" ] = 2.20;

	double maximumPriceLimit;
	std::cout << "Enter price limit: ";
	std::cin >> maximumPriceLimit;

	std::for_each(
		prices.begin(), prices.end(),
		[ maximumPriceLimit ] ( const Prices::value_type & v )
	    {
		    if ( v.second > maximumPriceLimit )
			    std::cout << "Item " << v.first << " is too expensive" << std::endl;
	    }
	);
}
