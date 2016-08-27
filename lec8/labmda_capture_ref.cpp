#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>

int main ()
{
	typedef std::map< std::string, double > Prices;
	Prices prices;
	prices[ "Apple" ] = 9.50;
	prices[ "Orange" ] = 8.30;
	prices[ "Banana" ] = 2.20;

	typedef std::map< std::string, double > Order;
	Order myOrder;

	myOrder[ "Apple" ] = 2.5;
	myOrder[ "Orange" ] = 1.3;
	myOrder[ "Banana" ] = 0.6;

	double orderTotalCost =
		std::accumulate(
			myOrder.begin(), myOrder.end(),
			0.0,
			[ &prices ] ( double total, Order::value_type vt )
	        {
                return total + vt.second * prices[ vt.first ];
            }
	);

	std::cout << "Order totally takes: " << orderTotalCost << std::endl;
}
