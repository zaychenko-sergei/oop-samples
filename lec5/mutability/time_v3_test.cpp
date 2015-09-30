// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "time_v3.hpp"
#include <iostream>

/*****************************************************************************/


int main ()
{
	Time t1( 17, 15 );
	Time t2( 23, 10 );
	std::cout << t1.ToString() << ' ' << t2.ToString() << std::endl;
	t2.NextMinute();
	std::cout << t2.ToString() << std::endl;
}


/*****************************************************************************/
